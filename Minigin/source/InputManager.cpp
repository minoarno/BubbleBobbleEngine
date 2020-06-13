#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


bool dae::InputManager::ProcessInput()
{
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	m_DidInputGet = false;
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
	{
		if (e.type == SDL_QUIT) 
		{
			return false;
		}
		if (e.type == SDL_KEYDOWN) 
		{
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) 
		{
			
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{

		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	switch (button)
	{
	case ControllerButton::ButtonA: 
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB: 
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX: 
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY: 
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	default: return false;
	}
}

SDL_Event dae::InputManager::GetEvent()
{
	SDL_Event temp = m_Event;
	m_Event = SDL_Event{};
	return temp;
}

