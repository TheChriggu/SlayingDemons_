#include <memory>
#include "Application.h"

int main() {

    Sp<sd::Application> app = std::make_shared<sd::Application>();
  app->setup ();

    while (app->run ())
    {
    }

  app->shutdown ();

    return 0;
}