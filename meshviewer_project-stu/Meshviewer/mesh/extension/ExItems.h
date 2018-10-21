/////////////////////////////////////////////////////////////////////////////// 
#ifndef __WMQ_MESH_EXTENSION_ITEMS_H__
#define __WMQ_MESH_EXTENSION_ITEMS_H__ 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../core/InternalItems.h"
namespace MeshN {


	///////////////////////////////////////////////////////////////////////////////
	class ExItems : public MeshN::InternalItems{
	public:   
		struct Vertex : public MeshN::InternalItems::Vertex {  
			Normal   normal_; 

			//在此加其它需要的顶点属性
		};


		///===================================================
		struct Edge : public MeshN::InternalItems::Edge {
			Scalar   length_;

			//在此加其它需要的边属性
		};


		///===================================================
		struct Facet : public MeshN::InternalItems::Facet {

			Normal         normal_;//三角形法向 
			Coord          centroid_;//三角形重心
			Scalar         area_;//三角形面积
			//add others

		}; 

	};


} //namespace 


#endif

