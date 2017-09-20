
            /*  邻接表的各种操作(14个)    */

        /*  函数声明  */
int     LocateVex(MGraph   G,VerTexType   u);
void    PutVex(MGraph  *G,VerTexType   v,VerTexType   value);
void    InsertVex(MGraph  *G,VerTexType  v);
void    InsertArc(MGraph  *G,VerTexType   v,VerTexType   w);
void    DeleteArc(MGraph  *G,VerTexType  v,VerTexType  w);
void    DeleteVex(MGraph  *G,VerTexType   v);
void    PrintMatrix(MGraph  G);
VerTexType      GetVex(MGraph  G,int   v);
VerTexType      GetVex(MGraph  G,int   v);
void    DFS(MGraph   G,int   v);
void    DFSTraverse(MGraph  G);
void visit(VerTexType    v);

            bool   Visited[MAX_VERTEX_NUM];

           /*  函数定义  */


            /*  如果顶点u和图G中某顶点有相似特征,则返回该顶点的序号,否则返回-1  */
int   LocateVex(MGraph   G,VerTexType   u)
{
     int  i;
     for(i=0;i<G.vexnum;i++)
     {
         if(!strcmp(u.name,G.vexs[i].name))
              return  i;
     }
     return  -1;
}


        /*  如果v是图G中某顶点的序号,则返回该顶点  */
VerTexType   GetVex(MGraph  G,int   v)
{
            if(v >= G.vexnum  ||  v < 0)
                 exit(0);
            return   G.vexs[v];
}

            /* 如果v是图G中的顶点,则给该顶点赋新值:value  */
void   PutVex(MGraph  *G,VerTexType   v,VerTexType   value)
{
        int  k = LocateVex(*G,v);
        if(k < 0)
        {
            printf("您的输入有误\n");
            exit(0);
        }

        G->vexs[k] = value;
}


            /*  求顶点v的第一个邻接点
               若存在第一个邻接点,则返回邻接点的序号
               否则返回-1
            */
int   FirstAdjVex(MGraph   G,int  v)
{
        VRType   j = 0;
        if(v >= G.vexnum  ||   v < 0)       //判断v是否合法
            exit(0);
        int   i;
      /*  if(v%2)        //网
            j = INFINITY;*/
        for(i=0;i<G.vexnum;i++)
        {
              if(G.arcs[v][i].adj  !=  j)
                     return  i;
        }
        return   -1;        //不存在邻接点,返回-1
}



            /*
               w是v的第1个邻接点,求v的第2个邻接点
               若存在第2个邻接点,则返回其序号
               否则返回-1
            */
int   NextAdjVex(MGraph   G,int  v,int   w)
{
        VRType   j = 0;
        if((v >= G.vexnum  ||  v < 0) ||  (w >= G.vexnum  ||  w < 0))       //判断v和w是否合法
              exit(0);
        int      i;
        /*if(v%2)        //网
            j = INFINITY;*/
        for(i=w+1;i<G.vexnum;i++)
        {
              if(G.arcs[v][i].adj  !=  j)
                     return  i;
       }
        return   -1;        //不存在第2个邻接点,返回-1
}



        /*  向图中插入顶点v  */
void  InsertVex(MGraph  *G,VerTexType  v)
{
            int  i;
            VRType    j = 0;
            if(G->kind % 2)       //网
                j = INFINITY;

            G->vexs[G->vexnum] = v;     //将新顶点加入顶点向量
            for(i = 0; i <= G->vexnum; i++)             //初始化新增行、新增列
            {
                G->arcs[G->vexnum][i].adj  = G->arcs[i][G->vexnum].adj = j;
                G->arcs[G->vexnum][i].info = G->arcs[i][G->vexnum].info = NULL;
             }
             G->vexnum++;           //顶点数加1
}


        /*  若v和w是图G中的顶点,则构造弧<v,w>
            如果是无向图,则还构造弧<w,v>
            */
void   InsertArc(MGraph  *G,VerTexType   v,VerTexType   w)
{
        int  v1,w1;
        VRType    j = 1;
        v1 = LocateVex(*G,v);           //弧尾(顶点1)的序号
        w1 = LocateVex(*G,w);           //弧头(顶点2)的序号
        if(v1 < 0 || w1 < 0)        //判断v1和w1是否合法
            exit(0);
        if(G->kind % 2)       //网
        {
            printf("请输入两地的距离:");
            scanf("%d",&G->arcs[v1][w1].adj);
        }
        else
            G->arcs[v1][w1].adj = 1;

        if(G->kind > 1)     //无向图(网)
            G->arcs[w1][v1] = G->arcs[v1][w1];
        G->arcnum++;        //弧数加1
}

            /*  打印邻接矩阵  */
