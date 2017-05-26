#ifndef APP_HTTP_CONTROLLERS_DASHBOARD_CONTROLLER_H_
#define APP_HTTP_CONTROLLERS_DASHBOARD_CONTROLLER_H_
#include "controller.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
      class DashboardController : public Controller
      {
       public:
        DashboardController(cppcms::service &s);

        // virtual void main(std::string path);
        void index();
      };
    }
  }
}
#endif
