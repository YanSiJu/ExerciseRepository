

typedef  VRType   ShortPathTable[  MAX_VERTEX_NUM ];            //��̾����,һά����
typedef  bool  PathMatrix[  MAX_VERTEX_NUM ][  MAX_VERTEX_NUM ];        //·������,��ά����

void   ShortestPath_DIJ(MGraph  G,int  v0,PathMatrix   p,ShortPathTable  D)
{   //��Dijkstra�㷨���������Ķ���v0�����ඥ��v�����·��p[v]����Ȩ����D[v]
    //��p[v][w]Ϊtrue,��w�Ǵ�v0��v��ǰ������·���ϵĶ���
    //final[v]Ϊtrue,���Ѿ���ô�v0��v�����·��


            int i,j,k,v,w;
            VRType  min;
            bool  final[  MAX_VERTEX_NUM ];
                    //��������,Ϊ���ʾv0���ö���ľ����Ѿ����,��ֵΪ��

            for(v = 0;v < G.vexnum;v++)
            {
               final[v] = false;       //���ֵ
                D[v] = G.arcs[v0][v].adj;   //D[]���v0��v����̾���,��ʼֵΪv0��v��ֱ�Ӿ���
               for(w = 0;w < G.vexnum;w++)
                    p[v][w] = false;        //·����ʼ��Ϊ��
                if(D[v] < INFINITY)      //v0��v��ֱ��·��
                    p[v][v0] = p[v][v] = true;
                    //һά����p[v][]���v0��v����̾��뾭���Ķ���,Ŀǰ������������ v0 �� v
            }

            final[v0] = true;       //Դ��v0����S��
            D[v0] = 0;      //v0��v0�ľ���Ϊ0

          for(i = 1;i < G.vexnum;i++)        //�������� G.vexnum - 1 ������
         {
             //��ʼ��ѭ��,ÿ�����v0��ĳ������v�����·��,����v����S��
                min = INFINITY;     //Ŀǰ��֪��v0����Ķ���ľ���,��ֵΪ��
                for(w = 0;w < G.vexnum;w++)     //������ж���
                {
                    //��S��֮��Ķ���(final[] == false)��,����v0����Ķ���,��������Ÿ���v,���븳��min
                    if(!final[w] && D[w] < min)
                    {
                            min = D[w];     //��̵ľ���
                            v = w;      //��S��֮������v0����Ķ�������
                    }
                }

                final[v] = true;        //��v����S��

                for(w = 0;w < G.vexnum;w++)
                {
                        //�����²���Ķ���,���²���S���Ķ��㵽v0�ľ����·������
                    if(!final[w] && min < INFINITY && G.arcs[v][w].adj < INFINITY &&
                        (min + G.arcs[v][w].adj < D[w]))
                    {
                         //w������S���� v0��v��w �ľ��� < Ŀǰ v0��w �ľ���

                        D[w] = min + G.arcs[v][w].adj;      //����D[w]

                            //����p[w],v0��w�����Ķ������v0��v�����Ķ������ w
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
                printf("��");*/

            begin = MinNum;
            Path[MinNum] = false;
        }
        printf("\n");

}
