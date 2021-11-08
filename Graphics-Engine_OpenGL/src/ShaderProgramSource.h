#ifndef SHADERPROGRAMSOURCE_H
#define SHADERPROGRAMSOURCE_H

#include "Export.h"
#include <iostream>
#include <string>

struct ENGINE_API ShaderProgramSource {
	std::string Vertex;
	std::string Fragment;
};

#endif // !SHADERPROGRAMSOURCE_H
