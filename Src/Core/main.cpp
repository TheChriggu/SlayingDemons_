#include <memory>
#include "Application.h"
#include <regex>

int main() {

    auto app = std::make_shared<sd::Application>();
    auto result = app->setup ();

    if (!result) {
      std::cerr << "Error while setting up Application!" << std::endl;
        return EXIT_FAILURE;
    }

    while (app->run ())
    {
    }

    return EXIT_SUCCESS;
}