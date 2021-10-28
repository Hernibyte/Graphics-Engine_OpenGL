#include "Program.h"

class Juego : public Program {
public:
	Juego() : Program(1280, 720, "Juego") {

	}

	void Awake() {};
	void Start() {};
	void LateUpdate() {};
	void Update() {};
	void FixedUpdate() {};
	void Sleep() {};
};

int main() {
	Juego juego;
	juego.Run();
	return 0;
}