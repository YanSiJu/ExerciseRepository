

typedef  VRType   ShortPathTable[  MAX_VERTEX_NUM ];            //最短距离表,一维数组
typedef  bool  PathMatrix[  MAX_VERTEX_NUM ][  MAX_VERTEX_NUM ];        //路径矩阵,二维数组

void   ShortestPath_DIJ(MGraph  G,int  v0,PathMatrix   p,ShortPathTable  D)
{   //用Dijkstra算法求有向网的顶点v0到其余顶点v的最短路径p[v]及带权长度D[v]
    //若p[v][w]为true,则w是从v0到v当前求得最短路径上的顶点
    //final[v]为true,即已经求得从v0到v的最短路径


            int i,j,k,v,w;
            VRType  min;
            bool  final[  MAX_VERTEX_NUM ];
                    //辅助矩阵,为真表示v0到该顶点的距离已经求出,初值为假

            for(v = 0;v < G.vexnum;v++)
            {
               final[v] = false;       //设初值
                D[v] = G.arcs[v0][v].adj;   //D[]存放v0到v的最短距离,初始值为v0到v的直接距离
               for(w = 0;w < G.vexnum;w++)
                    p[v][w] = false;        //路径初始化为空
                if(D[v] < INFINITY)      //v0到v有直接路径
                    p[v][v0] = p[v][v] = true;
                    //一维数组p[v][]存放v0到v的最短距离经过的顶点,目前仅有两个顶点 v0 和 v
            }

            final[v0] = true;       //源点v0并入S集
            D[v0] = 0;      //v0到v0的距离为0

          for(i = 1;i < G.vexnum;i++)        //对于其余 G.vexnum - 1 个顶点
         {
             //开始主循环,每次求得v0到某个顶点v的最短路径,并将v并入S集
                min = INFINITY;     //目前所知离v0最近的顶点的距离,初值为∞
                for(w = 0;w < G.vexnum;w++)     //检查所有顶点
                {
                    //在S集之外的顶点(final[] == false)中,找离v0最近的顶点,并将其序号赋给v,距离赋给min
                    if(!final[w] && D[w] < min)
                    {
                            min = D[w];     //最短的距离
                            v = w;      //在S集之外且离v0最近的顶点的序号
                    }
                }

                final[v] = true;        //将v并入S集

                for(w = 0;w < G.vexnum;w++)
                {
                        //根据新并入的顶点,更新不在S集的顶点到v0的距离和路径数组
                    if(!final[w] && min < INFINITY && G.arcs[v][w].adj < INFINITY &&
                        (min + G.arcs[v][w].adj < D[w]))
                    {
                         //w不属于S集且 v0→v→w 的距离 < 目前 v0→w 的距离

                        D[w] = min + G.arcs[v][w].adj;      //更新D[w]

                            //更新p[w],v0到w经过的顶点包括v0到v经过的顶点加上 w
                        for(j = 0;j < G.vexnum;j++)
                            p[w][j] = p[v][j];
                        p[w][w] = true;
                    }
                }
         }


}




void  MakePath(MGraph G,bool Path[],int  i,int  j,int a[MAX_VERTEX_NUM],int *size)
{
        VRType  min;
        int  MinNum,k,begin = i;
        Path[begin] = false;
        while(begin != j)
        {
            min = INFINITY;
            for(k = 0;k < G.vexnum;k++)
            {
                if(G.arcs[begin][k].adj < min && Path[k])
                {
                    min = G.arcs[begin][k].adj;
                    MinNum = k;
                }
            }
            if(INFINITY == min)
                break;

            //printf("%s",G.vexs[MinNum].name);

             a[*size] = MinNum;
            (*size)++;

           /* if(MinNum != j)
                printf("→");*/

            begin = MinNum;
            Path[MinNum] = false;
        }
        printf("\n");

}
