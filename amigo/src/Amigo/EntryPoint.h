#pragma once

#ifdef AMIGO_PLATFORM_WINDOWS

extern Amigo::Application* Amigo::CreateApplication();

int main(int argc, char** argv)
{
    Amigo::Log::Init();
    AMIGO_CORE_WARN("Initialized Log!");
    AMIGO_CLIENT_INFO("Hello I am Client!");

    auto app = Amigo::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif