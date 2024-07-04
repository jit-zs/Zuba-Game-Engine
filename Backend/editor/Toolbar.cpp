#include "Toolbar.h"
#include "General.h"
#include "../Zuba_Internal.h"

#include <iostream>
namespace Editor {
	void Toolbar::Update() {
		inspector = false;
		gameView = false;
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("Edit")) {
				preferences = ImGui::MenuItem("Preferences");
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Windows")) {
				inspector = ImGui::MenuItem("Inspector");
				gameView = ImGui::MenuItem("Game View");
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}