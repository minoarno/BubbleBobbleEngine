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
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}