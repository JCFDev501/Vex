#pragma once

#ifdef VEX_PLATFORM_WINDOWS

extern Vex::Application* Vex::CreateApplication();

int main(int argc, char** argv)
{
    int a = 5;

    Vex::Log::Init();
    VEX_CORE_WARN("Testing Logging");
    VEX_INFO("Hello! var={0}", a);
    
    auto app = Vex::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
