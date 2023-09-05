#define GL_SILENCE_DEPRECATION
#include <math.h>
#include "Camera3D.h"
#include "fssimplewindow.h"

const double Camera3D::PI = 3.1415927;

Camera3D::Camera3D()
{
	initialize();
}

void Camera3D::initialize(void)
{
	x = y = z = 0;
    h = PI;
	p = b = 0;

	fov = PI / 6.0;  // 30 degree
	nearZ = 0.1;
	farZ = 400.0;
}

void Camera3D::setUpCameraProjection(void)
{
	int wid, hei;
	double aspect;

	FsGetWindowSize(wid, hei);
	aspect = (double)wid / (double)hei;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov * 180.0 / PI, aspect, nearZ, farZ);
}

void Camera3D::setUpCameraTransformation(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotated(-b * 180.0 / PI, 0.0, 0.0, 1.0); // bank
	glRotated(-p * 180.0 / PI, 1.0, 0.0, 0.0); // pitch
	glRotated(-h * 180.0 / PI, 0.0, 1.0, 0.0); // heading
	glTranslated(-x, -y, -z);
}

void Camera3D::getForwardVector(double& vx, double& vy, double& vz)
{
	vx = -cos(p) * sin(h);
	vy = sin(p);
	vz = -cos(p) * cos(h);
}

