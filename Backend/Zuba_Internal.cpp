#include "Zuba_Internal.h"
#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "editor/Inspector.h"
#include "editor/Toolbar.h"
#include "WindowBox.h"

#include "object library/Component.h"
VoidFunc onStart;
VoidFunc onUpdate;
VoidFunc* GetStartHandle(){
	return &onStart;
}
VoidFunc* GetUpdateHandle() {
	return &onUpdate;
}

sf::RenderWindow window;
int StartEngine() {
	window.create(sf::VideoMode(800, 600), "Zuba");

	ImGui::SFML::Init(window);
	//ImGui::GetIO().IniFilename = nullptr;

	sf::CircleShape cir = sf::CircleShape(200.0f, 100);
	sf::Clock deltaClock;
	bool open = true;
	onStart();
	Editor::Inspector::components = Zuba::Component::GetAllDerivedComponents();
	Editor::WindowBox box;
	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			ImGui::SFML::ProcessEvent(ev);
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
			default:
				break;
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		onUpdate();
		box.Update();

		window.clear();
		window.draw(cir);
		ImGui::SFML::Render(window);
		window.display();
	}
	return 0;
}

void GetScreenSize(int* x, int* y) {
	*x = window.getSize().x;
	*y = window.getSize().y;
}