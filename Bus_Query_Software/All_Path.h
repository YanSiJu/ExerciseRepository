 /*
        ������������㷨��
        */


#define INFINTITY       INT_MAX       // �������Զ��·������
#define TRUE 1
#define FALSE 0


   typedef struct Path
    {
        int size;
        int nodes[MAX_VERTEX_NUM];
    }Path;






void getPaths(int start,int end,int isNodeUsed[],struct Path paths[],int *pathsNum)
{
        int i,j;
        Path tempPaths[100];
        int tempPathsNum ;
        isNodeUsed[start] = 1;   // ��ǵ�ǰ��㲻����

        VRType  React = 0;
        if(G.kind % 2)
             React = INFINITY;
        for(i = 0;i < G.vexnum;i++)
        {
            // ��㲻��·���У��ҿ��Ե���
            if(isNodeUsed[i] == 0 && G.arcs[start][i].adj != React)
            {
            // ��ǰ�����ֱ�ӵ����յ�
                    if(i == end)
                    {
                        paths[(*pathsNum)].size = 2;
                        paths[(*pathsNum)].nodes[0] = end;
                        paths[(*pathsNum)].nodes[1] = start;
                        (*pathsNum)++;
                    }
                    else
                    {
                        // �ݹ����ӵ�ǰ��㵽���յ������·��
                        tempPathsNum = 0;
                       // printf("\nvexnum:%d   i:%d  \n",G.vexnum,i);
                        getPaths(i,end,isNodeUsed,tempPaths,&tempPathsNum);

                // �����ҵ��ģ��ӵ�ǰ��㵽���յ������·��
                            for(j=0;j<tempPathsNum;j++)
                            {
                        // �ڵ�ǰ��㵽���յ������·���У���ӵ�ǰ���
                                tempPaths[j].nodes[tempPaths[j].size] = start;
                                tempPaths[j].size ++;

                                // �ϲ������յ�·����
                                paths[(*pathsNum)] = tempPaths[j];
                                (*pathsNum)++;

                            }
                    }

            }
        }
        //printf("\nisNodeUsed[%d] ==  %d\n",start,);
       isNodeUsed[start] = 0;

}





