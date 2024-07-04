#pragma once 
#include <SFML/Graphics.hpp>
__declspec(dllexport) int StartEngine();

typedef void(*VoidFunc)();
__declspec(dllexport) VoidFunc* GetStartHandle();
__declspec(dllexport) VoidFunc* GetUpdateHandle();

void GetScreenSize(int* x, int* y);
extern sf::RenderWindow window;