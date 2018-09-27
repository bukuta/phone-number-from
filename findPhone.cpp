#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Header {
  char version[4];
  uint32_t offset;
};

struct Record {
  uint32_t phone;
  uint32_t offset;
  uint8_t type;
};

struct Area {
  string province;
  string city;
  string zip;
  string areaCode;
};

int getFileLength(std::string& filepath) {
  std::ifstream in(filepath, std::ifstream::ate | std::ifstream::binary);
  return in.tellg();
}

std::ostream& operator<<(std::ostream& out, const Area& p) {
  out << "Area{province:\"" << p.province << "\", city:\"" << p.city
      << "\", zip:\"" << p.zip << "\""
      << ", areaCode:\"" << p.areaCode << "\""
      << "}";
  return out;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "usage:\n ./findPhone 13012312312\n";
    exit(-1);
  }
  short pieceLength = 9;
  string phoneNumber = string(argv[1]);

  string phoneDataFile = "./phone.dat";
  int fileLength = getFileLength(phoneDataFile);
  ifstream fin(phoneDataFile, ios::in | ios::binary);
  if (!fin) {
    cerr << "file open failed" << endl;
    exit(-1);
  }

  char buffHeaders[8];
  fin.read(buffHeaders, 8);
  Header* header = reinterpret_cast<Header*>(buffHeaders);

  int recordLength = (fileLength - header->offset) / pieceLength;

  int length = sizeof(char) * (header->offset - 8 + 1);
  char* buff = new char[length]();

  int iOffset = header->offset;
  fin.read(buff, iOffset - 8);

  int lastPos = 0;
  int nextPos = 0;
  int segLength = 0;

  int indexPos = iOffset;
  char* buffRecords = new char[recordLength * pieceLength]();
  fin.read(buffRecords, recordLength * pieceLength);

  uint32_t iPhone = stoi(phoneNumber.substr(0, 7));

  int start = 0;
  int end = recordLength;
  int middle;
  char(*piece)[9];
  Record* record;

  do {
    middle = (start + end) / 2;
    piece = (char(*)[9])(buffRecords + middle * pieceLength);
    record = reinterpret_cast<Record*>(piece);
    if (record->phone < iPhone) {
      start = middle;
    } else if (record->phone > iPhone) {
      end = middle;
    } else {
      break;
    }
  } while (true);

  char* section;
  section = (buff + (record->offset - 8));

  vector<string> r;
  boost::split(r, section, [](char c) { return c == '|'; });
  Area area = {.province = r[0], .city = r[1], .zip = r[2], .areaCode = r[3]};
  cout << "area:" << area << endl;

  return 0;
}