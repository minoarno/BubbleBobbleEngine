#include <MidestinyEngine.h>

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{

	}

	~Sandbox()
	{

	}

	void Run() override
	{

	}
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}