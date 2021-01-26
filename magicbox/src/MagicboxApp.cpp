#include "Amigo.h"

class Magicbox : public Amigo::Application
{
public:
	Magicbox()
	{

	}
	~Magicbox()
	{

	}

};

Amigo::Application* Amigo::CreateApplication()
{
	return new Magicbox();
}