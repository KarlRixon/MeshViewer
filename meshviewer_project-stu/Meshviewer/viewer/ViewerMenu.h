///////////////////////////////////////////////////////////////////////////////
// Menu.h: Creating menu and submenus.
// By Mingqiang Wei
// Initially written at Mar. 2001, and reviewed at May 2005.
// All rights Reserved. 
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef __WEI_VIEWER_MENU_H__
#define __WEI_VIEWER_MENU_H__


///////////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <iostream>
#include <string>
#include "ViewerCallbacks.h"
#include "ViewerMaterials.h"


namespace ViewerN {


///////////////////////////////////////////////////////////////////////////////
void makeMenu(void);                             //�������˵�

static void handleRootMenu(int _item);           //������˵�
static void handleMaterialSubmenu(int _item);    //��������Ӳ˵�
static void handleBackColorSubmenu(int _item);   //������ɫ�Ӳ˵�
static void handleForeColorSubmenu(int _item);   //����ǰ��ɫ�Ӳ˵�
static void handleLightingSubmenu(int _item);    //��������Ӳ˵�
static void handleDrawingModeSubmenu(int _item); //�����ͼģʽ�Ӳ˵�


///////////////////////////////////////////////////////////////////////////////
std::string  submenuName ("Anonymity");   //�Ӳ˵�������

int          addSubmenu(std::string _submenuName);
static void  handleSubmenu(int _item);    //��������ӵ��Ӳ˵�


///////////////////////////////////////////////////////////////////////////////
void makeMenu(void) {   //�������˵�
   int materials_ = glutCreateMenu(handleMaterialSubmenu);  //���������Ӳ˵�
   glutAddMenuEntry("No Material",     MAT_NONE); 
   glutAddMenuEntry("Brass",           MAT_BRASS);
   glutAddMenuEntry("Bronze",          MAT_BRONZE);
   glutAddMenuEntry("Polished_Bronze", MAT_POLISHED_BRONZE);
   glutAddMenuEntry("Chrome",          MAT_CHROME);
   glutAddMenuEntry("Copper",          MAT_COPPER);
   glutAddMenuEntry("Polished_Copper", MAT_POLISHED_COPPER);
   glutAddMenuEntry("Gold",            MAT_GOLD);
   glutAddMenuEntry("Polished_Gold",   MAT_POLISHED_GOLD);
   glutAddMenuEntry("Pewter",          MAT_PEWTER);
   glutAddMenuEntry("Silver",          MAT_SLIVER);
   glutAddMenuEntry("Polished_Silver", MAT_POLISHED_SLIVER);
   glutAddMenuEntry("Emerald",         MAT_EMERALD);
   glutAddMenuEntry("Jade",            MAT_JADE);
   glutAddMenuEntry("Obsidian",        MAT_OBSIDIAN);
   glutAddMenuEntry("Pearl",           MAT_PEARL);
   glutAddMenuEntry("Ruby",            MAT_RUBY);
   glutAddMenuEntry("Turquoise",       MAT_TURQUOISE);
   glutAddMenuEntry("Black_Plastic",   MAT_BLACK_PLASTIC);
   glutAddMenuEntry("Black_Rubber",    MAT_BLACK_RUBBER);
  
   int bgColors_ = glutCreateMenu(handleBackColorSubmenu);  //����ɫ 
   glutAddMenuEntry("Black",           COLOR_BLACK);       
   glutAddMenuEntry("White",           COLOR_WHITE);
   glutAddMenuEntry("Red",             COLOR_RED);
   glutAddMenuEntry("Green",           COLOR_GREEN);
   glutAddMenuEntry("Blue",            COLOR_BLUE);
   glutAddMenuEntry("Grey",            COLOR_GREY);

   int frColors_ = glutCreateMenu(handleForeColorSubmenu);  //ǰ��ɫ 
   glutAddMenuEntry("Black",           COLOR_BLACK);       
   glutAddMenuEntry("White",           COLOR_WHITE);
   glutAddMenuEntry("Red",             COLOR_RED);
   glutAddMenuEntry("Green",           COLOR_GREEN);
   glutAddMenuEntry("Blue",            COLOR_BLUE);
   glutAddMenuEntry("Grey",            COLOR_GREY);

   int lightings_ = glutCreateMenu(handleLightingSubmenu); //�ƹ���� 
   glutAddMenuEntry("Light0 on",       LIGHT0_ON);
   glutAddMenuEntry("Light1 on",       LIGHT1_ON);
   glutAddMenuEntry("Both on",         BOTH_ON);
   glutAddMenuEntry("All on",          ALL_ON);
   glutAddMenuEntry("Light0 off",      LIGHT0_OFF);
   glutAddMenuEntry("Light1 off",      LIGHT1_OFF);
   glutAddMenuEntry("Both off",        BOTH_OFF);
   glutAddMenuEntry("All off",         ALL_OFF);

   int drawColors_ = glutCreateMenu(NULL);  //������ƹ� 
   glutAddSubMenu("ForeGround",        frColors_);
   glutAddSubMenu("BackGround",        bgColors_);
   glutAddSubMenu("Lighting",          lightings_);

   int drawModes_ = glutCreateMenu(handleDrawingModeSubmenu); //��ͼģʽ 
   glutAddMenuEntry("Vertex",          DRAW_VERTEX);
   glutAddMenuEntry("Wire frame",      DRAW_WIRE_FRAME);
   glutAddMenuEntry("Shade frame",     DRAW_SHADING_FRAME);
   glutAddMenuEntry("Solid+frame",     DRAW_SOLID_AND_FRAME);
   glutAddMenuEntry("Solid",           DRAW_SOLID);
   glutAddMenuEntry("Bounding box",    DRAW_BOUNDING_BOX);

   int additionSubmenu_ = addSubmenu("OK_OK");
   std::string submenuName_ = submenuName;

   glutCreateMenu(handleRootMenu);
   glutAddMenuEntry("Main Menu",       '\0');
   glutAddMenuEntry("---------------", '\0');
   glutAddSubMenu("Drawing Colors",    drawColors_);
   glutAddSubMenu("Materials",         materials_);
   glutAddSubMenu("Drawing Mode",      drawModes_);

	if (additionSubmenu_) {
      glutAddSubMenu(submenuName.data(), additionSubmenu_);
   }

	glutAddMenuEntry("Quit(Esc)",       886);

   glutAttachMenu(GLUT_RIGHT_BUTTON);
}


///////////////////////////////////////////////////////////////////////////////
void handleRootMenu(int _item) {          //������˵�
	if (_item==886) exit(0);
	std::cout<<"Root Menu.\n";
}


///////////////////////////////////////////////////////////////////////////////
void handleMaterialSubmenu(int _item) {  //��������Ӳ�
	material.SetMaterial(_item);
   //is_list_created_ = GL_FALSE;
}


///////////////////////////////////////////////////////////////////////////////
void handleBackColorSubmenu(int _item) {  //����ɫ
   switch (_item) {
	   case COLOR_BLACK:
		   bgdColor[0]=0.0f;
			bgdColor[1]=0.0f; 
			bgdColor[2]=0.0f; break;
      case COLOR_WHITE:
		   bgdColor[0]=1.0f;
			bgdColor[1]=1.0f;
			bgdColor[2]=1.0f;	break;
      case COLOR_RED:
		   bgdColor[0]=1.0f;
			bgdColor[1]=0.0f;
			bgdColor[2]=0.0f;	break;
      case COLOR_GREEN:
		   bgdColor[0]=0.0f;
			bgdColor[1]=1.0f;
			bgdColor[2]=0.0f;	break;
      case COLOR_BLUE:
		   bgdColor[0]=0.0f;
			bgdColor[1]=0.0f;
			bgdColor[2]=1.0f;	break;
      case COLOR_GREY:
		   bgdColor[0]=0.7f;
			bgdColor[1]=0.7f;
			bgdColor[2]=0.7f;	//break;
	};
   isListCreated = GL_FALSE;
}


///////////////////////////////////////////////////////////////////////////////
void handleForeColorSubmenu(int _item) { //ǰ��ɫ
   switch (_item) {
      case COLOR_BLACK:
		   fgdColor[0]=0.0f;
			fgdColor[1]=0.0f; 
			fgdColor[2]=0.0f;   break;
      case COLOR_WHITE:
		   fgdColor[0]=1.0f;
			fgdColor[1]=1.0f;
			fgdColor[2]=1.0f;	break;
      case COLOR_RED:
		   fgdColor[0]=1.0f;
			fgdColor[1]=0.0f;
			fgdColor[2]=0.0f;	break;
      case COLOR_GREEN:
		   fgdColor[0]=0.0f;
			fgdColor[1]=1.0f;
			fgdColor[2]=0.0f;	break;
      case COLOR_BLUE:
		   fgdColor[0]=0.0f;
			fgdColor[1]=0.0f;
			fgdColor[2]=1.0f;	break;
      case COLOR_GREY:
		   fgdColor[0]=0.7f;
			fgdColor[1]=0.7f;
			fgdColor[2]=0.7f; //break;
	}

   isListCreated = GL_FALSE;
}


///////////////////////////////////////////////////////////////////////////////
void handleLightingSubmenu(int _item) { //����
   switch (_item) {
	   case LIGHT0_ON:   // on
		   glEnable(GL_LIGHT0);   break;
	   case LIGHT1_ON:
         glEnable(GL_LIGHT1);   break;
	   case BOTH_ON:
		   glEnable(GL_LIGHT0 | GL_LIGHT1); break;
	   case ALL_ON:
		   glEnable(GL_LIGHTING); break;
	   case LIGHT0_OFF:  // off
		   glDisable(GL_LIGHT0);  break;
	   case LIGHT1_OFF:
         glDisable(GL_LIGHT1);  break;
	   case BOTH_OFF:
		   glDisable(GL_LIGHT0 | GL_LIGHT1); break;
	   case ALL_OFF:
		   glDisable(GL_LIGHTING);  //break;
	}

   isListCreated = GL_FALSE;
}


///////////////////////////////////////////////////////////////////////////////
void handleDrawingModeSubmenu(int _item) { //����ģʽ�Ӳ˵�
	switch (_item) {
      case DRAW_SOLID:
			drawingMode = DRAW_SOLID;        break;
	   case DRAW_WIRE_FRAME:
		   drawingMode = DRAW_WIRE_FRAME;   break;
	   case DRAW_SHADING_FRAME:
		   drawingMode = DRAW_SHADING_FRAME;  break;
	   case DRAW_SOLID_AND_FRAME:
		   drawingMode = DRAW_SOLID_AND_FRAME;  break;
	   case DRAW_VERTEX:
		   drawingMode = DRAW_VERTEX;       break;
	   case DRAW_BOUNDING_BOX:
		   drawingMode = DRAW_BOUNDING_BOX; break;  
	}
   isListCreated = GL_FALSE;
}


} //namespace


#endif //