#include <MidestinyEngine.h>

class Sandbox final : public MidestinyEngine::Application
{
public:
	Sandbox()
		:Application()
	{
		ME_WARN("Works");
		glBegin(GL_LINE);
		glVertex2f(0.f, 1.f);
		glVertex2f(0.f, 5.f);
		glEnd();
	}

	~Sandbox() = default;
};

MidestinyEngine::Application* MidestinyEngine::CreateApplication()
{
	return new Sandbox{};
}