#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include "UVCoord.h"

class Frame {
public:
	UVCoord uv[4];
	float duration;
	float keyframe;
};

#endif // !FRAME_H
