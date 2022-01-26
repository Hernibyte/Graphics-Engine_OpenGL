#shader vertex
#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;

out vec3 ourColor;
out vec2 texCoord;

uniform mat4 model;

void main() {
	gl_Position = model * vec4(inPosition, 1.0);
	ourColor = inColor;
	texCoord = inTexCoord;
}

#shader fragment
#version 330 core

in vec3 ourColor;
in vec2 texCoord;

uniform int type;

uniform sampler2D ourTexture;

void main() {
	if (type == 0) {
		gl_FragColor = vec4(ourColor, 1.0);
	}
	else if (type == 1) {
		gl_FragColor = texture(ourTexture, texCoord) * vec4(ourColor, 1.0);
	}
}