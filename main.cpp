#include "Logger.hpp"
#include "Post.hpp"
#include "RestApi.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  Logger::info("This is log");
  Logger::warn("This is log");
  Logger::error("This is log");
  Logger::debug("This is log");
  RestApi<Post> api(U("http://jsonplaceholder.typicode.com/"));

  auto i = 10;
  string path;
  path = "posts/" + to_string(i);
  string got;
  api.getString(path).subscribe([&got](const string_t &v) {
    got = v;
    cout << "got:" << endl;
    cout << v << endl;
  });
  //   Logger::warn(got);
  api.getObject(path).subscribe([](const Post &v) {
    //   Logger::warn("Post:[ title: \"{}\", body:\"{}\" ]",v.title,v.body);
    //   console->error("Post:{}", v);
    cout << "got:" << endl;
    cout << v << endl;
  });

  Post post;
  post.id = 1;
  post.userId = 101;
  post.title = U("test 人民");
  post.body = U("body 体");
  //   api.createObject(U("posts"),post).subscribe([](string_t v){
  //       cout <<"创建了:"<<endl;
  //       cout<< v << endl;
  //       });
}
