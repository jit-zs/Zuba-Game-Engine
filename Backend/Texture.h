#pragma once
#include <SFML/Graphics.hpp>
namespace Zuba {
	public ref class Texture : System::IDisposable
	{
	public:
	private:
		sf::Texture* texture;
	public:
		Texture(System::String^ texture);
		~Texture();
	private:
	};
}