#include <iostream>
#include "router.h"
#include "../../routes/web.h"
#include "../../routes/api.h"

#include <stdio.h>
#include <cppcms/http_request.h>

app::core::Router::Router(cppcms::service &s) : cppcms::application(s)
{
  attach(new routes::API(s),
    "api",
    "/api{1}",
    "/api((/?.*))",
    1);
  // Web Route must be set at last of Router Lists.
  attach(new routes::Web(s),
    "web",
    "/{1}",
    "/((/?.*))",
    1);
}

void app::core::Router::main(std::string path)
{
  try
  {
    cppcms::application::main(path);
  }
  catch(std::exception const &e)
  {
    std::cerr << "Failed: " << e.what() << std::endl;
    std::cerr << booster::trace(e) << std::endl;
  }
  // Write Logs
  printf("============== Connection Info ===============\n");
  printf("IP: %s\n", request().remote_host().c_str());
  printf("Path: %s\n", path.c_str());
}