void    PrintMatrix(MGraph  G)
{
        int  i,j;
        printf("\t\t\t\t\t-----------------------邻接矩阵------------------\n                      ");


        for(i=0;i<G.vexnum;i++)
        {

            for(j=0;j<G.vexnum;j++)
            {

                    if(INFINITY ==  G.arcs[i][j].adj)
                        printf("∞   ");
                    else
                        printf("%d  ",G.arcs[i][j].adj);
                    if(j  ==   G.vexnum-1)
                        printf("\n                      ");
            }
        }

}


                /*
                    如果图中存在弧<v,w>,则删除之
                    若是无向图(网),则还删除对称弧<w,v>
                */
void    DeleteArc(MGraph  *G,VerTexType  v,VerTexType  w)
{
            int  v1,w1;
            VRType   j = 0;     //顶点关系类型：图
            v1 = LocateVex(*G,v);       //顶点v、w的序号
            w1 = LocateVex(*G,w);

            if((v1 >= G->vexnum  ||  v1 < 0) ||  (w1 >= G->vexnum  ||  w1 < 0))       //判断v1和w1是否合法
                      {
                          printf("站点输入错误，请重新输入\n");
                      }

            if(G->kind % 2)                 //网
                  j = INFINITY;
            if(G->arcs[v1][w1].adj  != j)       //如果有弧，则删除
            {
                G->arcs[v1][w1].adj = j;            //顶点关系置为不相邻
                if(G->arcs[v1][w1].info)            // 如果有相关信息,则将相关信息指针置为空
                {
                    free(G->arcs[v1][w1].info);     //释放空间
                    G->arcs[v1][w1].info = NULL;
                }
                if(G->kind > 2)          //若为无向,还删除对称弧<w,v>
                      G->arcs[w1][v1] = G->arcs[v1][w1];
                G->arcnum--;                    //弧数减1
            }

}


        /*  若顶点v存在于图G中，则删除顶点v及与其相关的弧  */
void    DeleteVex(MGraph  *G,VerTexType   v)
{
     int  i,j,k;
     k = LocateVex(*G,v);                   //顶点v的序号
     if(k < 0  ||   k  >=  G->vexnum)           //判断k是否合法
        {
            printf("error\n");
            exit(0);                            //图中不存在顶点v
        }

     for(i = 0;i < G->vexnum;i++)
          DeleteArc(G,v,G->vexs[i]);        //删除从顶点v出发的弧

     if(G->kind < 2)                        //若是有向图，则还要删除指向顶点v的弧
     {
         for(i = 0;i< G->vexnum;i++)
            DeleteArc(G,G->vexs[i],v);
     }

     for(i = k+1;i< G->vexnum;i++)
           G->vexs[i-1] = G->vexs[i];       //前移顶点v之后的顶点

     for(i = 0;i < G->vexnum;i++)               //左移顶点v右边的矩阵元素
        for(j = k+1;j < G->vexnum;j++)
            G->arcs[i][j-1]  = G->arcs[i][j];

     for(i = 0;i< G->vexnum;i++)           //上移顶点v下面的矩阵元素
        for(j = k+1;j<G->vexnum;j++)
           G->arcs[j-1][i] = G->arcs[j][i];
      G->vexnum--;          //顶点数减1
}

        /*  销毁图G  */
void    DestroyGraph(MGraph  *G)
{
      int  i;
      for(i = G->vexnum-1;i >= 0;i--)         //由大到小逐一删除每个顶点及与其相关的弧
           DeleteVex(G,G->vexs[i]);
}

        /*  深度优先遍历所有的顶点  */
void   DFSTraverse(MGraph  G)
{
      int  v;
      for(v = 0;v < G.vexnum;v++)
           Visited[v] = false;          //初始化标志域
      for(v = 0;v < G.vexnum;v++)       //从第1个顶点开始遍历
      {
          if(!Visited[v])
            DFS(G,v);
      }

}



        /*  从第(v+1)个顶点开始遍历  */
void  DFS(MGraph   G,int   v)
{
      int  w;
      Visited[v] = true;
      visit(G.vexs[v]);
      for(w = FirstAdjVex(G,v);w >= 0;w = NextAdjVex(G,v,w))
      {
           if(!Visited[w])
                DFS(G,w);
      }
}


        /*  对顶点v进行操作 */
void visit(VerTexType    v)
{
        printf("%c   ",v.name);
}
