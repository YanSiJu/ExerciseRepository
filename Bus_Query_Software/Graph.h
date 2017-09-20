
            /*  �ڽӱ�ĸ��ֲ���(14��)    */

        /*  ��������  */
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

           /*  ��������  */


            /*  �������u��ͼG��ĳ��������������,�򷵻ظö�������,���򷵻�-1  */
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


        /*  ���v��ͼG��ĳ��������,�򷵻ظö���  */
VerTexType   GetVex(MGraph  G,int   v)
{
            if(v >= G.vexnum  ||  v < 0)
                 exit(0);
            return   G.vexs[v];
}

            /* ���v��ͼG�еĶ���,����ö��㸳��ֵ:value  */
void   PutVex(MGraph  *G,VerTexType   v,VerTexType   value)
{
        int  k = LocateVex(*G,v);
        if(k < 0)
        {
            printf("������������\n");
            exit(0);
        }

        G->vexs[k] = value;
}


            /*  �󶥵�v�ĵ�һ���ڽӵ�
               �����ڵ�һ���ڽӵ�,�򷵻��ڽӵ�����
               ���򷵻�-1
            */
int   FirstAdjVex(MGraph   G,int  v)
{
        VRType   j = 0;
        if(v >= G.vexnum  ||   v < 0)       //�ж�v�Ƿ�Ϸ�
            exit(0);
        int   i;
      /*  if(v%2)        //��
            j = INFINITY;*/
        for(i=0;i<G.vexnum;i++)
        {
              if(G.arcs[v][i].adj  !=  j)
                     return  i;
        }
        return   -1;        //�������ڽӵ�,����-1
}



            /*
               w��v�ĵ�1���ڽӵ�,��v�ĵ�2���ڽӵ�
               �����ڵ�2���ڽӵ�,�򷵻������
               ���򷵻�-1
            */
int   NextAdjVex(MGraph   G,int  v,int   w)
{
        VRType   j = 0;
        if((v >= G.vexnum  ||  v < 0) ||  (w >= G.vexnum  ||  w < 0))       //�ж�v��w�Ƿ�Ϸ�
              exit(0);
        int      i;
        /*if(v%2)        //��
            j = INFINITY;*/
        for(i=w+1;i<G.vexnum;i++)
        {
              if(G.arcs[v][i].adj  !=  j)
                     return  i;
       }
        return   -1;        //�����ڵ�2���ڽӵ�,����-1
}



        /*  ��ͼ�в��붥��v  */
void  InsertVex(MGraph  *G,VerTexType  v)
{
            int  i;
            VRType    j = 0;
            if(G->kind % 2)       //��
                j = INFINITY;

            G->vexs[G->vexnum] = v;     //���¶�����붥������
            for(i = 0; i <= G->vexnum; i++)             //��ʼ�������С�������
            {
                G->arcs[G->vexnum][i].adj  = G->arcs[i][G->vexnum].adj = j;
                G->arcs[G->vexnum][i].info = G->arcs[i][G->vexnum].info = NULL;
             }
             G->vexnum++;           //��������1
}


        /*  ��v��w��ͼG�еĶ���,���컡<v,w>
            ���������ͼ,�򻹹��컡<w,v>
            */
void   InsertArc(MGraph  *G,VerTexType   v,VerTexType   w)
{
        int  v1,w1;
        VRType    j = 1;
        v1 = LocateVex(*G,v);           //��β(����1)�����
        w1 = LocateVex(*G,w);           //��ͷ(����2)�����
        if(v1 < 0 || w1 < 0)        //�ж�v1��w1�Ƿ�Ϸ�
            exit(0);
        if(G->kind % 2)       //��
        {
            printf("���������صľ���:");
            scanf("%d",&G->arcs[v1][w1].adj);
        }
        else
            G->arcs[v1][w1].adj = 1;

        if(G->kind > 1)     //����ͼ(��)
            G->arcs[w1][v1] = G->arcs[v1][w1];
        G->arcnum++;        //������1
}

            /*  ��ӡ�ڽӾ���  */
