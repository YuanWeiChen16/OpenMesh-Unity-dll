using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class move : MonoBehaviour
{
    public Vector3 MovePos;
    public Vector3 RealPos;
    public GameObject player;
    // Start is called before the first frame update
    void Start()
    {
        RealPos = this.GetComponent<Transform>().position;
    }
    void Update()
    {
        float dis = player.GetComponent<Transform>().position.z - this.GetComponent<Transform>().position.z;
        if (dis < 0)
        {
            dis = -dis;
        }

        if (dis < 4)
        {
            Vector3 temp = this.GetComponent<Transform>().position;
            if (temp.x < (RealPos + MovePos).x)
            {
                Vector3 tt = (MovePos + RealPos) - temp;
                temp.x += (Time.deltaTime * 5);
                this.GetComponent<Transform>().position = temp;
            }
        }

        if ((player.GetComponent<Transform>().position.z > 10)||((player.GetComponent<Transform>().position.z < -10)))
        {
            Vector3 temp = this.GetComponent<Transform>().position;
            if (temp.x > RealPos.x)
            {
                Vector3 tt = RealPos - temp;
                temp.x -= (Time.deltaTime * 5);
                this.GetComponent<Transform>().position = temp;
            }
        }
    }
}
