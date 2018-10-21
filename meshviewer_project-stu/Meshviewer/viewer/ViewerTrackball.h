///////////////////////////////////////////////////////////////////////////////
// Trackball.h: a very simple trackball class.
// By Mingqiang Wei
// Initially written at Mar. 2001, and reviewed at May 2005.
// All rights Reserved. 
//-----------------------------------------------------------------------------
// Usage:
//  o  init()���κ���������֮ǰ����
//  o  reshape()��reshape�ص������е���
//  o  matrix()�õ����������ת����
//  o  startMotion()����������
//  o  stopMotion()ʹ������������
//  o  motion()������˶��ص������е���֮
//  o  animate(GL_TRUE)���ϣ�����ɿ���������ת�������֮
//  o  animate(GL_FALSE)���ϣ�����ɿ�����ת�����֮
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
/// ��ʵ��
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//���캯�� 
Trackball::Trackball(void) : isButtonDown_(GL_FALSE), angle_(0.0),  
   button_(-1), isTracking_(GL_FALSE), isAnimater_(GL_TRUE)
{}


///////////////////////////////////////////////////////////////////////////////
//����Ļ��һ���Ϊ�������ϵĵ� 
void Trackball::point2Vector(double _x, double _y, double _v[3]) { 
   //project x, y onto a hemi-sphere centered within width, height. 
   _v[0] = (2.0*_x - width_) / width_;    //�����ӿڲ�������x(in [-1..1])
   _v[1] = (height_ - 2.0*_y) / height_;  //��y
   double d_ = sqrt(_v[0]*_v[0] + _v[1]*_v[1]);   //����
   _v[2] = cos(sqrt(2.0)*3.1415926/4.0*d_); 
	       //cos((3.14159265 / 2.0) * ((d_< 1.0) ? d_ : 1.0));  
   double a_ = 1.0 / sqrt(_v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2]);
   _v[0] *= a_;      //��λ��
   _v[1] *= a_;
   _v[2] *= a_;
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::animate(bool _animate) {
   isAnimater_ = _animate;
}


///////////////////////////////////////////////////////////////////////////////
//��ʼ�������� 
void Trackball::init(unsigned _button) {
   button_ = _button;     //�����������ٵ�����
   angle_  = 0.0;         //��ת����0

   axis_[0] = axis_[1] = axis_[2] = 0.0;
   //put the identity in the trackball transform 
   glPushMatrix();
   glLoadIdentity();      //���ۼ���ת��Ϊ��λ����
   glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)transform_);
   glPopMatrix();
}


///////////////////////////////////////////////////////////////////////////////
//��GL״̬����ǰ�任����ʩ������˶����������ת 
void Trackball::matrix(void) {
   glPushMatrix();
   glLoadIdentity();   //��������������ת
   glRotatef(angle_, axis_[0], axis_[1], axis_[2]);
   glMultMatrixf((GLfloat*)transform_);  //���ȥ����ת�����е��� 
   glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)transform_); //���յ���ת��
   glPopMatrix();

   glMultMatrixf((GLfloat*)transform_);  //�Ե�ǰ�任����ʩ���ۻ���ת��
}


///////////////////////////////////////////////////////////////////////////////
/// �����ӿڲ��� 
void Trackball::reshape(int _width, int _height) {
   width_  = _width;    //�����ӿڲ���
   height_ = _height;   //Ҫ��Ҫ���¼��������,����ú��о�..... ��:No!!
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::mouse(int _button, int _state, int _x, int _y) {
   //�������������������£�...; 
   if (_state == GLUT_DOWN && _button == button_){
   	isButtonDown_ = GL_TRUE;
	   //����Ļ�ϵ���ʼ���Ϊ�������ϵĵ�
      isTracking_ = GL_TRUE;      //���ٿ�ʼ��Ҳ
      lastTime_ = glutGet(GLUT_ELAPSED_TIME); //��¼�¿�ʼʱ��ʱ��
      point2Vector(_x, _y, lastPosition_);    //����Ļʼ���Ϊ�������ϵĵ�
   } else if (_state == GLUT_UP && _button == button_) { //������....
	   isButtonDown_ = GL_FALSE;
      isTracking_   = GL_FALSE;   //������ 
      if (lastTime_==(GLuint)glutGet(GLUT_ELAPSED_TIME) && isAnimater_) {
  	      isRedraw_ = GL_TRUE;     //�ػ棫����
		} else {
         angle_ = 0.0;
         if (isAnimater_)                              
            isRedraw_ = GL_FALSE; //ֹͣ����
		}
   }
}


///////////////////////////////////////////////////////////////////////////////
void Trackball::motion(int _x, int _y) {
   if (button_==-1){
      printf("CTrakball: Trackball is defined with a mouse button!\n\n");
      exit(0);
   };
  
   if (isTracking_==GL_FALSE)  return;  //�����򲻴��ڸ���״̬
  
   //�������ڸ���״̬
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