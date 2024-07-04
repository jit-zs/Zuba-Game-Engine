#pragma once
namespace Zuba {
	ref class AssemblyManager
	{
	public:
		static array<System::Reflection::Assembly^>^ GetAssemblies();
	};
}


