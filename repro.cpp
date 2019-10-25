#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/string/view_or_value.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

class ServerSetup
{
public:
  const static std::string &mongoUri();
private:
  static std::string MongoUri;
};

// Of course the real url would be different, not "my_server", but I
// can't share the company url with you
std::string ServerSetup::MongoUri = "mongodb://my_server/?ssl=true";

const std::string &ServerSetup::mongoUri()

{
  return MongoUri;
}
int main()

{

  try

  {

    mongocxx::instance instance{};

    mongocxx::uri uri = mongocxx::uri(ServerSetup::mongoUri());
    std::cout << uri.to_string() << std::endl;

  }

  catch (std::exception &ex)

  {
    std::cout << "std::excetpion caught: " << ex.what();
  } catch (...)

  {
    std::cout << "unknown excetpion caught";
  }
  return 0;
}
