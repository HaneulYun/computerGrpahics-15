#pragma once
#include <ctime>
#include <chrono>
#include "Scene.h"
#include "Object3d.h"
#include "ObjectGlutModel.h"

class GameScene : public Scene
{
	Object3d grid;

	ObjectGlutModel obj[6][7];

	Object parents[6];
	ObjectGlutModel colon[4];

	Object master;

	std::chrono::system_clock::time_point tpNow, tpDay;
	time_t tNow;
	tm *ttm;
public:
	GameScene();
	~GameScene();

	void initialize();
	void update();
	void render();
	void release();

	void keyboard(unsigned char key, int x, int y);
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};