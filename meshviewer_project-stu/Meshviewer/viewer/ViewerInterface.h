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
int addSubmenu(std::string _sub_menu_name) {   //����µ��Ӳ˵� 
   submenuName = std::string("To Do.."); //<<==== �Ӳ˵��� 
	int submenu_ = glutCreateMenu(handleSubmenu);
   glutAddMenuEntry("No1",      0); //<<=== ����Ӳ˵��� 
   glutAddMenuEntry("No2",      1); 	
	return submenu_;
}
///////////////////////////////////////////////////////////////////////////////
void handleSubmenu(int _item) {                //��������ӵ��Ӳ˵�
	switch (_item) 
	{ 
		case 0:  
			std::cout<<"No.0 is selected!\n"; break; //<<====�Ӳ˵����� 
		case 1:
			std::cout<<"No.1 is selected!\n"; break; //<<====�Ӳ˵����� 
	} 
	isListCreated = GL_FALSE;
}
///////////////////////////////////////////////////////////////////////////////
void extKeyboard(int _k) {                     //�����µļ�����
	std::cout<<(char)_k<<" is pressed! OK!!\n"; 
	switch ((char)_k) 
	{ 
		case 'u': //<<==== �����¼�
			flag = 1; break; //<<==== �����¼�
		case 'i': //<<==== �����¼�
			flag = 2; break; //<<==== �����¼�
		case 'o': //<<==== �����¼�
			flag = 3; break; //<<==== �����¼�
		case 'p': //<<==== �����¼�
			flag = 4; break; //<<==== �����¼�
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
			//glutSolidIcosahedron(); //<<======= ����������
			glutSolidTeapot(1.0f);
	}
}

} //namespace

#endif 