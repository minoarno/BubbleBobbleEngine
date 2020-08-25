#include "MiniginPCH.h"
#include "InputManager.h"
#include "Tilemap.h"
#include "Core.h"
#include "Command.h"
#include <Xinput.h>

bool MidestinyEngine::InputManager::ProcessInput()
{
	//DWORD state;
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	IsPressed(ControllerButton{ m_CurrentState.Gamepad.wButtons });

	m_DidInputGet = false;
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
	{
		if (e.type == SDL_QUIT) 
		{
			ME_WARN("YOU SHOULDN'T BE HERE UNLESS YOU CLOSE");
			return false;
		}
		if (e.type == SDL_KEYDOWN) 
		{
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) 
		{
			#ifdef _DEBUG
			SceneManager::GetInstance().GetActiveScene()->GetTilemap()->TilemapBlockChanger(float(e.button.x),float(e.button.y));
			#endif
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{

		}
		for (auto& key : m_KeyboardCommands)
		{
			if (key.first == e.key.keysym.scancode)
			{
				key.second->Execute();
			}
		}

		if (m_KeyboardCommands.find(e.key.keysym.scancode) != m_KeyboardCommands.end())
		{
			m_KeyboardCommands.at(e.key.keysym.scancode)->Execute();
		}
	}

	return true;
}

bool MidestinyEngine::InputManager::IsPressed(ControllerButton button) const
{
	if (m_ControllerCommands.find(button) != m_ControllerCommands.end())
	{
		m_ControllerCommands.at(button)->Execute();
	}
	return false;
}

SDL_Event MidestinyEngine::InputManager::GetEvent()
{
	SDL_Event temp = m_Event;
	m_Event = SDL_Event{};
	return temp;
}

#pragma warning(push)
#pragma warning(disable:26812)
void MidestinyEngine::InputManager::AddInput(ControllerButton controllerButton, Command* command)
{
	m_ControllerCommands.emplace(controllerButton, command);
}

void MidestinyEngine::InputManager::AddInput(SDL_Scancode keySymbol, Command* command)
{
	m_KeyboardCommands.emplace(keySymbol, command);
}
#pragma warning(pop)

bool MidestinyEngine::InputManager::ProcessKeyboardInput()
{
	return false;
}
bool MidestinyEngine::InputManager::ProcessControllerInput()
{
	return false;
}
