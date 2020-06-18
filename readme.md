# Unity_OpenMesh_dll
Some unity project want use OpenMesh datastract, to rewrite OpenMesh datastract is almost impossible, so use dll to do that.

open DLL1_visualstudio to modify dll copy dll file to DLLtest_unity to test it.


## How to build openmesh dll to unity

### step 1
download openmesh source code.

### step 2 
use cmake to make VisualStudio format file.Configure selelct visualstudio version and **x64 platform** because unity is 64 bytes, and Generate. May have some error just ignore it.
![](https://i.imgur.com/toBko9E.png)
![](https://i.imgur.com/6GYqGht.png)

### step 3
open cmake made VisualStudio project and build it, It will generate two .lib file 
"OpenMeshCore.lib""OpenMeshTools.lib" in release x64 mode or "OpenMeshCored.lib""OpenMeshToolsd.lib" in debug x64 mode.

### step 4
create a VisualStudio dll project.

### step 5
copy two lib file and Openmesh sorce code Foler /src/OpenMesh/core /src/OpenMesh/Tools to VisualStudio dll project and **change project setting** ![](https://i.imgur.com/JTXuHJ2.png)
and add preprocessor define
```
_CRT_SECURE_NO_WARNINGS
_SCL_SECURE_NO_WARNINGS
_USE_MATH_DEFINES
NOMINMAX
_MBCS
```
![](https://i.imgur.com/SafxbQl.png)
and include them in you dll.h flie like this.
![](https://i.imgur.com/KU6KEBQ.png)
### step 6
write your owns API from OpenMesh to Unity in visualstudio dll project and build. This     will create  dll file.
a simple function API
    in dll.h file
![](https://i.imgur.com/sRGA6YA.png)
    in dll.c file
![](https://i.imgur.com/NvbluNX.png)

### step 7
create a unity project (I use unity2018.4.5.f1) add Plugins folder in Asstes floder and copy dll file to this folder you just create.

### step 8
create a C# script in unity and you can use dll file to use OpenMesh:D
![](https://i.imgur.com/VCz2iE5.png)