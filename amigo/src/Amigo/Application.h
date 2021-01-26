#pragma once
#include "Core.h"

namespace Amigo {
    class AMIGO_API Application 
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };
    
    //To be defined in Client - Magicbox
    Application* CreateApplication();
}