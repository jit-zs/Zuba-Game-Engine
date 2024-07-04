#pragma once
#include <atlstr.h>
#include <locale>
#include <codecvt>
#include <string>
namespace Zuba {
	 inline std::string CSStringToSTDString(System::String^ string) {
		using convert_type = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_type, wchar_t> converter;

		return converter.to_bytes(std::wstring(CString(string).GetString()));
	}
}