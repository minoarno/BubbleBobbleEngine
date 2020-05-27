#include <MidestinyEngine.h>

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	void Run()
	{

	}
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}