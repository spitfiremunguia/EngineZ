#pragma once
#include <GL/glew.h>
class Sprite
{
public:
	Sprite();
	~Sprite();
	void Draw();
	void Init(float x, float y, float width, float height);
private:
	
	int _x;
	int _y;
	int _widht;
	int _height;
	GLuint _vboID;//guarantee to be 32 bits
};

