#include "App.h"
#include "GameScene.h"

App* App::m_instance = nullptr;

App::App(int argc, char** argv) : m_argc(argc), m_argv(argv),
	m_winPosition({ NULL, NULL }), m_winSize({ NULL, NULL }),
	m_title(nullptr), m_pScene(nullptr)
{
}

App::~App()
{
	release();
}

App* App::create(int argc, char** argv)
{
	if (!m_instance)
		m_instance = new App(argc, argv);
	return m_instance;
}

App* App::instance()
{
	if (m_instance)
		return m_instance;
	return nullptr;
}

void App::initialize(POINT winPosition, SIZE winSize, char* title)
{
	m_winPosition = winPosition;
	m_winSize = winSize;

	m_title = new char[strlen(title) + 1];
	strcpy(m_title, title);

	GLinit();
}

void App::initialize(int x, int y, int width, int height, char* title)
{
	m_winPosition = { x , y };
	m_winSize = { width, height };

	m_title = new char[strlen(title) + 1];
	strcpy(m_title, title);

	GLinit();

	m_pScene = new GameScene();
	if (m_pScene)
		m_pScene->initialize();
}

void App::GLinit()
{
	glutInit(&m_argc, m_argv); glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(m_winPosition.x, m_winPosition.y);
	glutInitWindowSize(m_winSize.cx, m_winSize.cy);
	glutCreateWindow(m_title);
}

void App::release()
{
	if (m_pScene)
	{
		m_pScene->release();
		delete m_pScene;
	}
	delete[] m_title;
}

int App::run()
{
	glutDisplayFunc(App::drawScene);
	glutReshapeFunc(App::Reshape);
	glutKeyboardFunc(App::Keyboard);
	glutMouseFunc(App::Mouse);
	glutMotionFunc(App::Motion);
	glutTimerFunc(1000 / 60, App::TimerFunction, 1);
	glutMainLoop();
	return 0;
}

GLvoid App::drawScene(GLvoid) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// 설정된 색으로 전체를 칠하기

	if (g_app->m_pScene)
		g_app->m_pScene->render();

	// 이 부분에 색상 지정하고 사각형 그리기 …
	glutSwapBuffers();
}

GLvoid App::Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.f, 800.f, 0.f, 600.f, -400.f, 400.f);
}

GLvoid App::Keyboard(unsigned char key, int x, int y)
{
	if (g_app->m_pScene)
		g_app->m_pScene->keyboard(key, x, y);
}

GLvoid App::Mouse(int button, int state, int x, int y)
{
	if (g_app->m_pScene)
		g_app->m_pScene->mouse(button, state, x, y);
}

GLvoid App::Motion(int x, int y)
{
	if (g_app->m_pScene)
		g_app->m_pScene->motion(x, y);
}

GLvoid App::TimerFunction(int value)
{
	if (g_app->m_pScene)
		g_app->m_pScene->update();
	glutTimerFunc(1000 / 60, App::TimerFunction, 1);
	glutPostRedisplay();
}