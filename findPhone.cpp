#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

struct Header{
  char version[4];
  uint32_t offset;
};

struct Record{
  uint32_t phone;
  uint32_t offset;
  uint8_t type;
};

struct Area{
  string province;
  string city;
  string zip;
  string areaCode;
};

int getFileLength(std::string &filepath) {
  std::ifstream in(filepath, std::ifstream::ate | std::ifstream::binary);
  return in.tellg();
}



std::ostream& operator<<(std::ostream& out, const Area& p) {
  out << "Area{province:\"" << p.province << "\", city:\"" << p.city << "\", zip:\""
      << p.zip << "\""
      << ", areaCode:\"" << p.areaCode << "\""
      << "}";
  return out;
}

int main(int argc,char* argv[]){
  if (argc != 2) {
    cout<<"usage:\n ./findPhone 13012312312\n";
    exit(-1);
  }
  short pieceLength=9;
  string phoneNumber = string(argv[1]);

  string phoneDataFile = "./phone.dat";
  int fileLength = getFileLength(phoneDataFile);
  ifstream fin(phoneDataFile,ios::in|ios::binary);
  if(!fin){
    cerr<<"file open failed"<<endl;
    exit(-1);
  }
  

  char buffHeaders[8];
  fin.read(buffHeaders,8);
  Header * header = reinterpret_cast<Header *>(buffHeaders);

  int recordLength = (fileLength-header->offset)/pieceLength;

  int length = sizeof(char) * (header->offset - 8 + 1);
  char* buff = new char[length]();

  int iOffset = header->offset;
  fin.read(buff, iOffset - 8);

  int lastPos = 0;
  int nextPos =0;
  int segLength = 0;

  // vector<Area> areas;

  // while(nextPos<length){
  //   while(buff[nextPos++]!=0){
  //   }
  //   segLength = nextPos-lastPos-1;

  //   if (segLength == 0) {
  //     break;
  //   }
  //   // Logger::warn("seq.sub:{},{},{}",lastPos,nextPos,nextPos-lastPos-1);
  //   char* chars=new char[nextPos-lastPos]();

  //   memcpy(chars, buff + lastPos, nextPos - lastPos - 1);
  //   // Logger::warn("charss:{}", chars);
  //   string seg = string(chars);

  //   vector<string> r;
  //   boost::split(r, seg, [](char c) { return c == '|'; });
  //   // cout << "split:" << seg << r.size() << endl;

  //   Area area = {.province = r[0], .city = r[1], .zip = r[2], .areaCode = r[3]};
  //   cout << "seg:" << area << endl;

  //   areas.push_back(area);

  //   // string seg(buff,lastPos+1,nextPos-lastPos-1);
  //   // Logger::warn("seq:{}",seg);
  //   lastPos = nextPos;
  //   // string seg1 = string(buff[pos])
  //   // Logger::warn("segs:{}", buff);
  // }
  // Logger::error("size:{}", areas.size());

  int indexPos = iOffset;
  char* buffRecords = new char[recordLength*pieceLength]();
  fin.read(buffRecords,recordLength*pieceLength);
  // fin.seekg(iOffset);
  // fin.read(piece, pieceLength);

  // Record *record = reinterpret_cast<Record *>(piece);
  // Logger::warn("record:{},{},{}",record->phone,record->offset,record->type);


  uint32_t iPhone = stoi(phoneNumber.substr(0,7));
  // Logger::warn("iPhone:{}",iPhone);

  int start = 0;
  int end = recordLength;
  int middle;
  char (*piece)[9];
  // cout<<"&piece:"<<piece<<endl;

  Record *record;
  do{
    middle = (start + end) / 2;
    piece =(char (*)[9])(buffRecords+middle*pieceLength);
    record = reinterpret_cast<Record *>(piece);
    // cout<<"record:"<<record->phone<<endl;
    if(record->phone<iPhone){
      start = middle;
    }else if(record->phone>iPhone){
      end = middle;
    }else{
      break;
    }
  }while(true);

  char *section;
  section = (buff+(record->offset-8));
  // Logger::warn("section: {}", (uintptr_t)&section);
  // Logger::warn("section:{}", section);
  // Logger::warn("section: {}", buff);
  vector<string> r;
  boost::split(r, section, [](char c) { return c == '|'; });
  Area area = {.province = r[0], .city = r[1], .zip = r[2], .areaCode = r[3]};
  cout<<"area:"<<area<<endl;

  return 0;


  // char prefix[4];
  // memcpy(prefix,piece,4);
  // int segOffset = (piece[4]<<8)+piece[7];
  // char type = piece[8];

  // Logger::info("piece:segOffset:{},type:{}", segOffset,(int)piece[8]);
  // Logger::info("piece:{},{},{},{},{},{},{}", (int)prefix[0], (int)piece[1],
  //              (int)piece[2], (int)piece[3], (int)piece[4], (int)piece[5],
  //              (int)piece[6]);
  // Logger::info("piece:segOffset:{},type:{}", segOffset,type);

  // return 0;
  // int iPid = (int)getpid();
  // Logger::warn("pid:{}",iPid);
  // this_thread::sleep_for(chrono::seconds(15));
  // Logger::info("exit");

  // vector<string> segs;
  // boost::split(segs, buff, [](char c) { return c == '\0'; });
  // Logger::warn("segs:{}",segs.size());
}