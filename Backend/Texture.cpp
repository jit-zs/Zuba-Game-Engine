#include "Texture.h"
#include "Conversion.h"
namespace Zuba {
	Texture::~Texture() {
		delete texture;
	}
	Texture::Texture(System::String^ texture) {
		this->texture = new sf::Texture();
		this->texture->loadFromFile(CSStringToSTDString(texture));
	}
}