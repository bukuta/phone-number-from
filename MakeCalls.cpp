#include "Logger.hpp"
#include <boost/algorithm/string.hpp>

#include "Call.hpp"
// #include "Post.hpp"
#include "RestApi.hpp"
#include "yaml-cpp/yaml.h"

#include <nlohmann/json.hpp>
using nlohmann::json;

 using namespace boost;
using namespace std;



int main(int argc, char *argv[]) {
  YAML::Node config = YAML::LoadFile("./config.yaml");
  string baseUrl=config["baseUrl"].as<string>();
  string path=config["path"].as<string>();
  Logger::warn("baseUrl:{}",baseUrl);
  Logger::warn("path:{}",path);
  RestApi<Call> api(baseUrl);

  YAML::Node targets = config["targets"];
  // cout<<targets<<endl;

  if(targets.IsSequence()){
    auto length = targets.size();
    for(auto i =0;i<length;i++){
      auto item = targets[i];
      Call call;
      call.name=item["name"].as<string>();
      string phone=item["phone"].as<string>();
      trim(phone);
      call.phone = phone;
      // cout<<i<<item<<endl;
      // cout<<i<<call<<endl;
      Logger::info("拨打:{}",call);
      api.createObject(path, call).subscribe([](string_t v) {
        Logger::warn("接口:{}",v);
      });
    }
  }
}
