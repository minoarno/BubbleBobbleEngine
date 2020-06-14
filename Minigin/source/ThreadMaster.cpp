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
			ME_WARN(m_Threads[i].joinable());
			if (m_Threads[i].joinable())
			{
				m_Threads[i].detach();
			}
		}
	}

	void Update()
	{

	}

	void ThreadMaster::Invoke(std::function<void()> func, int intervalInMilliseconds, bool isLooping)
	{
		std::thread newThread = std::thread([func, intervalInMilliseconds, isLooping]()
		{
			do
			{
				auto nextTimeFunctionCall = std::chrono::steady_clock::now() + std::chrono::milliseconds(intervalInMilliseconds);
				std::this_thread::sleep_until(nextTimeFunctionCall);
				func();
			} while (isLooping);
		});

		m_Threads.push_back(std::move(newThread));
	}

	void ThreadMaster::TerminateAllThreads()
	{
		if (m_Threads.size() > 0)
		{
			m_Threads.clear();
		}
	}
}