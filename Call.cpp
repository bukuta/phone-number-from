#include "Call.hpp"
using namespace std;

void to_json(json& j, const Call& p) {
  j = json{{"userName", p.name}, {"phoneNumber", p.phone}};
}

void from_json(const json& j, Call& p) {
  p.name = j.at("userName").get<string>();
  p.phone = j.at("phoneNumber").get<string>();
}

std::ostream& operator<<(std::ostream& out, const Call& p) {
  out << "Call{userName=" << p.name << ", phoneNumber=" << p.phone << "}";
  return out;
}
