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
		//for (auto& key : m_KeyboardCommands)
		//{
		//	if (key.first == e.key.keysym.scancode)
		//	{
		//		key.second->Execute();
		//	}
		//}

		if (m_KeyboardCommands.find(e.key.keysym.scancode) != m_KeyboardCommands.end())
		{
			m_KeyboardCommands.at(e.key.keysym.scancode)->Execute();
		}
	}

	//DWORD word[14]{ int(ControllerButton::DPadUp),int(ControllerButton::DPadDown),int(ControllerButton::DPadLeft),int(ControllerButton::DPadRight),int(ControllerButton::ButtonStart)
	//	,int(ControllerButton::ButtonBack),int(ControllerButton::LeftThumb),int(ControllerButton::RightThumb),int(ControllerButton::LeftShoulder),int(ControllerButton::RightShoulder),
	//		int(ControllerButton::ButtonA), int(ControllerButton::ButtonB),int(ControllerButton::ButtonX),int(ControllerButton::ButtonY) };
	//for (int i = 0; i < 14; i++)
	//{
	//	IsPressed(word);
	//}

	return true;
}

bool MidestinyEngine::InputManager::IsPressed(ControllerButton button) const
{
	if (m_ControllerCommands.find(button) != m_ControllerCommands.end())
	{
		m_ControllerCommands.at(button)->Execute();
	}
	

	/*switch (button)
	{
	case ControllerButton::ButtonA:
		ME_INFO("something");
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB: 
		ME_INFO("something");
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX: 
		ME_INFO("something");
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY: 
		ME_INFO("something");
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	default:
	}*/
	return false;
}

SDL_Event MidestinyEngine::InputManager::GetEvent()
{
	SDL_Event temp = m_Event;
	m_Event = SDL_Event{};
	return temp;
}

void MidestinyEngine::InputManager::AddControllerInput(ControllerButton controllerButton, Command* command)
{
	m_ControllerCommands.emplace(controllerButton, command);
}
#pragma warning(push)
#pragma warning(disable:26812)
void MidestinyEngine::InputManager::AddKeyboardInput(SDL_Scancode keySymbol, Command* command)
{
	m_KeyboardCommands.emplace(keySymbol, command);
}
#pragma warning(push)