#include "display.h"
#include <SolsticeRuntime.h>
#include <GL/glut.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	SolsticeApplication::Init(argc, argv);
	SolsticeApplication::SetRenderFunction(&glutRender);
	glutDisplayFunc(&glutCallback); // glutCallBack will call SolsticeApplication::MainLoop
	glutMainLoop();
	return 0;
}