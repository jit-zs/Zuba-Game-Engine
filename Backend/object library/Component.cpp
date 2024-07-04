#include "Component.h"
#include "../AssemblyManager.h"
using namespace System::Reflection;
using namespace System;
using namespace System::Collections::Generic;
namespace Zuba {
	array<System::Type^>^ Component::GetAllDerivedComponents() {
		array<Assembly^>^ assemblies = Zuba::AssemblyManager::GetAssemblies();
		List<Type^>^ result = gcnew List<Type^>;

		for each (Assembly ^ assembly in assemblies)
			for each (Type ^ type in assembly->GetTypes())
				if (type->IsSubclassOf(Component::typeid))
					result->Add(type);
		for each (Type ^ type in Assembly::GetExecutingAssembly()->GetTypes())
			if (type->IsSubclassOf(Component::typeid))
				result->Add(type);
		return result->ToArray();
	}
}