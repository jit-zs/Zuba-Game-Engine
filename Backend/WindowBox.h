#pragma once
#include "EditorWindow.h"
#include "editor/Toolbar.h"
#include "GameView.h"

#include <string>
#include <string.h>

namespace Editor {
	ref class WindowBox {
	internal:
		array<Editor::EditorWindow^, 2>^ dockedWindows = gcnew array<Editor::EditorWindow^, 2>(4, 4);

		System::Collections::Generic::List<Editor::EditorWindow^>^ nonDockedWindows;

		Editor::Toolbar toolBar;

		void Update();
		template<class T>
		void AddWindow(void);
		WindowBox();
		~WindowBox();
	};
}
