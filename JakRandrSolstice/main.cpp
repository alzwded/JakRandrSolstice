#include "display.h"
#include <SolsticeRuntime.h>
#include <GL/glut.h>

#include <iostream>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	try {
		SolsticeApplication::Init(argc, argv);
		SolsticeApplication::SetRenderFunction(&glutRender);
	} catch(Exception ex) {
		std::cerr << ex << std::endl;
		exit(1);
	}

	glutDisplayFunc(&glutCallback); // glutCallBack will call SolsticeApplication::MainLoop
	glutMainLoop();
	return 0;
}