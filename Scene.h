#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void initialize();
	virtual void update();
	virtual void render();
	virtual void release();

	virtual void keyboard(unsigned char key, int x, int y);
	virtual void mouse(int button, int state, int x, int y);
	virtual void motion(int x, int y);
};