#pragma once
#include "imgui.h"
#include "ZMath.h"

namespace Editor
{
	public ref class EditorWindow abstract {
	public:
		System::String^ name;
		Zuba::Vector2 position;
		bool docked;
		bool open = true;
	private:
	internal:
		virtual void PreGUI(){}
	protected:
		virtual void OnGUI() abstract;
	internal:
		void ProcGUI();
	private:
	};
}