#include "GameView.h"
#include "../Zuba_Internal.h"
#include <SFML/Graphics.hpp>
using namespace Zuba;
namespace Editor {
	void GameView::PreGUI() {
		ImGui::SetNextWindowBgAlpha(0);
	}
	void GameView::OnGUI() {
		ImVec2 _pos = ImGui::GetWindowPos();
		Vector2 pos = Vector2::FromForeignVector2(&_pos);
		ImVec2 _size = ImGui::GetWindowSize();
 		Vector2 size = Vector2::FromForeignVector2(&_size);
		sf::Vector2u _winSize = window.getSize();
		Vector2 windowSize = Vector2(_winSize.x, _winSize.y);


		sf::View view = sf::View(sf::FloatRect(0, 0,200, 200));
		view.setViewport(sf::FloatRect(pos.x / windowSize.x, (pos.y / windowSize.y) + (20 / windowSize.y), size.x / windowSize.x, size.y / windowSize.y - (20 / windowSize.y)) );
		
		window.setView(view);
	}
}