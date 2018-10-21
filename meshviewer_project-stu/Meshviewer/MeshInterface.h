/************************************************************************/
/* 
*Interface.h: interface functions are in this file
*By Wei Mingqiang (mingqiang.wei@gmail.com)
*16:23:29.2015.7.16
*All Rights Reserved                                                                    */
/************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef __WMQ_INTERFACE_H__
#define __WMQ_INTERFACE_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
///////////////////////////////////////////////////////////////////////////////
#include "Viewer\ViewerCallbacks.h" 
#include "Viewer\ViewerMenu.h"


///////////////////////////////////////////////////////////////////////////////
#include "mesh/extension/ExItems.h"
#include "mesh\extension/ExKernelT.cpp" 
#include "mesh\read_write/read_write.cpp" 
#include <string>

typedef MeshN::ExKernelT<MeshN::ExItems>   MyMesh;
typedef MeshN::ReaderWriterT<MyMesh>       Reader;


MyMesh  mesh;
Reader  reader(&mesh);

void MyMeshInit(void) { //

	std::string totalmodelname("./models/");
	std::string modelname;
	std::cout<<"Input model(just read .OFF file NOW):\n";
	std::cout<<"./models/";
	std::cin>>modelname;
	totalmodelname += modelname;

	reader.off_reader( totalmodelname.c_str() );
	mesh.meshInit();
	
/////////////模型显示/////////////////////
	 	glNewList(23, GL_COMPILE); 
	    reader.ogl_writer(0, 1); 
	 	glEndList();
///////////////////////////////////////////////

///////////////显示模型和面片法向////////////////

		glNewList(25, GL_COMPILE);
		reader.ogl_writer2(0, 1);
		glEndList();
//////////////////////////////////////////////

///////////////////三角网格去噪////////////////////////

		int choice;
		std::cout << "请选择一种去噪方法" << std::endl;
		std::cout << "数字 1 代表 Xianfang Sun 发表在 TVCG 上2007年的方法" << std::endl;
		std::cout << "数字 2 代表 Youyi Zheng 发表在 TVCG 上2011年的方法" << std::endl;
		std::cout << "数字 3 代表 你自己实现的某一种去噪方法" << std::endl;
		std::cout << "请输入数字(1-3): " << std::endl;
		std::cin >> choice;
		if (choice == 1)
			mesh.Mesh_Denoising_FE();//Sun et al.
		else if (choice == 2)
			mesh.Mesh_Denoising_YouyiZheng();
		else if (choice == 3)
			mesh.Laplacian_Smoothing();
		std::cout << "去噪执行完毕!!!" << std::endl;
		std::cout << "按 b 可以查看去噪结果" << std::endl;


	glNewList(24, GL_COMPILE);
	reader.ogl_writer(0, 1);
	glEndList();



	mesh.output_to_file();

}

namespace ViewerN {


	///////////////////////////////////////////////////////////////////////////////
	int addSubmenu(std::string _sub_menu_name) {   
		submenuName = std::string("To Do.."); 

		int submenu_ = glutCreateMenu(handleSubmenu);
		glutAddMenuEntry("No1",      0); //<<=== ?????? 
		glutAddMenuEntry("No2",      1); 

		return submenu_;
	}


	///////////////////////////////////////////////////////////////////////////////
	void handleSubmenu(int _item) {                
		switch (_item) { 
		case 0:  
			std::cout<<"No.0 is selected!\n"; break; 
		case 1:
			std::cout<<"No.1 is selected!\n"; break; 
		} 

		isListCreated = GL_FALSE;
	}


	///////////////////////////////////////////////////////////////////////////////
	void extKeyboard(int _k) {                     //???????
		std::cout<<(char)_k<<" is pressed! OK!!\n"; 

		switch ((char)_k) { 
		case 'u': //<<==== ????
			flag = 1; break; //<<==== ????
		case 'i': //<<==== ????
			flag = 2; break; //<<==== ????
		case 'o': //<<==== ????
			flag = 3; break; //<<==== ????
		case 'p': //<<==== ????
			flag = 4; break; //<<==== ????
		case 'm':
			flag = 5;
			break;
		case'b':
			flag = 6;
			break;
		case 'v':
			flag = 7;
			break;
		default:
			flag = 8;  
		}
		isListCreated = GL_FALSE; 
	}


	///////////////////////////////////////////////////////////////////////////////
	void drawingObject(void) {
		switch (flag ) {
		case 1:
			glutSolidCube(1.0f); break;
		case 2:
			glutSolidTorus(0.5f, 1.0, 30, 30); break;
		case 3:
			glutSolidSphere(1.0f, 30, 30); break;
		case 4:
			glutSolidTeapot(1.0f); break;
		case 5:
			glCallList(25);
			break;
		case 6:
			glCallList(24);
			break;
		case 7:
			glCallList(26);
			break;
		default: 

			glCallList(23); //glutSolidIcosahedron(); //<<======= ?????? 
		}
	}


} //namespace


#endif // 