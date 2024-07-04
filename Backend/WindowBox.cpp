#include "WindowBox.h"
#include "editor/Inspector.h"
#include "HasMultiple.h"
#include "Conversion.h"

#include <iostream>
#include <type_traits>
using namespace System::Collections::Generic;
namespace Editor {
	void WindowBox::Update() {
		toolBar.Update();
		if (toolBar.inspector) {
			AddWindow<Inspector>();
		}
		if (toolBar.gameView) {
			AddWindow<GameView>();
		}
		List<EditorWindow^>^ windsToDel = gcnew List<EditorWindow^>(0);
		for each (EditorWindow ^ var in nonDockedWindows)
		{
			var->ProcGUI();
			if (!var->open) {
				windsToDel->Add(var);
			}
		}
		for each (EditorWindow ^ var in windsToDel) {
			nonDockedWindows->Remove(var);
		}
	}
	template<class T>
	void WindowBox::AddWindow(void) {
		static_assert(std::is_base_of<EditorWindow, T>::value, "This type cannot be used as a type argunemt in the functino EditorBox::WindowBox::WindowBox");
		if (!T::typeid->IsDefined(HasMultipleAttribute::typeid, false)) {
			bool valid = true;
			for each (EditorWindow ^ var in nonDockedWindows)
			{
				if (var->GetType() == T::typeid)
					valid = false;
			}
			for each (Editor::EditorWindow ^ var in dockedWindows)
			{
				if (var != nullptr)
					if (var->GetType() == T::typeid)
						valid = false;

			}
			if (valid) {
				nonDockedWindows->Add((Editor::EditorWindow^)System::Activator::CreateInstance(T::typeid));
			}
		}
		else
			nonDockedWindows->Add((Editor::EditorWindow^)System::Activator::CreateInstance(T::typeid));

	}
	WindowBox::WindowBox() {
		nonDockedWindows = gcnew System::Collections::Generic::List<EditorWindow^>(1);
	}
	WindowBox::~WindowBox() {
		delete nonDockedWindows;
	}
}
