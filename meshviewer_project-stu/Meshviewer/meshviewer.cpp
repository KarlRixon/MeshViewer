/************************************************************************/
/* 
*a simple viewer for rendering triangular mesh based on GLUT Libs.
*by Wei Mingqiang (mingqiang.wei@gmail.com)
*12:56:15.2018.04.16
*all rights reserved 
*feel free to contact me if bugs are found
*/
/************************************************************************/
#ifdef _MSC_VER
#pragma warning (disable: 4786)
#endif

//////////////////////////////////////////////////////////////////////////
#pragma comment(lib, "glut32.lib") 
#pragma comment(lib, "opengl32.lib") 
#pragma comment(lib, "glu32.lib") 
/////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////// 
#include <iostream>
/////////////////////////////////////////////////////////////////////////////// 
#include <iostream>
#include "MeshInterface.h"   ///<<<===========界面/功能个性化 


//using namespace ViewerN;
void Usage(void) {
	std::cout << "USAGE:\n---Keyboard---\n";
	std::cout << "  [A/a]--Zoom in;          [Z/z]--Zoom out\n";
	std::cout << "  [F/f]--Zoom in quickly;  [C/c]--Zoom out quickly\n";
	std::cout << "  [W/w]--Move up;    [X/x]--Move down;";
	std::cout << "  [S/w]--Move left;  [D/d]--Move right\n";
	std::cout << "  [U/u],[I/i],[O/o],[P/p]--Selecting model to show\n";
	std::cout << "  [Q/q]--Quit\n";
	std::cout << "---Mouse---\n";
	std::cout << "  Left Button -- to Rotate;  Right Button -- Pop Menu\n\n";
}


///////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

	Usage();
	glutInitWindowPosition(400, 0);
	glutInitWindowSize(620, 620);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	if (glutCreateWindow("Viewer(by Mingqiang WEI)") == GL_FALSE)
		exit(1);

	ViewerN::init();
	ViewerN::makeMenu();

	glutDisplayFunc(ViewerN::display);
	glutReshapeFunc(ViewerN::resize);
	glutMouseFunc(ViewerN::mouse);
	glutMotionFunc(ViewerN::motion);
	glutIdleFunc(ViewerN::idle);
	glutKeyboardFunc(ViewerN::keyboard);

	MyMeshInit();///里面加载各种函数对网格模型进行处理

	glutMainLoop();
	return 0;
}