void    PrintMatrix(MGraph  G)
{
        int  i,j;
        printf("\t\t\t\t\t-----------------------�ڽӾ���------------------\n                      ");


        for(i=0;i<G.vexnum;i++)
        {

            for(j=0;j<G.vexnum;j++)
            {

                    if(INFINITY ==  G.arcs[i][j].adj)
                        printf("��   ");
                    else
                        printf("%d  ",G.arcs[i][j].adj);
                    if(j  ==   G.vexnum-1)
                        printf("\n                      ");
            }
        }

}


                /*
                    ���ͼ�д��ڻ�<v,w>,��ɾ��֮
                    ��������ͼ(��),��ɾ���Գƻ�<w,v>
                */
void    DeleteArc(MGraph  *G,VerTexType  v,VerTexType  w)
{
            int  v1,w1;
            VRType   j = 0;     //�����ϵ���ͣ�ͼ
            v1 = LocateVex(*G,v);       //����v��w�����
            w1 = LocateVex(*G,w);

            if((v1 >= G->vexnum  ||  v1 < 0) ||  (w1 >= G->vexnum  ||  w1 < 0))       //�ж�v1��w1�Ƿ�Ϸ�
                      {
                          printf("վ�������������������\n");
                      }

            if(G->kind % 2)                 //��
                  j = INFINITY;
            if(G->arcs[v1][w1].adj  != j)       //����л�����ɾ��
            {
                G->arcs[v1][w1].adj = j;            //�����ϵ��Ϊ������
                if(G->arcs[v1][w1].info)            // ����������Ϣ,�������Ϣָ����Ϊ��
                {
                    free(G->arcs[v1][w1].info);     //�ͷſռ�
                    G->arcs[v1][w1].info = NULL;
                }
                if(G->kind > 2)          //��Ϊ����,��ɾ���Գƻ�<w,v>
                      G->arcs[w1][v1] = G->arcs[v1][w1];
                G->arcnum--;                    //������1
            }

}


        /*  ������v������ͼG�У���ɾ������v��������صĻ�  */
void    DeleteVex(MGraph  *G,VerTexType   v)
{
     int  i,j,k;
     k = LocateVex(*G,v);                   //����v�����
     if(k < 0  ||   k  >=  G->vexnum)           //�ж�k�Ƿ�Ϸ�
        {
            printf("error\n");
            exit(0);                            //ͼ�в����ڶ���v
        }

     for(i = 0;i < G->vexnum;i++)
          DeleteArc(G,v,G->vexs[i]);        //ɾ���Ӷ���v�����Ļ�

     if(G->kind < 2)                        //��������ͼ����Ҫɾ��ָ�򶥵�v�Ļ�
     {
         for(i = 0;i< G->vexnum;i++)
            DeleteArc(G,G->vexs[i],v);
     }

     for(i = k+1;i< G->vexnum;i++)
           G->vexs[i-1] = G->vexs[i];       //ǰ�ƶ���v֮��Ķ���

     for(i = 0;i < G->vexnum;i++)               //���ƶ���v�ұߵľ���Ԫ��
        for(j = k+1;j < G->vexnum;j++)
            G->arcs[i][j-1]  = G->arcs[i][j];

     for(i = 0;i< G->vexnum;i++)           //���ƶ���v����ľ���Ԫ��
        for(j = k+1;j<G->vexnum;j++)
           G->arcs[j-1][i] = G->arcs[j][i];
      G->vexnum--;          //��������1
}

        /*  ����ͼG  */
void    DestroyGraph(MGraph  *G)
{
      int  i;
      for(i = G->vexnum-1;i >= 0;i--)         //�ɴ�С��һɾ��ÿ�����㼰������صĻ�
           DeleteVex(G,G->vexs[i]);
}

        /*  ������ȱ������еĶ���  */
void   DFSTraverse(MGraph  G)
{
      int  v;
      for(v = 0;v < G.vexnum;v++)
           Visited[v] = false;          //��ʼ����־��
      for(v = 0;v < G.vexnum;v++)       //�ӵ�1�����㿪ʼ����
      {
          if(!Visited[v])
            DFS(G,v);
      }

}



        /*  �ӵ�(v+1)�����㿪ʼ����  */
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


        /*  �Զ���v���в��� */
void visit(VerTexType    v)
{
        printf("%c   ",v.name);
}
