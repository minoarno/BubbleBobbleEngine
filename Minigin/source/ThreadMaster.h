#pragma once
#include "Singleton.h"
#include <thread>
#include <vector>

namespace MidestinyEngine
{
	class ThreadMaster : public Singleton<ThreadMaster>
	{
	public:
		~ThreadMaster();

		void Update();

		void Invoke(std::function<void()> func, int intervalInMilliseconds, bool isLooping);

		void TerminateAllThreads();
	private:
		friend class Singleton<ThreadMaster>;
		ThreadMaster() = default;

		std::vector<std::thread> m_Threads;
	};
}