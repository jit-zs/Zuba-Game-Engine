#pragma once
namespace Zuba
{
	public ref class Component
	{
    public :
		static array<System::Type^>^ GetAllDerivedComponents();
	};
}