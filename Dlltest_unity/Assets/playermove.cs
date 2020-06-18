using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playermove : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.A))
        {
            Vector3 tempV =this.GetComponent<Transform>().position;
            tempV.z -= 0.1f;
            Debug.Log("enter A");
            this.GetComponent<Transform>().position = tempV;
        }
        if (Input.GetKey(KeyCode.D))
        {
            Vector3 tempV = this.GetComponent<Transform>().position;
            tempV.z += 0.1f;
            Debug.Log("enter D");
            this.GetComponent<Transform>().position = tempV;
        }
    }
}
