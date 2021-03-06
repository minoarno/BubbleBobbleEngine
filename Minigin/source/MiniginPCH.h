#pragma once
#include <stdio.h>
#include <iostream> // std::cout
#include <type_traits>
#include <sstream> // stringstream
#include <memory> // smart pointers
#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>

#include <chrono>
#include <thread>

#include "Log.h"
#include "ColliderIncludes.h"
#include "GameTime.h"
#include "Vector2f.h"
#include "Structs.h"
#include "utils.h"

#pragma warning(push)
#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
#pragma warning(disable : 6385)
//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>

#include "SDL.h"
#include "SDL_opengl.h"
//#include <gl/GLU.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h> 

//#include "Saving.h"
#pragma warning(pop)

#include "Application.h"

#include "GameObject.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "BaseComponent.h"
#include "Scene.h"
#include "Renderer.h"
#include "Texture2D.h"