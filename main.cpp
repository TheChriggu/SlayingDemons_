#include <iostream>
#include "Application.h"

int main() {

    Application* app = new Application();
    app->initialize();

    while (app->run())
    {
    }
    return 0;
}