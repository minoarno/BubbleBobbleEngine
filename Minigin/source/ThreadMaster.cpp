#include "MiniginPCH.h"
#include "ThreadMaster.h"

namespace MidestinyEngine
{
	ThreadMaster::~ThreadMaster()
	{
		TerminateAllThreads();
	}

	void ThreadMaster::Update()
	{
		for (int i = 0; i < m_Threads.size(); i++)
		{
			if ((*m_Threads[i]).joinable())
			{
				(*m_Threads[i]).join();
			}
		}
	}

	void Update()
	{

	}

	void ThreadMaster::Invoke(std::function<void()> func, int intervalInMilliseconds, bool isLooping)
	{
		std::thread([func, intervalInMilliseconds, isLooping]()
		{
			do
			{
				auto nextTimeFunctionCall = std::chrono::steady_clock::now() + std::chrono::milliseconds(intervalInMilliseconds);
				std::this_thread::sleep_until(nextTimeFunctionCall);
				func();
			} while (isLooping);
		}).detach();

		//_Threads.push_back(std::make_unique(&newThread));
	}

	void ThreadMaster::TerminateAllThreads()
	{
		for (int i = 0; i < m_Threads.size(); i++)
		{
			m_Threads[i]->join();
		}
	}
}