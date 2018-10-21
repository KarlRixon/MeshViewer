///////////////////////////////////////////////////////////////////////////////
// Interface.h: interface functions are in this file. 
// By Mingqiang Wei
// Initially written at Mar. 2001, and reviewed at May 2005.
// All rights Reserved. 
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef __WEI_VIEWER_INTERFACE_H__
#define __WEI_VIEWER_INTERFACE_H__
///////////////////////////////////////////////////////////////////////////////
#include "ViewerCallbacks.h" 
#include "ViewerMenu.h"
//////////////////////////////////////////////////////////////////////////
namespace ViewerN 
{
int addSubmenu(std::string _sub_menu_name) {   //添加新的子菜单 
   submenuName = std::string("To Do.."); //<<==== 子菜单名 
	int submenu_ = glutCreateMenu(handleSubmenu);
   glutAddMenuEntry("No1",      0); //<<=== 添加子菜单项 
   glutAddMenuEntry("No2",      1); 	
	return submenu_;
}
///////////////////////////////////////////////////////////////////////////////
void handleSubmenu(int _item) {                //处理新添加的子菜单
	switch (_item) 
	{ 
		case 0:  
			std::cout<<"No.0 is selected!\n"; break; //<<====子菜单处理 
		case 1:
			std::cout<<"No.1 is selected!\n"; break; //<<====子菜单处理 
	} 
	isListCreated = GL_FALSE;
}
///////////////////////////////////////////////////////////////////////////////
void extKeyboard(int _k) {                     //定义新的键功能
	std::cout<<(char)_k<<" is pressed! OK!!\n"; 
	switch ((char)_k) 
	{ 
		case 'u': //<<==== 定义新键
			flag = 1; break; //<<==== 处理新键
		case 'i': //<<==== 定义新键
			flag = 2; break; //<<==== 处理新键
		case 'o': //<<==== 定义新键
			flag = 3; break; //<<==== 处理新键
		case 'p': //<<==== 定义新键
			flag = 4; break; //<<==== 处理新键
		default:
			flag = 5;  
	}
   isListCreated = GL_FALSE; 
}
///////////////////////////////////////////////////////////////////////////////
void drawingObject(void) {
   switch (flag) 
	{
		case 1:
			glutSolidCube(1.0f); break;
		case 2:
			glutSolidTorus(0.5f, 1.0, 30, 30); break;
		case 3:
			glutSolidSphere(1.0f, 30, 30); break;
		case 4:
			glutSolidTeapot(1.0f); break;
		default: 
			//glutSolidIcosahedron(); //<<======= 添加形体绘制
			glutSolidTeapot(1.0f);
	}
}

} //namespace

#endif 