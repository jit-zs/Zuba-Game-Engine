#include "Zuba_Internal.h"
void Start() {
	
}
void Update() {
	
}
int main() {
	VoidFunc* start = GetStartHandle();
	VoidFunc* update = GetUpdateHandle();
	*start = Start;
	*update = Update;

	return StartEngine();
}
