using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class dllTest : MonoBehaviour
{

    [DllImport("Dll1")]
    private static extern int happyMesh(int a, float b, int c);
    [DllImport("Dll1")]
    private static extern int NotHappyMesh();
    [DllImport("Dll1")]
    private static extern bool InitOpenMeshModel();
    [DllImport("Dll1")]
    private static extern int OpenMeshModel_returnPoint();

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(NotHappyMesh());
        Debug.Log(happyMesh(11,11,1));
        Debug.Log(NotHappyMesh());
        Debug.Log(happyMesh(10, 10, 0));
        Debug.Log(NotHappyMesh());
        Debug.Log(InitOpenMeshModel());
        Debug.Log(OpenMeshModel_returnPoint());

    }

    // Update is called once per frame
    void Update()
    {
       

    }
}
