#include"Shortest_Path.h"
#include"All_Path.h"

void  Bus_Query(void(*menu)());
void  Station_Query(char   Name[MAX_NAME+1]);
void  skip4(MGraph G);
void  Line_Query(int Name);
void  Tacke_Bus_Strategy(int start,int end);

        void(*Menu)();

  //菜单
void  Bus_Query(void(*menu)())
{
            Menu = menu;
            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------公交查询管理------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)站站查询\t\t(2)站点查询\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(3)线路查询\t\t\t\t\t(4)最短距离查询\t\t\t\t\t\t□\n\n");
            printf("\t\t\t□\t(5)返回上级菜单\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("请输入您的选项:");
            int flag,i,j,k,choose,v0 = 1,v = 0,x,y,start,end;
            VerTexType  V,W;
            ShortPathTable   D;
            PathMatrix   p;
            Bus *q;
            bool  *path;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose  && 4 != choose  && 5 != choose && 6 != choose)
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose  || 4 == choose  || 5 == choose || 6 == choose)
                                break;
                        }
            }

            switch(choose)
            {
                case 4:path = (bool *)malloc(G.vexnum*sizeof(bool));
                        if(!path)
                        {
                            printf("error\n");
                        }

                       printf("请输入起点站和终点站:");
                       scanf("%s%s",V.name,W.name);
                       start = LocateVex(G,V);
                       end = LocateVex(G,W);

                       if(start < 0 || end < 0)
                       {
                            while(1)
                            {
                                fflush(stdin);
                                printf("输入错误，请重新输入起点和终点:");
                                scanf("%s%s",V.name,W.name);

                                start = LocateVex(G,V);
                                end = LocateVex(G,W);
                                if(start >= 0 && end >= 0)
                                    break;
                            }
                       }

                        ShortestPath_DIJ(G,start,p,D);

                        int a[MAX_VERTEX_NUM],size;
                        a[0] = start;
                        size = 1;

                        if( start != end && D[v] < INFINITY)
                        {
                                printf("%s →%s:%d m \n",G.vexs[start].name,G.vexs[end].name,D[end]);

                                for(j = 0; j < G.vexnum;j++)
                                    path[j] = p[end][j];
                                MakePath(G,path,start,end,a,&size);
                        }


                    x = a[0] ;
                    printf("\n注:长沙大学 →德雅路口(132 136 901)：表示 长沙大学 →德雅路口 可乘坐132 136 901路公交车\n");
                    printf("%s",G.vexs[x].name);
                    for(j = 0; j < size - 1;j++)
                    {
                           x = a[j+1];
                            printf(" →%s(",G.vexs[x].name);
                            for(q = City_Buses; q; q = q->next)
                            {
                                    flag = 0;
                                    for(k = 0; k < q->Station_Num; k++)
                                    {
                                            if(q->stations[k] == a[j]||  q->stations[k] == a[j+1])
                                                flag++;

                              //  printf("\nflag:%d\n",flag);
                                            if(2 == flag)
                                            {
                                                printf("%d ",q->Bus_Name);
                                                break;
                                            }
                                    }


                            }
                            printf(")");
                    }
                        printf("\n");
                        skip4(G);
                        break;

               /* case 5:printf("即将跳转至上级菜单......");
                        Sleep(5000);
                        system("cls");
                        main_menu(G);
                        break;*/

                case 1:printf("请输入起点站和终点站:");
                       scanf("%s%s",V.name,W.name);
                       start = LocateVex(G,V);
                       end = LocateVex(G,W);


                       if(start < 0 || end < 0)
                       {
                            while(1)
                            {
                                fflush(stdin);
                                printf("输入错误，请重新输入起点和终点:");
                                scanf("%s%s",V.name,W.name);
                                start = LocateVex(G,V);
                                end = LocateVex(G,W);
                                if(start >= 0 && end >= 0)
                                    break;
                            }
                       }

                       Tacke_Bus_Strategy(start,end);
                       skip4(G);
                       break;

               case 5:printf("即将跳转至上级菜单\n");
                      Sleep(3000);
                      system("cls");
                      Menu();
                      break;

                case 2:printf("请输入欲查询的站点:");
                       char   Name[MAX_NAME+1];       //站点名称
                       scanf("%s",Name);
                       printf("该站点停靠的公交车有:");
                       Station_Query(Name);
                       skip4(G);
                       break;

                case 3:printf("请输入欲查询的公交线路:");
                       int Bus_Name;
                       scanf("%d",&Bus_Name);
                       printf("该公交线路经过的站点有:");
                       Line_Query(Bus_Name);
                       skip4(G);
                       break;
            }
}

         //站点查询:查询某个站点所停靠的公交车
