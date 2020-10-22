#include <cmath>
static constexpr double Pi = acos(-1.);
#include "MyWindow.h"

MyWindow::MyWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
}
static const float s_material_brown[4]  { 0.5f, 0.2f,0.1f, 1.f };
void MyWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
			5., 3., 4.,
			0., 0., 0.,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);


	double height = _Height;
	double width = _Width;
	double length = _Length;


	glBegin(GL_QUADS);

	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( length,-width,  height);
	glVertex3d( length, width,  height);
	glVertex3d( length, width, -height);
	glVertex3d( length,-width, -height);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width, height);
	glVertex3d( -length, -width, height);
	glVertex3d( -length, -width,-height);
	glVertex3d( -length,  width,-height);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length,  width, -height);
	glVertex3d( -length,  width, -height);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( length, -width,  height);
	glVertex3d( -length, -width, height);
	glVertex3d( -length, -width, -height);
	glVertex3d( length, -width, -height);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length, -width,  height);
	glVertex3d( -length, -width,  height);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d(  length,  width, -height);
	glVertex3d( -length,  width, -height);
	glVertex3d( -length, -width, -height);
	glVertex3d(  length, -width, -height);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width / 10000.,  height * 2.);
	glVertex3d(  length,  width / 10000., height * 2.);
	glVertex3d(  length, -width,  height);
	glVertex3d( -length, -width,  height);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length, -width / 10000., height * 2.);
	glVertex3d( -length, -width / 10000., height * 2.);

	glNormal3d(  1., 0., 0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d(  length, -width / 10000., height * 2.);
	glVertex3d(  length,  -width / 10000., height * 2.);
	glVertex3d(  length,  width, height);
	glVertex3d(  length, -width, height);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_brown);
	glVertex3d( -length,  width / 100000., height * 2.);
	glVertex3d( -length, -width / 100000., height * 2.);
	glVertex3d( -length, -width, height);
	glVertex3d( -length,  width, height);


	glEnd();
}

void MyWindow::handle_logic()
{
//	_angle += 1.;
//	if (_angle >= 360.)
//		_angle -= 360.;
//
//	_eye_level = sin(_angle / 180. * Pi);
}
void MyWindow::handle_keys(const Uint8 * keys)
{
	if (keys[SDL_SCANCODE_LEFT]) {
		_angle += 1.;
			if (_angle >=360.)
				_angle -=360.;

			_eye_level = sin(_angle / 180. * Pi);
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		_angle -= 1.;
			if (_angle >=360.)
				_angle -=360.;

			_eye_level = sin(_angle / 180. * Pi);
	}
	if (keys[SDL_SCANCODE_Q]) {
			_Height += 0.01;
		}

		if (keys[SDL_SCANCODE_R]) {
			_Height -= 0.01;
		}

		if (keys[SDL_SCANCODE_W]) {
			_Width += 0.01;
		}

		if (keys[SDL_SCANCODE_T]) {
			_Width -= 0.01;
		}

		if (keys[SDL_SCANCODE_E]) {
			_Length += 0.01;
		}

		if (keys[SDL_SCANCODE_Y]) {
			_Length -= 0.01;
		}

		if (_Length <= 1.)
			_Length = 1.;

		if (_Width <= 1.)
			_Width = 1.;

		if (_Height <= 1.)
			_Height = 1.;
	}
