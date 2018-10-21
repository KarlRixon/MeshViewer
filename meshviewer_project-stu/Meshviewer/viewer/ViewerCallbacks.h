///////////////////////////////////////////////////////////////////////////////
// Callback.h: a set of callback functions, which manage materials, trackball,
//    3D transformations, keyboard, and rendering.
// By Mingqiang Wei
// All rights Reserved. 
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef __WEI_VIEWER_CALLBACKS_H__
#define __WEI_VIEWER_CALLBACKS_H__


///////////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <iostream>
#include "ViewerConstants.h"
#include "ViewerTrackball.h"
#include "ViewerMaterials.h"


namespace ViewerN {


///////////////////////////////////////////////////////////////////////////////
//公共变量
GLboolean isListCreated (GL_FALSE);             //控制是否重新生成显示列表
GLint     drawingMode (DRAW_SOLID_AND_FRAME);   //绘制模式(缺省为"实体模式")

GLfloat   bgdColor[3] = {0.7f, 0.7f, 0.7f};     //背景色
GLfloat   fgdColor[3] = {0.0f, 0.0f, 0.0f};     //前景色
GLfloat   translate[3] = {0.0f, 0.0f, -100.0f}; //空间变换

int       flag(0);    //不同绘制对象之间的切换

Material  material;   //负责管理材质
Trackball trackball;  //司鼠标下的形体旋转变换


///////////////////////////////////////////////////////////////////////////////
void init(void);
void display(void);
void resize(int _width, int _height);

void mouse(int _button, int _state, int _x, int _y);
void motion(int _x, int _y);
void idle(void); 
void keyboard (unsigned char _k, int _x, int _y);

void drawingObject(void);
void extKeyboard(int _k);

void drawingWithMode(void);
 

///////////////////////////////////////////////////////////////////////////////
// implementations of callback functions
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
void init(void) { //OGL初始化函数
   trackball.init(GLUT_LEFT_BUTTON);

	GLfloat light_position1[4] = {-52, -16, -50, 0};
    GLfloat light_position2[4] = {-26, -48, -50, 0};
    GLfloat light_position3[4] = { 16, -52, -50, 0};

    GLfloat direction1[3] = {52,16,50};
    GLfloat direction2[3] = {26,48,50};
    GLfloat direction3[3] = {-16,52,50};

    GLfloat light_position4[4] = {52, 16, 50, 0};
    GLfloat light_position5[4] = {26, 48, 50, 0};
    GLfloat light_position6[4] = {-16, 52, 50, 0};

    GLfloat direction4[3] = {-52,-16,-50};
    GLfloat direction5[3] = {-26,-48,-50};
    GLfloat direction6[3] = {16,-52,-50};

//     GLfloat color1[4] = {1,0,0,1};
//     GLfloat color2[4] = {0,1,0,1};
//     GLfloat color3[4] = {0,0,1,1};
// 
//     GLfloat color4[4] = {1,0,0,1};
//     GLfloat color5[4] = {0,1,0,1};
//     GLfloat color6[4] = {0,0,1,1};
    
    
    GLfloat color1[4] = {0.43,0.43,0.43,1.0};
    GLfloat color2[4] = {0.43,0.43,0.43,1.0};
    GLfloat color3[4] = {0.45,0.45,0.45,1.0};

    GLfloat color4[4] = {0.45,0.45,0.45,1.0};
    GLfloat color5[4] = {0.45,0.45,0.45,1.0};
    GLfloat color6[4] = {0.45,0.45,0.45,1.0};

// 	GLfloat color1[4] = {1,1,1,0};
// 	GLfloat color2[4] = {1,1,1,0};
// 	GLfloat color3[4] = {1,1,1,0};
// 
// 	GLfloat color4[4] = {1,1,1,0};
// 	GLfloat color5[4] = {1,1,1,0};
// 	GLfloat color6[4] = {1,1,1,0};
    

    GLfloat ambient[4] = {0.3f,0.3f,0.3f,0.5f};

    GLfloat material_color[4] = {1,1,1,0.3f};
    GLfloat material_specular[4] = {0.5,0.5,0.5,0.5};
    GLfloat material_ambient[4] = {0.0,0.0,0.0,0.0};

    glClearColor(1,1,1,0);
    //glClearColor(0,0,0,0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color1);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color1);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, color2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, color2);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction3);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, color3);
    glLightfv(GL_LIGHT2, GL_SPECULAR, color3);

    glLightfv(GL_LIGHT3, GL_POSITION, light_position4);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction4);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, color4);
    glLightfv(GL_LIGHT3, GL_SPECULAR, color4);

    glLightfv(GL_LIGHT4, GL_POSITION, light_position5);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, direction5);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, color5);
    glLightfv(GL_LIGHT4, GL_SPECULAR, color5);

    glLightfv(GL_LIGHT5, GL_POSITION, light_position6);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, direction6);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, color6);
    glLightfv(GL_LIGHT5, GL_SPECULAR, color6);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128);

    glEnable(GL_LIGHTING);

    /*
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    */
    
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    //glEnable(GL_LINE_SMOOTH);
    //glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glLineWidth(0.5);
    //glPointSize(1.0f);
    glPointSize(1.0);
    //glPointSize(10.0);

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS);


   material.SetMaterial(MAT_EMERALD);  //缺省材质为"翡翠色"
}
  

