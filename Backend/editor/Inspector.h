#pragma once
#include "../EditorWindow.h"
#include "../HasMultiple.h"
namespace Editor {
	public ref  class Inspector sealed: EditorWindow{
	public:
		static array<System::Type^>^ components;
		array<System::Type^>^ comps;
	private:
		bool addComp;
	public:
		void OnGUI() override;
		inline Inspector()
		{
			name = "Inspector";
		}
	private:
		
	};
}