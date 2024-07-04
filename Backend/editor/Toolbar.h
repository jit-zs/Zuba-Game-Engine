#pragma once
#include <imgui.h>
#include "../EditorWindow.h"
namespace Editor {
	ref class Toolbar {
	public:
		bool hidden;
		bool inspector;
		bool gameView;
		bool preferences;
	private:
	public:
		void Update();
	private:
	};
}
