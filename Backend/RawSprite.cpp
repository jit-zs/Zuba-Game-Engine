#include "RawSprite.h"
namespace Zuba {
	namespace Internal {
		RawSprite::RawSprite() {
			sprite = new sf::Sprite();
		}
		RawSprite::~RawSprite() {
			delete sprite;
		}
		void RawSprite::Draw() {
			if (texture) {

			}
		}
	}
}