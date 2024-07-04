#pragma once
#include <imgui.h>

namespace Zuba {
	value struct Vector2;
	public value struct Vector2
	{
		float x ;
		float y ;
		
		Vector2(float _x, float _y);
		static Vector2 operator+(Vector2 a, Vector2 b);
		Vector2 operator-(Vector2 other);
		Vector2 operator*(Vector2 other);
		Vector2 operator/(Vector2 other);
		Vector2 operator*(float f);
		Vector2 operator/(float f);

		float GetMagnitude();
		/// <summary>
		/// Uses undefined behaviour to get the x and y values from an unknown float Vector2 type. <br/> Note: This is UNSAFE. Use at your own risk.
		/// </summary>
		/// <param name="vec"></param>
		/// <returns></returns>
		static Vector2 FromForeignVector2(void* vec);
		Vector2 PointTowards(Vector2 end);
	};

}