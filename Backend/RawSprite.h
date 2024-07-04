#pragma once
#include <SFML/Graphics.hpp>
namespace Zuba {
	namespace Internal {
		public ref class RawSprite : System::IDisposable {
		public:
		private:
			sf::Sprite* sprite;
			sf::Texture* texture;
		public:
			void Draw();
			RawSprite();
			~RawSprite();
		private:
		};
	}
}