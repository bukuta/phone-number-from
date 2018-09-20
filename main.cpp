#include "post.hpp"

#include "RestApi.hpp"

using namespace std;

int main(int argc, char* argv[]){
  RestApi<Post>api(U("http://jsonplaceholder.typicode.com/"));

  auto i=10;
  string path;
  path = "posts/"+to_string(i);
  api.getString(path).subscribe([](const string_t& v){
      cout << "got:"<< endl;
      cout << v<< endl;
  });
  api.getObject(path).subscribe([](const Post& v){
      cout << "got:"<< endl;
      cout << v<< endl;
  });

}
