#pragma once

#ifdef VEX_PLATFORM_WINDOWS

extern Vex::Application* Vex::CreateApplication();

int main(int argc, char** argv)
{
    int a = 500;

    Vex::Log::Init();
    VEX_CORE_WARN("Testing Logging Vex");
    VEX_INFO("Hello! var={0}", a);
    
    auto app = Vex::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
