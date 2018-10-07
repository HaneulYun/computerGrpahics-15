#include <gl/freeglut.h>
#include "GameScene.h"

#define PI 3.141592

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::initialize()
{
	{
		auto& v = grid;
		v.vectors.push_back({ -400, 0 });
		v.vectors.push_back({  400, 0 });
		v.vectors.push_back({ 0, -300 });
		v.vectors.push_back({ 0,  300 });

		v.setPosition(400, 300, 0);
		v.setColor(1.f, 1.f, 1.f);
		v.setBeginMode(GL_LINES);
	}
	for (int i = 0; i < 6; ++i)
	{
		obj[i][0].setScale(80, 20, 20);
		obj[i][0].setPosition(0, 100, 0);

		obj[i][1].setScale(20, 80, 20);
		obj[i][1].setPosition(-50, 50, 0);

		obj[i][2].setScale(20, 80, 20);
		obj[i][2].setPosition(50, 50, 0);

		obj[i][3].setScale(80, 20, 20);
		obj[i][3].setPosition(0, 0, 0);

		obj[i][4].setScale(20, 80, 20);
		obj[i][4].setPosition(-50, -50, 0);

		obj[i][5].setScale(20, 80, 20);
		obj[i][5].setPosition(50, -50, 0);

		obj[i][6].setScale(80, 20, 20);
		obj[i][6].setPosition(0, -100, 0);

		for (int j = 0; j < 7; ++j)
		{
			obj[i][j].setCube(1.f);
			obj[i][j].setColor(0.f, 1.f, 1.f);
			parents[i].addChild(&obj[i][j]);
		}
	}
	parents[0].setPosition(-390, 0, 0);
	parents[1].setPosition(-250, 0, 0);
	parents[2].setPosition(-70, 0, 0);
	parents[3].setPosition(70, 0, 0);
	parents[4].setPosition(250, 0, 0);
	parents[5].setPosition(390, 0, 0);

	colon[0].setPosition(-160, 50, 0);
	colon[1].setPosition(-160, -50, 0);
	colon[2].setPosition(160, 50, 0);
	colon[3].setPosition(160, -50, 0);
	for (int i = 0; i < 4; ++i)
	{
		colon[i].setCube(1.f);
		colon[i].setColor(0.f, 1.f, 1.f);
		colon[i].setScale(20, 20, 20);
		master.addChild(&colon[i]);
	}

	for (int i = 0; i < 6; ++i)
		master.addChild(&parents[i]);
	master.setPosition(400, 300, 0);
	master.setRotation(30, 30, 0);
	master.setScale(0.8, 0.8, 0.8);
}

void GameScene::update()
{
	grid.update();
	master.update();

	tNow = time(NULL);
	ttm = localtime(&tNow);
	tpDay = std::chrono::system_clock::from_time_t(mktime(ttm));
	tpNow = std::chrono::system_clock::now();
	int ms = std::chrono::duration_cast<std::chrono::milliseconds>(tpNow - tpDay).count();
	auto f = [](auto& v, int n) {
		for (auto& r : v)
			r.setSolid(true);
		switch (n)
		{
		case 0: v[3].setSolid(false); break;
		case 1:for (auto& r : v)r.setSolid(false);
			v[2].setSolid(true); v[5].setSolid(true); break;
		case 2:v[1].setSolid(false); v[5].setSolid(false); break;
		case 3:v[1].setSolid(false); v[4].setSolid(false); break;
		case 4:v[0].setSolid(false); v[4].setSolid(false); v[6].setSolid(false); break;
		case 5:v[2].setSolid(false); v[4].setSolid(false); break;
		case 6:v[2].setSolid(false); break;
		case 7:v[3].setSolid(false); v[4].setSolid(false); v[6].setSolid(false); break;
		case 8:break;
		case 9:v[4].setSolid(false); break;
		}
	};
	f(obj[0], ttm->tm_hour / 10);
	f(obj[1], ttm->tm_hour % 10);
	f(obj[2], ttm->tm_min / 10);
	f(obj[3], ttm->tm_min % 10);
	f(obj[4], ttm->tm_sec / 10);
	f(obj[5], ttm->tm_sec % 10);
	if (ms < 500)
		for (auto& v : colon)
			v.setSolid(false);
	else
		for (auto& v : colon)
			v.setSolid(true);
}


void GameScene::render()
{
	grid.render();
	master.render();
}

void GameScene::release()
{
}

void GameScene::keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		master.addRotation(1, 0, 0);
		break;
	case 's':
		master.subRotation(1, 0, 0);
		break;
	case 'a':
		master.addRotation(0, 1, 0);
		break;
	case 'd':
		master.subRotation(0, 1, 0);
		break;
	case 'q':
		exit(NULL);
		break;
	}
}

void GameScene::mouse(int button, int state, int x, int y)
{
}

void GameScene::motion(int x, int y)
{
}