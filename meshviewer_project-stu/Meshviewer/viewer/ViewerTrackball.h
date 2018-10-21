///////////////////////////////////////////////////////////////////////////////
// Trackball.h: a very simple trackball class.
// By Mingqiang Wei
// Initially written at Mar. 2001, and reviewed at May 2005.
// All rights Reserved. 
//-----------------------------------------------------------------------------
// Usage:
//  o  init()在任何其它函数之前调用
//  o  reshape()在reshape回调函数中调用
//  o  matrix()得到跟踪球的旋转矩阵
//  o  startMotion()启动跟踪球
//  o  stopMotion()使跟踪球不起作用
//  o  motion()在鼠标运动回调函数中调用之
//  o  animate(GL_TRUE)如果希望在松开鼠标后仍能转动请调用之
//  o  animate(GL_FALSE)如果希望在松开鼠标后不转动请调之
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef __WEI_VIEWER_TRACKBALL_H__
#define __WEI_VIEWER_TRACKBALL_H__


///////////////////////////////////////////////////////////////////////////////
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>


namespace ViewerN {



///////////////////////////////////////////////////////////////////////////////
class Trackball {
public:
	Trackball(void);
	~Trackball(void) {};

public:
	inline void init(unsigned _button);
	inline void animate(bool _animate);
   inline void matrix(void);
   inline void reshape(int _width, int _height);
   inline void mouse(int _button, int _state, int _x, int _y);
   inline void motion(int _x, int _y);
   inline bool idle(void);

private:
	inline void point2Vector(double _x, double _y, double _v[3]);

public:
   bool isButtonDown_;
	bool isRedraw_;
   bool isAnimater_;

private:
	unsigned lastTime_;
   double   lastPosition_[3];

   double   angle_; 
   double   axis_[3];
   double   transform_[4][4];
   unsigned width_;
   unsigned height_;

   int      button_;  
   bool     isTracking_; 

};



///////////////////////////////////////////////////////////////////////////////
/// 类实现
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//构造函数 
Trackball::Trackball(void) : isButtonDown_(GL_FALSE), angle_(0.0),  
   button_(-1), isTracking_(GL_FALSE), isAnimater_(GL_TRUE)
{}


///////////////////////////////////////////////////////////////////////////////
//将屏幕上一点变为跟踪球上的点 
void Trackball::point2Vector(double _x, double _y, double _v[3]) { 
   //project x, y onto a hemi-sphere centered within width, height. 
   _v[0] = (2.0*_x - width_) / width_;    //根据视口参数，求x(in [-1..1])
   _v[1] = (height_ - 2.0*_y) / height_;  //求y
   double d_ = sqrt(_v[0]*_v[0] + _v[1]*_v[1]);   //长度
   _v[2] = cos(sqrt(2.0)*3.1415926/4.0*d_); 
	       //cos((3.14159265 / 2.0) * ((d_< 1.0) ? d_ : 1.0));  
   double a_ = 1.0 / sqrt(_v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2]);
   _v[0] *= a_;      //单位化
   _v[1] *= a_;
   _v[2] *= a_;
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::animate(bool _animate) {
   isAnimater_ = _animate;
}


///////////////////////////////////////////////////////////////////////////////
//初始化跟踪球 
void Trackball::init(unsigned _button) {
   button_ = _button;     //定义跟踪球跟踪的鼠标键
   angle_  = 0.0;         //旋转角清0

   axis_[0] = axis_[1] = axis_[2] = 0.0;
   //put the identity in the trackball transform 
   glPushMatrix();
   glLoadIdentity();      //置累加旋转量为单位矩阵
   glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)transform_);
   glPopMatrix();
}


///////////////////////////////////////////////////////////////////////////////
//对GL状态机当前变换矩阵施加鼠标运动所定义的旋转 
void Trackball::matrix(void) {
   glPushMatrix();
   glLoadIdentity();   //定义跟踪球定义的旋转
   glRotatef(angle_, axis_[0], axis_[1], axis_[2]);
   glMultMatrixf((GLfloat*)transform_);  //与过去的旋转量进行叠加 
   glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)transform_); //最终的旋转量
   glPopMatrix();

   glMultMatrixf((GLfloat*)transform_);  //对当前变换矩阵施加累积旋转量
}


///////////////////////////////////////////////////////////////////////////////
/// 修正视口参数 
void Trackball::reshape(int _width, int _height) {
   width_  = _width;    //修正视口参数
   height_ = _height;   //要不要重新计算跟踪球,还需好好研究..... 答案:No!!
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::mouse(int _button, int _state, int _x, int _y) {
   //若定义跟踪球的鼠标键按下，...; 
   if (_state == GLUT_DOWN && _button == button_){
   	isButtonDown_ = GL_TRUE;
	   //将屏幕上的起始点变为跟踪球上的点
      isTracking_ = GL_TRUE;      //跟踪开始了也
      lastTime_ = glutGet(GLUT_ELAPSED_TIME); //记录下开始时的时间
      point2Vector(_x, _y, lastPosition_);    //将屏幕始点变为跟踪球上的点
   } else if (_state == GLUT_UP && _button == button_) { //否则，若....
	   isButtonDown_ = GL_FALSE;
      isTracking_   = GL_FALSE;   //不跟踪 
      if (lastTime_==(GLuint)glutGet(GLUT_ELAPSED_TIME) && isAnimater_) {
  	      isRedraw_ = GL_TRUE;     //重绘＋动画
		} else {
         angle_ = 0.0;
         if (isAnimater_)                              
            isRedraw_ = GL_FALSE; //停止动画
		}
   }
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::motion(int _x, int _y) {
   if (button_==-1){
      printf("CTrakball: Trackball is defined with a mouse button!\n\n");
      exit(0);
   };
  
   if (isTracking_==GL_FALSE)  return;  //跟踪球不处在跟踪状态
  
   //跟踪球处在跟踪状态
   GLdouble currentPosition[3], dx, dy, dz;

   point2Vector(_x, _y, currentPosition);

   //calculate the angle to rotate by (directly proportional to the
   //length of the mouse movement 
   dx = currentPosition[0] - lastPosition_[0];
   dy = currentPosition[1] - lastPosition_[1];
   dz = currentPosition[2] - lastPosition_[2];
   angle_ = 90.0 * sqrt(dx*dx + dy*dy + dz*dz);

   //calculate the axis of rotation (cross product) 
   axis_[0] = lastPosition_[1] * currentPosition[2] - 
              lastPosition_[2] * currentPosition[1];
   axis_[1] = lastPosition_[2] * currentPosition[0] - 
              lastPosition_[0] * currentPosition[2];
   axis_[2] = lastPosition_[0] * currentPosition[1] - 
              lastPosition_[1] * currentPosition[0];

   //reset for next time 
   lastTime_ = glutGet(GLUT_ELAPSED_TIME);
   lastPosition_[0] = currentPosition[0];
   lastPosition_[1] = currentPosition[1];
   lastPosition_[2] = currentPosition[2];

   //remember to draw new Position 
   isRedraw_ =GL_TRUE;
	//glutPostRedisplay();
}


///////////////////////////////////////////////////////////////////////////////
bool Trackball::idle(void) {
   return (isAnimater_ && (!isButtonDown_));
}



} //namespace 


#endif  