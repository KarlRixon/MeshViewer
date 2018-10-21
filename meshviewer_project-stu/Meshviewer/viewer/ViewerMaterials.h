///////////////////////////////////////////////////////////////////////////////
// Material.h: define a material class, which offers several common  materials.
// By Mingqiang Wei
// Initially written at Mar. 2001, and reviewed at May 2005.
// All rights Reserved. 
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef __WEI_VIEWER_MATERIAL_H__
#define __WEI_VIEWER_MATERIAL_H__


///////////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>


namespace ViewerN {


///////////////////////////////////////////////////////////////////////////////
//材质常量: 用于定义不同的材料属性
enum MaterialConst {
    MAT_NONE            = 0,  //无材质
    MAT_BRASS           = 1,  //黄铜色
    MAT_BRONZE          = 2,  //紫铜色
    MAT_POLISHED_BRONZE = 3,
    MAT_CHROME          = 4,
    MAT_COPPER          = 5,
    MAT_POLISHED_COPPER = 6,
    MAT_GOLD            = 7,  //金黄色
    MAT_POLISHED_GOLD   = 8,
    MAT_PEWTER          = 9,
    MAT_SLIVER          = 10, //银灰色
    MAT_POLISHED_SLIVER = 11,
    MAT_EMERALD         = 12, //翠绿色
    MAT_JADE            = 13,
    MAT_OBSIDIAN        = 14,
    MAT_PEARL           = 15, //淡紫色
    MAT_RUBY            = 16, //红宝石色
    MAT_TURQUOISE       = 17,
    MAT_BLACK_PLASTIC   = 18,
    MAT_BLACK_RUBBER    = 19
};


///////////////////////////////////////////////////////////////////////////////
/// 材质类
struct Material {
  void SetMaterial(int _material);
};



///////////////////////////////////////////////////////////////////////////////
// 材质类成员函数: 设置材质
void Material::SetMaterial(int _material) {
   GLfloat amb_[4], dif_[4], spe_[4], shin_;
   GLfloat memi[4] = {0, 0, 0, 0};

   switch (_material) {
   
	case MAT_NONE: {
	 amb_[0]=0.5f, amb_[1]=0.5f, amb_[2]=0.5f, amb_[3]=1.0f;  //ambient
     dif_[0]=0.5f, dif_[1]=0.5f, dif_[2]=0.5f, dif_[3]=1.0f;  //diffuse
     spe_[0]=0.5f, spe_[1]=0.5f, spe_[2]=0.5f, spe_[3]=1.0f;  //specular
     shin_ =40.0f;  //shininess
	  break;
	}

   case MAT_BRASS: {
	  amb_[0]=0.329412f, amb_[1]=0.223529f, amb_[2]=0.027451f, amb_[3]=1.0f;
     dif_[0]=0.780392f, dif_[1]=0.568627f, dif_[2]=0.113725f, dif_[3]=1.0f;
     spe_[0]=0.992157f, spe_[1]=0.941176f, spe_[2]=0.807843f, spe_[3]=1.0f;
     shin_ =27.897400f;
	  break;
	}
   
	case MAT_BRONZE: {
     amb_[0]=0.212500f, amb_[1]=0.127500f, amb_[2]=0.054000f, amb_[3]=1.0f;
     dif_[0]=0.714000f, dif_[1]=0.428400f, dif_[2]=0.181440f, dif_[3]=1.0f;
     spe_[0]=0.393548f, spe_[1]=0.271906f, spe_[2]=0.166721f, spe_[3]=1.0f;
     shin_ =25.600000f;
	  break;
	}
   
	case MAT_POLISHED_BRONZE: {
     amb_[0]=0.250000f, amb_[1]=0.148000f, amb_[2]=0.064750f, amb_[3]=1.0f;
     dif_[0]=0.400000f, dif_[1]=0.236800f, dif_[2]=0.103600f, dif_[3]=1.0f;
     spe_[0]=0.774597f, spe_[1]=0.458561f, spe_[2]=0.200621f, spe_[3]=1.0f;
     shin_ =76.800003f;
	  break;
	}
   
	case MAT_CHROME: {
     amb_[0]=0.250000f, amb_[1]=0.250000f, amb_[2]=0.250000f, amb_[3]=1.0f;
     dif_[0]=0.400000f, dif_[1]=0.400000f, dif_[2]=0.400000f, dif_[3]=1.0f,
     spe_[0]=0.774597f, spe_[1]=0.774597f, spe_[2]=0.774597f, spe_[3]=1.0f;
     shin_ =76.800003f;
	  break;
	}
   
	case MAT_COPPER: {
     amb_[0]=0.191250f, amb_[1]=0.073500f, amb_[2]=0.022500f, amb_[3]=1.0f;
     dif_[0]=0.703800f, dif_[1]=0.270480f, dif_[2]=0.082800f, dif_[3]=1.0f;
     spe_[0]=0.256777f, spe_[1]=0.137622f, spe_[2]=0.086014f, spe_[3]=1.0f;
     shin_ =12.800000f;
	  break;
	}
   
	case MAT_POLISHED_COPPER: {
     amb_[0]=0.229500f, amb_[1]=0.088250f, amb_[2]=0.027500f, amb_[3]=1.0f;
     dif_[0]=0.550800f, dif_[1]=0.211800f, dif_[2]=0.066000f, dif_[3]=1.0f;
     spe_[0]=0.580594f, spe_[1]=0.223257f, spe_[2]=0.069570f, spe_[3]=1.0f;
     shin_ =51.200001f;
	  break;
	}
   
	case MAT_GOLD: {
     amb_[0]=0.247250f, amb_[1]=0.199500f, amb_[2]=0.074500f, amb_[3]=1.0f;
     dif_[0]=0.751640f, dif_[1]=0.606480f, dif_[2]=0.226480f, dif_[3]=1.0f;
     spe_[0]=0.628281f, spe_[1]=0.555802f, spe_[2]=0.366065f, spe_[3]=1.0f;
     shin_ =51.200001f;
	  break;
	}
   
	case MAT_POLISHED_GOLD: {
     amb_[0]=0.247250f, amb_[1]=0.224500f, amb_[2]=0.064500f, amb_[3]=1.0f;
     dif_[0]=0.346150f, dif_[1]=0.314300f, dif_[2]=0.090300f, dif_[3]=1.0f;
     spe_[0]=0.797357f, spe_[1]=0.723991f, spe_[2]=0.208006f, spe_[3]=1.0f;
     shin_ =83.199997f;
	  break;
	}
   
	case MAT_PEWTER: {
     amb_[0]=0.105882f, amb_[1]=0.058824f, amb_[2]=0.113725f, amb_[3]=1.0f;
     dif_[0]=0.427451f, dif_[1]=0.470588f, dif_[2]=0.541176f, dif_[3]=1.0f;
     spe_[0]=0.333333f, spe_[1]=0.333333f, spe_[2]=0.521569f, spe_[3]=1.0f;
     shin_ =9.846150f;
	  break;
	}
   
	case MAT_SLIVER: {
     amb_[0]=0.192250f, amb_[1]=0.192250f, amb_[2]=0.192250f, amb_[3]=1.0f;
     dif_[0]=0.507540f, dif_[1]=0.507540f, dif_[2]=0.507540f, dif_[3]=1.0f;
     spe_[0]=0.508273f, spe_[1]=0.508273f, spe_[2]=0.508273f, spe_[3]=1.0f;
     shin_ =51.200001f;
     break;
	}
   
	case MAT_POLISHED_SLIVER: {
     amb_[0]=0.231250f, amb_[1]=0.231250f, amb_[2]=0.231250f, amb_[3]=1.0f;
     dif_[0]=0.277500f, dif_[1]=0.277500f, dif_[2]=0.277500f, dif_[3]=1.0f;
     spe_[0]=0.773911f, spe_[1]=0.773911f, spe_[2]=0.773911f, spe_[3]=1.0f;
     shin_ =89.599998f;
	  break;
	}
   
	case MAT_EMERALD: {
     amb_[0]=0.021500f, amb_[1]=0.174500f, amb_[2]=0.021500f, amb_[3]=0.55f;
     dif_[0]=0.075680f, dif_[1]=0.614240f, dif_[2]=0.075680f, dif_[3]=0.55f;
     spe_[0]=0.633000f, spe_[1]=0.727811f, spe_[2]=0.633000f, spe_[3]=0.55f;
     shin_ =76.800003f;
	  break;
	}
   
	case MAT_JADE: {
     amb_[0]=0.135000f, amb_[1]=0.222500f, amb_[2]=0.157500f, amb_[3]=0.95f;
     dif_[0]=0.540000f, dif_[1]=0.890000f, dif_[2]=0.630000f, dif_[3]=0.95f;
     spe_[0]=0.316228f, spe_[1]=0.316228f, spe_[2]=0.316228f, spe_[3]=0.95f;
     shin_ =12.800000f;
	  break;
	}
   
	case MAT_OBSIDIAN: {
     amb_[0]=0.053750f, amb_[1]=0.050000f, amb_[2]=0.066250f, amb_[3]=0.82f;
     dif_[0]=0.182750f, dif_[1]=0.170000f, dif_[2]=0.225250f, dif_[3]=0.82f;
     spe_[0]=0.332741f, spe_[1]=0.328634f, spe_[2]=0.346435f, spe_[3]=0.82f;
     shin_ =38.400002f;
	  break;
	
	}
   
	case MAT_PEARL: {
     amb_[0]=0.250000f, amb_[1]=0.207250f, amb_[2]=0.207250f, amb_[3]=0.922f;
     dif_[0]=1.000000f, dif_[1]=0.829000f, dif_[2]=0.829000f, dif_[3]=0.922f;
     spe_[0]=0.296648f, spe_[1]=0.296648f, spe_[2]=0.296648f, spe_[3]=0.922f;
     shin_ =11.264000f;
	  break;
	}
   
	case MAT_RUBY: {
     amb_[0]=0.174500f, amb_[1]=0.011750f, amb_[2]=0.011750f, amb_[3]=0.55f;
     dif_[0]=0.614240f, dif_[1]=0.041360f, dif_[2]=0.041360f, dif_[3]=0.55f;
     spe_[0]=0.727811f, spe_[1]=0.626959f, spe_[2]=0.626959f, spe_[3]=0.55f;
     shin_ =76.800003f;
	  break; }
   
	case MAT_TURQUOISE: {
     amb_[0]=0.100000f, amb_[1]=0.187250f, amb_[2]=0.174500f, amb_[3]=0.8f;
     dif_[0]=0.396000f, dif_[1]=0.741510f, dif_[2]=0.691020f, dif_[3]=0.8f;
     spe_[0]=0.297254f, spe_[1]=0.308290f, spe_[2]=0.306678f, spe_[3]=0.8f;
     shin_ =12.800000f;
	  break;
	}
   
	case MAT_BLACK_PLASTIC: {
     amb_[0]=0.000000f, amb_[1]=0.000000f, amb_[2]=0.000000f, amb_[3]=1.0f;
     dif_[0]=0.010000f, dif_[1]=0.010000f, dif_[2]=0.010000f, dif_[3]=1.0f;
     spe_[0]=0.500000f, spe_[1]=0.500000f, spe_[2]=0.500000f, spe_[3]=1.0f;
     shin_ =32.000000f;
	  break;
	}
   
	case MAT_BLACK_RUBBER: {
     amb_[0]=0.020000f, amb_[1]=0.020000f, amb_[2]=0.020000f, amb_[3]=1.0f;
     dif_[0]=0.010000f, dif_[1]=0.010000f, dif_[2]=0.010000f, dif_[3]=1.0f;
     spe_[0]=0.400000f, spe_[1]=0.400000f, spe_[2]=0.400000f, spe_[3]=1.0f;
     shin_ =10.000000f;
	  break;
	}
   
	default:
	  amb_[0]=0.021500f, amb_[1]=0.174500f, amb_[2]=0.021500f, amb_[3]=0.55f;
     dif_[0]=0.075680f, dif_[1]=0.614240f, dif_[2]=0.075680f, dif_[3]=0.55f;
     spe_[0]=0.633000f, spe_[1]=0.727811f, spe_[2]=0.633000f, spe_[3]=0.55f;
     shin_  = 76.800003f;
   };
   
   glMaterialfv(GL_FRONT, GL_AMBIENT, amb_); 
   glMaterialfv(GL_FRONT, GL_DIFFUSE, dif_); 
   glMaterialfv(GL_FRONT, GL_SPECULAR, spe_);
   glMaterialfv(GL_FRONT, GL_EMISSION, memi);
   glMaterialf(GL_FRONT,  GL_SHININESS, shin_); 
}


} //namespace



#endif 