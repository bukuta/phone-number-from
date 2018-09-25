#ifndef Call_hpp
#define Call_hpp

#include <iostream>
#include <nlohmann/json.hpp>
using nlohmann::json;

#include "spdlog/fmt/ostr.h"

struct Call {
  std::string name;
  std::string phone;

  template <typename OStream>
  friend OStream& operator<<(OStream& out, const Call& c) {
    return out << "[Call name=" << c.name << ", phone" << c.phone << "]";
  }
};

void to_json(json& j, const Call& c);
void from_json(const json& j, Call& c);

std::ostream& operator<<(std::ostream& out, const Call& c);

#endif