void  Station_Query(char   Name[MAX_NAME+1])
{
            //遍历顶点向量数组，若某顶点的名字与欲查找的顶点的名字相等，则打印出该站点所停靠的所有公交车
        int i,j;

        for(i = 0; i < G.vexnum; i++)       //遍历顶点向量数组
        {
               if(!strcmp(G.vexs[i].name,Name))     //若查找成功，则打印出所有站点名
               {
                    for(j = 0; j < G.vexs[i].Buses_Num; j++)
                            printf("%d   ",G.vexs[i].Buses[j]);
               }
        }
}

void  Tacke_Bus_Strategy(int start,int end)
{

        int   x,v,V,W,i,j,k,Vex_Used[G.vexnum];
        for( i = 0;i < G.vexnum;i++)
            Vex_Used[i] = 0;

        int flag = 0,PathNum = 0,P[G.vexnum];
        Bus *p;
        Path Paths[100];
        getPaths(start,end,Vex_Used,Paths,&PathNum);
        //printf("\n%d\n",PathNum);

        //打印点 start 到点 end 的所有路径
        /*for(i = 0;i < PathNum;i++)
        {

            for(j= Paths[i].size-1;j >= 1;j--)
            {
                    v = Paths[i].nodes[j];
                    printf("%s →",G.vexs[v].name);
            }

            v = Paths[i].nodes[j];
            printf("%s\n",G.vexs[v].name);
        }
*/
        printf("\n注:长沙大学 →德雅路口(132 136 901)：表示 长沙大学 →德雅路口 可乘坐132 136 901路公交车\n");
        for(i = 0; i < PathNum;i++)
        {

            x = Paths[i].size - 1;
            v = Paths[i].nodes[x];

            printf("\n\n方案%d:%s",i+1,G.vexs[v].name);
            for(j = Paths[i].size - 1; j >= 1;j--)
            {


                W = Paths[i].nodes[j-1];
                printf(" →%s(",G.vexs[W].name);
                    for(p = City_Buses; p; p = p->next)
                    {
                             flag = 0;
                            for(k = 0; k < p->Station_Num; k++)
                            {
                                if(p->stations[k] == Paths[i].nodes[j] ||  p->stations[k] == Paths[i].nodes[j-1])
                                            flag++;

                              //  printf("\nflag:%d\n",flag);
                                if(2 == flag)
                                {
                                        printf("%d ",p->Bus_Name);
                                        break;
                                }
                            }


                    }
                    printf(")");
            }


        }

}
        //公交线路查询:查询某条公交线路所经过的站点
void  Line_Query(int Name)
{
            /*
                遍历公交车链表，
                若某公交车的名字与欲查找的公交车名字相等，
                则打印出其站点
            */

        Bus *p = City_Buses;
        int j,n;
        for(; p; p = p->next)       //遍历链表
        {
            if(Name == p->Bus_Name)
            {
                for(j = 0; j < p->Station_Num; j++)     //搜索到欲查找的公交车
                {
                    n = p->stations[j];
                    printf("%s  ",G.vexs[n].name);      //打印其站点名
                }
            }
            printf("\n");
        }

}





void  skip4(MGraph G)
{
        printf("\n(1)返回上级菜单   (2)退出程序");
        int choose;
        printf("\n请输入您的选项:");
        fflush(stdin);
        scanf("%d",&choose);


        if(1 != choose && 2 != choose )
        {
            while(1)
            {
                printf("输入错误,请重新输入:");
                scanf("%d",&choose);
                if(1 == choose || 2 == choose)
                    break;

            }
        }


        if(1 == choose)
        {
                printf("即将跳转至上级菜单....");
                Sleep(4000);
                system("cls");
                Bus_Query(Menu);
        }
        else if(2 == choose)
        {
            exit(1);
        }

}

