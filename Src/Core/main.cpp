#include <iostream>
#include "Application.h"

int main() {

    sp<sd::Application> app = sp<sd::Application>(new sd::Application());
    app->Setup();

    while (app->Run())
    {
    }

    app->Shutdown();

    return 0;
}