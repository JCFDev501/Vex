#pragma once

#ifdef VEX_PLATFORM_WINDOWS

extern Vex::Application* Vex::CreateApplication();

int main(int argc, char** argv)
{
    printf("Vex Engine!");
    auto app = Vex::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
