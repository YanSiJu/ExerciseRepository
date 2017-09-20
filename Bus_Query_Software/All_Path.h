 /*
        深度优先搜索算法。
        */


#define INFINTITY       INT_MAX       // 标记无穷远的路径长度
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
        isNodeUsed[start] = 1;   // 标记当前起点不可用

        VRType  React = 0;
        if(G.kind % 2)
             React = INFINITY;
        for(i = 0;i < G.vexnum;i++)
        {
            // 结点不在路径中，且可以到达
            if(isNodeUsed[i] == 0 && G.arcs[start][i].adj != React)
            {
            // 当前起点能直接到达终点
                    if(i == end)
                    {
                        paths[(*pathsNum)].size = 2;
                        paths[(*pathsNum)].nodes[0] = end;
                        paths[(*pathsNum)].nodes[1] = start;
                        (*pathsNum)++;
                    }
                    else
                    {
                        // 递归计算从当前起点到达终点的所有路径
                        tempPathsNum = 0;
                       // printf("\nvexnum:%d   i:%d  \n",G.vexnum,i);
                        getPaths(i,end,isNodeUsed,tempPaths,&tempPathsNum);

                // 处理找到的，从当前起点到达终点的所有路径
                            for(j=0;j<tempPathsNum;j++)
                            {
                        // 在当前起点到达终点的所有路径中，添加当前起点
                                tempPaths[j].nodes[tempPaths[j].size] = start;
                                tempPaths[j].size ++;

                                // 合并到最终的路径中
                                paths[(*pathsNum)] = tempPaths[j];
                                (*pathsNum)++;

                            }
                    }

            }
        }
        //printf("\nisNodeUsed[%d] ==  %d\n",start,);
       isNodeUsed[start] = 0;

}





