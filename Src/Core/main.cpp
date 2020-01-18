#include <memory>
#include "Application.h"

int main() {

    Sp<sd::Application> app = std::make_shared<sd::Application>();
    auto result = app->setup ();

    if (!result) {
      std::cerr << "Error while setting up Application!" << std::endl;
        return 1;
    }

    while (app->run ())
    {
    }

  app->shutdown ();

    return 0;
}