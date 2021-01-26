#pragma once

#ifdef AMIGO_PLATFORM_WINDOWS

extern Amigo::Application* Amigo::CreateApplication();

int main(int argc, char** argv)
{
	printf("Amigo Engine\n");
	auto app = Amigo::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
