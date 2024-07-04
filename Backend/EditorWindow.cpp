#include "EditorWindow.h"
#include "Conversion.h"
#include "editor/General.h"
#include <imgui.h>
using namespace Zuba;
namespace Editor {
	void EditorWindow::ProcGUI() {
		PreGUI();
		bool buf = open;
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(.25, .25, .25, 1));
		ImGui::Begin(CSStringToSTDString(name).c_str(), &buf); 
		open = buf;
		OnGUI();
		ImGui::End();
		ImGui::PopStyleColor();
	}
}