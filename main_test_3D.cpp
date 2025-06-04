#include "HW3.h"
#include "Scene.h"

#include "PPP/Graph.h"
#include "PPP/GUI.h"

using namespace Graph_lib;

struct ModelViewer : Window
{
	ModelViewer(Application* app, Point xy, int w, int h, const string& title);
	~ModelViewer();

private:
	int win_width = 0;
	int win_height = 0;

	Scene* scene = nullptr;

	float cam_dist = 1.0f;
	float cam_phi = 0.0f;
	float cam_theta = 0.0f;

	void renderScene();

	//
	Application* app = nullptr;

	Button load_cube_button;
	Button load_bunny_button;
	Button load_teapot_button;
//	Button load_armadillo_button;
	Button zoom_in_button;
	Button zoom_out_button;
	Button move_left_button;
	Button move_right_button;
	Button move_up_button;
	Button move_down_button;
	Button cull_button;
	Button exit_button;

	void loadCube();
	void loadBunny();
	void loadTeapot();
	void loadArmadillo();
	void zoomIn();
	void zoomOut();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void cull();
	void exit();
};

ModelViewer::ModelViewer(Application* app, Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	app(app),
	win_width(w),
	win_height(h),
	load_cube_button(Point(10, 10), 70, 20, "Cube", [this]() { loadCube(); }),
	load_bunny_button(Point(90, 10), 70, 20, "Bunny", [this]() { loadBunny(); }),
	load_teapot_button(Point(170, 10), 70, 20, "Teapot", [this]() { loadTeapot(); }),
//	load_armadillo_button(Point(250, 10), 70, 20, "Armadillo", [this]() { loadArmadillo(); }),
	zoom_in_button(Point(400, 10), 70, 20, "In", [this]() { zoomIn(); }),
	zoom_out_button(Point(480, 10), 70, 20, "Out", [this]() { zoomOut(); }),
	move_left_button(Point(560, 10), 70, 20, "Left", [this]() { moveLeft(); }),
	move_right_button(Point(640, 10), 70, 20, "Right", [this]() { moveRight(); }),
	move_up_button(Point(720, 10), 70, 20, "Up", [this]() { moveUp(); }),
	move_down_button(Point(800, 10), 70, 20, "Down", [this]() { moveDown(); }),
	cull_button(Point(w - 160, 10), 70, 20, "Cull", [this]() { cull(); }),
	exit_button(Point(w - 80, 10), 70, 20, "Exit", [this]() { exit(); })
{
	attach(load_cube_button);
	attach(load_bunny_button);
	attach(load_teapot_button);
//	attach(load_armadillo_button);

	attach(zoom_in_button);
	attach(zoom_out_button);
	attach(move_left_button);
	attach(move_right_button);
	attach(move_up_button);
	attach(move_down_button);
	attach(cull_button);
	attach(exit_button);

	scene = new Scene(this);
	scene->addMesh(Geometry::CUBE);

	cam_dist = 3.0f;
	cam_phi = 0.0f;
	cam_theta = radian_from_degree(90.0f);

	renderScene();
}

ModelViewer::~ModelViewer()
{
	delete scene;
}

void ModelViewer::renderScene()
{
	float cam_x = cam_dist * cosf(cam_phi) * sinf(cam_theta);
	float cam_z = cam_dist * sinf(cam_phi) * sinf(cam_theta);
	float cam_y = cam_dist * cosf(cam_theta);

	scene->setLookAt(Vector3(cam_x, cam_y, cam_z), Vector3(0, 0, 0), Vector3(0, 1, 0));
	scene->setPerspective(radian_from_degree(45.0f), (float)win_width / (float)win_height, 1.0f, 100.0f);
	scene->render();

	draw();
}

void ModelViewer::loadCube()
{
	scene->removeAllMeshes();
	scene->addMesh(Geometry::CUBE);

	renderScene();
}

void ModelViewer::loadBunny()
{
	scene->removeAllMeshes();
	scene->addMesh("bunny.txt");

	renderScene();
}

void ModelViewer::loadTeapot()
{
	scene->removeAllMeshes();
	scene->addMesh("teapot.txt");

	renderScene();
}

void ModelViewer::loadArmadillo()
{
	scene->removeAllMeshes();
	scene->addMesh("armadillo.txt");

	renderScene();
}

void ModelViewer::zoomIn()
{
	float d = 0.25f;
	if (cam_dist > d)
	{
		cam_dist -= d;
		renderScene();
	}
}

void ModelViewer::zoomOut()
{
	float d = 0.25f;
	cam_dist += d;
	renderScene();
}

void ModelViewer::moveLeft()
{
	float da = radian_from_degree(5.0f);
	cam_phi += da;
	renderScene();
}

void ModelViewer::moveRight()
{
	float da = radian_from_degree(5.0f);
	cam_phi -= da;
	renderScene();
}

void ModelViewer::moveUp()
{
	float da = radian_from_degree(5.0f);
	if (cam_theta > da)
	{
		cam_theta -= da;
		renderScene();
	}
}

void ModelViewer::moveDown()
{
	float da = radian_from_degree(5.0f);
	if (cam_theta <= radian_from_degree(90.0f) - da)
	{
		cam_theta += da;
		renderScene();
	}
}

void ModelViewer::cull()
{
	scene->toggleCulling();
	renderScene();
}

void ModelViewer::exit()
{
	close();
}

int main()
{
	Application app;

	int win_width = 1280;
	int win_height = 960;
	Point win_tl(0, 0);

	ModelViewer win(&app, win_tl, win_width, win_height, "3D Modeling and Viewing");
	app.gui_main();
}
