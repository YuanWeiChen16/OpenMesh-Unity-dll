// Dll1.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include "Dll1.h"

int adasdasdasd = 24;
MeshObject ThisMesh = MeshObject();

int happyMesh(int a, float b, int c)
{
	adasdasdasd =(int) a * b;
	return (int)(a * b + c);
}

int  NotHappyMesh(void)
{

	

	adasdasdasd = adasdasdasd / 2;
	return adasdasdasd;
}


bool InitOpenMeshModel()
{
	//string dest = fileName;
	return ThisMesh.Init("UnionSphere.obj");
}


int OpenMeshModel_returnPoint(void)
{

	return (int)ThisMesh.model.mesh.n_vertices();
}




//struct OpenMesh::VertexHandle const OpenMesh::PolyConnectivity::InvalidVertexHandle;

#pragma region MyMesh
MyMesh::MyMesh()
{
	request_vertex_normals();
	request_vertex_status();
	request_face_status();
	request_edge_status();
}
MyMesh::~MyMesh()
{

}
void MyMesh::ClearMesh()
{
	if (!faces_empty())
	{
		for (MyMesh::FaceIter f_it = faces_begin(); f_it != faces_end(); ++f_it)
		{
			delete_face(*f_it, true);
		}
		garbage_collection();
	}
}
#pragma endregion


#pragma region GLMesh

GLMesh::GLMesh()
{
}
GLMesh::~GLMesh()
{
}
bool GLMesh::Init(std::string fileName)
{
	if (LoadModel(fileName))
	{
		return true;
	}
	return false;
}

bool GLMesh::LoadModel(std::string fileName)
{
	OpenMesh::IO::Options ropt;
	if (OpenMesh::IO::read_mesh(mesh, fileName, ropt))
	{
		if (!ropt.check(OpenMesh::IO::Options::VertexNormal) && mesh.has_vertex_normals())
		{
			mesh.request_face_normals();
			mesh.update_normals();
			mesh.release_face_normals();
		}
		return true;
	}
	return false;
}
#pragma endregion

MeshObject::MeshObject()
{
}

MeshObject::~MeshObject()
{
}

bool MeshObject::Init(std::string fileName)
{
	return  model.Init(fileName);
}
