#include "AssemblyManager.h"
#include "Conversion.h"
#include <iostream>
using namespace System;
using namespace System::Reflection;
using namespace System::IO;
using namespace System::Collections::Generic;
namespace Zuba {
	array<System::Reflection::Assembly^>^ AssemblyManager::GetAssemblies() {
        array<System::String^>^ dlls = File::ReadAllLines(".dllsheet");
        List<Assembly^>^ assemblies = gcnew List<Assembly^>();
        String^ loc = Assembly::GetExecutingAssembly()->Location;
        loc = Path::GetDirectoryName(loc);
        for each(String^ dll in dlls)
        {
            String^ path = loc + L'\\' + dll;
            assemblies->Add(Assembly::LoadFile(path));
        }
        return assemblies->ToArray();
	}
}
