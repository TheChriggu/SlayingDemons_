#include <iostream>
#include "Application.h"

int main() {

    sd::Application* app = new sd::Application();
    app->Setup();

    while (app->Run())
    {
    }

    return 0;
}