///////////////////////////////////////////////////////////////////////////////
void display(void) { //OGL图形显示函数 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(bgdColor[0], bgdColor[1], bgdColor[2], 1.0f); 

   glPushMatrix();
     glTranslatef(translate[0], translate[1], translate[2]); //平移
     glPushMatrix();
       trackball.matrix(); //旋转
       trackball.isRedraw_ = GL_FALSE;

		 drawingWithMode();  //绘制图形

	  glPopMatrix ();
   glPopMatrix ();

   glutSwapBuffers ();
}


/////////////////////////////////////////////////////////////////////////////// 
void resize(int _width, int _height) {   //重新确定窗口大小
   trackball.reshape(_width, _height); 
   glViewport(0, 0, _width, _height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   GLfloat XYratio = (GLfloat)_width/(GLfloat)_height;
   gluPerspective(2.2, XYratio, 1.0,-1000);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


///////////////////////////////////////////////////////////////////////////////
void mouse(int _button, int _state, int _x, int _y) { //司鼠标点击信息之职
   trackball.mouse(_button, _state, _x, _y);
   glutPostRedisplay();
}


/////////////////////////////////////////////////////////////////////////////// 
void motion(int _x, int _y) { //司鼠标运动信息之职
   trackball.motion(_x, _y); 
   glutPostRedisplay();
}


///////////////////////////////////////////////////////////////////////////////
void idle (void) {	//空闲事件跟踪 
   if (trackball.idle())
      display();
}

	
///////////////////////////////////////////////////////////////////////////////
void drawingWithMode(void) { //图形绘制函数
   if (isListCreated) {
      glCallList(1);
	} else {
      if (glIsList(1)) glDeleteLists(1, 1);
      glNewList(1, GL_COMPILE_AND_EXECUTE);

      switch (drawingMode) {
	     case DRAW_VERTEX:
          glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	       drawingObject();
          break;
        case DRAW_WIRE_FRAME:
          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	       drawingObject();
          break;
        case DRAW_SOLID:
	       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			 drawingObject();
          break;
        case DRAW_SHADING_FRAME:
	       glDisable(GL_LIGHTING);
	       /////glEnable(GL_DEPTH_TEST);
	       glColor3f(1.0f, 1.0f, 1.0f);
	       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			 drawingObject();
 
          glEnable(GL_POLYGON_OFFSET_FILL);
          glPolygonOffset(1.0f, 1.0f);
	       glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	       glColor3f(fgdColor[0], fgdColor[1], fgdColor[2]);
			 drawingObject();

	       glEnable(GL_LIGHTING);
	       break;
        case DRAW_SOLID_AND_FRAME:
	       /////glEnable(GL_DEPTH_TEST);
	       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			 drawingObject();
 
          glEnable(GL_POLYGON_OFFSET_FILL);
          glPolygonOffset(1.0f, 1.0f);
	
			 glDisable(GL_LIGHTING);
	       glColor3f(fgdColor[0], fgdColor[1], fgdColor[2]);
	       glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			 drawingObject();

	       glEnable(GL_LIGHTING);
	       break;
        case DRAW_BOUNDING_BOX:
	       break; 
		}
	   glEndList();

      isListCreated = GL_TRUE;
	}
}

///////////////////////////////////////////////////////////////////////////////
void keyboard (unsigned char _k, int _x, int _y) {  //键盘操作 
   switch (_k) {
     case 'a':  //放大
     case 'A': translate[2] += 5.0f;   break;

     case 'z':  //缩小
     case 'Z': translate[2] -= 5.0f;   break;

     case 'd':  //向右
     case 'D': translate[0] += 0.1f;   break;

     case 's':  //向左
     case 'S': translate[0] -= 0.1f;   break;

     case 'e':  //向上
     case 'E': translate[1] += 0.1f;   break;

     case 'x':  //向下
     case 'X': translate[1] -= 0.1f;   break;

	  case 'c':  //快速缩小
     case 'C': translate[2] -= 50.0f;   break;

     case 'f':  //快速缩小
     case 'F': translate[2] += 50.0f;   break;

     case 'q':
     case 'Q':
     case 0x1B: exit(0);

	  default: 
        extKeyboard(_k);
	}
}


} // namespace ViewerN



#endif 