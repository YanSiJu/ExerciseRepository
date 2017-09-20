        //读图的信息进行读取


        //函数声明
void  Graph_Write(MGraph *G);
MGraph Graph_Read(MGraph  G);


void Graph_Write(MGraph  *G)
{
        int i,j;
        FILE *fp;
        fp = fopen("Graph.txt","w");
        if(!fp)
        {
            printf("系统拒绝分配内存\n");
            return;
        }

        fprintf(fp,"%d  %d  %d\n",G->vexnum,G->arcnum,G->kind);



        for(i = 0;i < G->vexnum; i++)
        {
            fprintf(fp,"%s  %d\n",G->vexs[i].name,G->vexs[i].Buses_Num);


            for(j = 0; j < G->vexs[i].Buses_Num; j++)
                    fprintf(fp,"%d  ",G->vexs[i].Buses[j]);
            fprintf(fp,"\n");
        }

        for(i = 0; i < G->vexnum; i++)
            for(j = 0; j < G->vexnum; j++)
            {
                    if(INT_MAX  == G->arcs[i][j].adj)
                        fprintf(fp,"0 ");
                    else
                        fprintf(fp,"%d ",G->arcs[i][j].adj);
                    if(j == G->vexnum - 1)
                        fprintf(fp,"\n");
            }
            fclose(fp);
           // printf("\n  Graph_Write \n");
}




MGraph Graph_Read(MGraph  G)
{
        int i,j,n;
        FILE *fp;
        fp = fopen("Graph.txt","r");
        if(!fp)
        {
            printf("系统拒绝分配内存\n");
            exit(1);
        }

       fscanf(fp,"%d  %d  %d\n",&G.vexnum,&G.arcnum,&G.kind);



       for(i = 0;i < G.vexnum; i++)
        {
            fscanf(fp,"%s  %d\n",G.vexs[i].name,&G.vexs[i].Buses_Num);


                G.vexs[i].Buses = (int *)malloc(G.vexs[i].Buses_Num*sizeof(int));
                if(!G.vexs[i].Buses)
                {
                    printf("error");
      //              return;
                }

            for(j = 0; j < G.vexs[i].Buses_Num; j++)
                    fscanf(fp,"%d  ",&G.vexs[i].Buses[j]);
                fscanf(fp,"\n");

        }

       for(i = 0; i < G.vexnum; i++)
            for(j = 0; j < G.vexnum; j++)
            {
                    fscanf(fp,"%d",&G.arcs[i][j].adj);
                    if(j == G.vexnum - 1)
                        fscanf(fp,"\n");
            }
            fclose(fp);
         //   printf("\n  Graph_Read \n");
            return G;
}
