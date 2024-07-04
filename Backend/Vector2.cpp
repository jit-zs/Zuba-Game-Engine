#include "Vector2.h"
#include <math.h>
namespace Zuba {
	Vector2::Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}
	Vector2 Vector2::operator+(Vector2 a, Vector2 b) {
		return Vector2(a.x + b.x, a.y + b.y);
	}
	Vector2 Vector2::operator-(Vector2 other) {
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 Vector2::operator*(Vector2 other) {
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 Vector2::operator/(Vector2 other) {
		return Vector2(x / other.x, y / other.y);
	}
	Vector2 Vector2::operator*(float factor) {
		return Vector2(x * factor, y * factor);
	}
	Vector2 Vector2::operator/(float divisor) {
		return Vector2(x / divisor, y / divisor);
	}
	float Vector2::GetMagnitude() {
		return sqrtf(powf(x, 2) + powf(y, 2));
	}
	Vector2 Vector2::FromForeignVector2(void* vec) {
		float* f = (float*)vec;
		return Vector2(f[0], f[1]);
	}
	Vector2 Vector2::PointTowards(Vector2 end) {
		return end - *this;
	}
}