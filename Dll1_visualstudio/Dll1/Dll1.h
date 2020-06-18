#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "OpenMeshCore.lib")
#pragma comment(lib, "OpenMeshTools.lib")

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <glm/glm.hpp>
using namespace std;

extern "C" _declspec(dllexport)  int happyMesh(int a, float b, int c);
extern "C" _declspec(dllexport)  int  NotHappyMesh(void);
extern "C" _declspec(dllexport) bool InitOpenMeshModel();
extern "C" _declspec(dllexport)  int OpenMeshModel_returnPoint(void);

typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;


class MyMesh : public TriMesh
{
public:
	MyMesh();
	~MyMesh();

	void ClearMesh();
};

class GLMesh
{
public:
	GLMesh();
	~GLMesh();
	bool Init(std::string fileName);
	MyMesh mesh;
	bool LoadModel(std::string fileName);
};

class MeshObject
{
public:
	MeshObject();
	~MeshObject();
	bool Init(std::string fileName);

	GLMesh model;

};
