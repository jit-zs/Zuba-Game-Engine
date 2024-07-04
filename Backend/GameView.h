#pragma once
#include "EditorWindow.h"
namespace Editor {
	ref class GameView :public EditorWindow
	{
	internal:
		void PreGUI() override;
	protected:
		void OnGUI() override;
	public:
		GameView() {
			name = "Game View";

		}
	};
}