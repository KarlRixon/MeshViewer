
#ifndef __WMQ_MESH_EXTENSION_KERNEL_H__
#define __WMQ_MESH_EXTENSION_KERNEL_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////
//#include "../core/KernelT.h" 
#include "../core/KernelT.cpp" 
//#include "kdtree\KdTree.h"//�����������ڵ㣬ʱ�临�Ӷ�Ϊ(nlogn)
//#include "pointset\PointSet.h"
//#include "NumericalC\simMatrix4.h"
//#include "NumericalC\jacobi.h"
//#include "NumericalC\SVD.h"
//#include "NumericalC\GaussianNoise3.h"
#include "time.h"

#define   weimq_e 2.71828
namespace MeshN { 

	template <class ExItems>
	class ExKernelT : public MeshN::KernelT<ExItems> {
	public:  
		typedef typename MeshN::KernelT<ExItems>       Kernel; 
		typedef typename ExKernelT<ExItems>            This; 

		typedef typename Kernel::Scalar            Scalar;
		typedef typename Kernel::Coord             Coord;
		typedef typename Kernel::Normal            Normal;  
		typedef typename Kernel::Color             Color;
		typedef typename Kernel::TexCoord          TexCoord;

		typedef typename Kernel::Halfedge          Halfedge;
		typedef typename Kernel::Vertex            Vertex;
		typedef typename Kernel::Edge              Edge;
		typedef typename Kernel::Facet             Facet;

		typedef typename Kernel::HalfedgeHandle    HalfedgeHandle;
		typedef typename Kernel::VertexHandle      VertexHandle;
		typedef typename Kernel::EdgeHandle        EdgeHandle;
		typedef typename Kernel::FacetHandle       FacetHandle; 

		typedef typename Kernel::VertexHandles     VertexHandles;
		typedef typename Kernel::EdgeHandles       EdgeHandles;
		typedef typename Kernel::FacetHandles      FacetHandles;

		typedef typename Kernel::VertexIterator       VertexIterator;
		typedef typename Kernel::EdgeIterator         EdgeIterator;
		typedef typename Kernel::FacetIterator        FacetIterator; 
		typedef typename Kernel::ConstVertexIterator  ConstVertexIterator;
		typedef typename Kernel::ConstEdgeIterator    ConstEdgeIterator;
		typedef typename Kernel::ConstFacetIterator   ConstFacetIterator; 

	public:
		ExKernelT();
		~ExKernelT();

	public:
		
		Scalar calc_facet_area(const FacetHandle& _fh);//����һ��������Ƭ�������������, 

		inline Normal calc_normal(const VertexHandle& _vh);//////���㶥��ķ���ֵ

		void Laplacian_Smoothing();/////////////////////////////////////////////////ʵ��һ����������ȥ���㷨

		void mesh_process();///////////////////////////////////////////////////////(��ѡ��������������ʵ��һ�ֲ���������������ȡ������ָ����������εȵ�)
		

	public: 
		// normals of facets
		inline Normal normal(const FacetHandle& _fh);////get the normal from _fh
		inline Normal calc_normal(const FacetHandle& _fh);/////calculate the normal for _fh
        void   update_facet_normals(void);


		// normals of vertices
		inline Normal normal(const VertexHandle& _vh);///////get the normal from _vh

		inline Normal calc_normal_max(const VertexHandle& _vh);
		
		void   update_vertex_normals(void);//////�������ж���ķ���ֵ

		void   update_vertex_normals_max(void);

		void   update_area();/////��������������Ƭ�����
		Scalar get_area(const FacetHandle& _fh);


		Coord calc_centroid(const FacetHandle& _fh);//����������Ƭ������

		void   update_normals(void);

		//edge length...
		double calc_edge_length(const EdgeHandle& _eh);
		void update_edge_length(void);

		void output_to_file();
		void getNeighborRing(VertexHandle& _vh, int _ring, std::vector<VertexHandle>& _vhs);//ȡ�����ring �������е�
		void getNeighborFaceN1(FacetHandle& _fh, std::vector<FacetHandle>& _fhs);//getting faces sharing edges with _fh
		void getNeighborFaceN2(FacetHandle& _fh, std::vector<FacetHandle>& _fhs);//getting faces sharing common vertices with _fh

		



///////////////����Ϊ������������ȥ���㷨//////////////////////////////////////////////
		void adjustFaceNormal_FE();//����Sun Xianfang TVCG2007���������淨��
		void adjustFaceNormal_YouyiZheng();//Based on Youyi Zheng TVCG 2011

		void Mesh_Denoising_FE();//Xianfang Sun, TVCG2007, fast and effective feature-preserving mesh denoising
		void Mesh_Denoising_YouyiZheng();//Based on Youyi Zheng TVCG 2011
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		void meshInit();
	public:
		// ������Ա�������ڴ˴�

		bool has_Normal(){return isNormal_;}
		void set_isNormal(bool tf){isNormal_ = tf;}
		bool has_Area(){return isArea_;}
		void set_isArea(bool tf){isArea_ = tf;}

	private:
		//KdTree* kdtree_;
		//PointSet* ps_;
		bool isNormal_;
		bool isArea_;
	};

} /// namespace

#endif



