#include "Inspector.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <atlstr.h>
#include <iostream>
#include <SFML/Window.hpp>

#include "../Conversion.h"
#include "General.h"

namespace Editor {
	void Inspector::OnGUI() {
		if (ImGui::Button("Add component", ImVec2(100, 25)))
			addComp = !addComp;
		if (addComp) {
			if (ImGui::BeginListBox("##", ImVec2(100, 200))) {
				for each (System::Type ^ t in components) {
					CString str(t->Name);
					bool filler;
					if (ImGui::Selectable(Zuba::CSStringToSTDString(t->Name).c_str(), &filler, 0, ImVec2(100, 20))) {
						std::cout << Zuba::CSStringToSTDString(t->Name) << std::endl;
					}
				}
				ImGui::EndListBox();
			}
		}

		if (ImGui::BeginCombo("Name", "None", ImGuiComboFlags_HeightLargest)) {
			ImVec2 vec = ImVec2(25, 25);
			ImGui::Button("Hi", vec);
			ImGui::EndCombo();
		}
		static bool openPopup;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			openPopup = !openPopup;
		

	}
}