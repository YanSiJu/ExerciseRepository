#include"Shortest_Path.h"
#include"All_Path.h"

void  Bus_Query(void(*menu)());
void  Station_Query(char   Name[MAX_NAME+1]);
void  skip4(MGraph G);
void  Line_Query(int Name);
void  Tacke_Bus_Strategy(int start,int end);

        void(*Menu)();

  //�˵�
void  Bus_Query(void(*menu)())
{
            Menu = menu;
            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------������ѯ����------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)վվ��ѯ\t\t(2)վ���ѯ\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(3)��·��ѯ\t\t\t\t\t(4)��̾����ѯ\t\t\t\t\t\t��\n\n");
            printf("\t\t\t��\t(5)�����ϼ��˵�\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");
            printf("����������ѡ��:");
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
                            printf("�������,����������:");
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

                       printf("���������վ���յ�վ:");
                       scanf("%s%s",V.name,W.name);
                       start = LocateVex(G,V);
                       end = LocateVex(G,W);

                       if(start < 0 || end < 0)
                       {
                            while(1)
                            {
                                fflush(stdin);
                                printf("����������������������յ�:");
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
                                printf("%s ��%s:%d m \n",G.vexs[start].name,G.vexs[end].name,D[end]);

                                for(j = 0; j < G.vexnum;j++)
                                    path[j] = p[end][j];
                                MakePath(G,path,start,end,a,&size);
                        }


                    x = a[0] ;
                    printf("\nע:��ɳ��ѧ ������·��(132 136 901)����ʾ ��ɳ��ѧ ������·�� �ɳ���132 136 901·������\n");
                    printf("%s",G.vexs[x].name);
                    for(j = 0; j < size - 1;j++)
                    {
                           x = a[j+1];
                            printf(" ��%s(",G.vexs[x].name);
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

               /* case 5:printf("������ת���ϼ��˵�......");
                        Sleep(5000);
                        system("cls");
                        main_menu(G);
                        break;*/

                case 1:printf("���������վ���յ�վ:");
                       scanf("%s%s",V.name,W.name);
                       start = LocateVex(G,V);
                       end = LocateVex(G,W);


                       if(start < 0 || end < 0)
                       {
                            while(1)
                            {
                                fflush(stdin);
                                printf("����������������������յ�:");
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

               case 5:printf("������ת���ϼ��˵�\n");
                      Sleep(3000);
                      system("cls");
                      Menu();
                      break;

                case 2:printf("����������ѯ��վ��:");
                       char   Name[MAX_NAME+1];       //վ������
                       scanf("%s",Name);
                       printf("��վ��ͣ���Ĺ�������:");
                       Station_Query(Name);
                       skip4(G);
                       break;

                case 3:printf("����������ѯ�Ĺ�����·:");
                       int Bus_Name;
                       scanf("%d",&Bus_Name);
                       printf("�ù�����·������վ����:");
                       Line_Query(Bus_Name);
                       skip4(G);
                       break;
            }
}

         //վ���ѯ:��ѯĳ��վ����ͣ���Ĺ�����
void  Station_Query(char   Name[MAX_NAME+1])
{
            //���������������飬��ĳ����������������ҵĶ����������ȣ����ӡ����վ����ͣ�������й�����
        int i,j;

        for(i = 0; i < G.vexnum; i++)       //����������������
        {
               if(!strcmp(G.vexs[i].name,Name))     //�����ҳɹ������ӡ������վ����
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

        //��ӡ�� start ���� end ������·��
        /*for(i = 0;i < PathNum;i++)
        {

            for(j= Paths[i].size-1;j >= 1;j--)
            {
                    v = Paths[i].nodes[j];
                    printf("%s ��",G.vexs[v].name);
            }

            v = Paths[i].nodes[j];
            printf("%s\n",G.vexs[v].name);
        }
*/
        printf("\nע:��ɳ��ѧ ������·��(132 136 901)����ʾ ��ɳ��ѧ ������·�� �ɳ���132 136 901·������\n");
        for(i = 0; i < PathNum;i++)
        {

            x = Paths[i].size - 1;
            v = Paths[i].nodes[x];

            printf("\n\n����%d:%s",i+1,G.vexs[v].name);
            for(j = Paths[i].size - 1; j >= 1;j--)
            {


                W = Paths[i].nodes[j-1];
                printf(" ��%s(",G.vexs[W].name);
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
        //������·��ѯ:��ѯĳ��������·��������վ��
void  Line_Query(int Name)
{
            /*
                ��������������
                ��ĳ�������������������ҵĹ�����������ȣ�
                ���ӡ����վ��
            */

        Bus *p = City_Buses;
        int j,n;
        for(; p; p = p->next)       //��������
        {
            if(Name == p->Bus_Name)
            {
                for(j = 0; j < p->Station_Num; j++)     //�����������ҵĹ�����
                {
                    n = p->stations[j];
                    printf("%s  ",G.vexs[n].name);      //��ӡ��վ����
                }
            }
            printf("\n");
        }

}





void  skip4(MGraph G)
{
        printf("\n(1)�����ϼ��˵�   (2)�˳�����");
        int choose;
        printf("\n����������ѡ��:");
        fflush(stdin);
        scanf("%d",&choose);


        if(1 != choose && 2 != choose )
        {
            while(1)
            {
                printf("�������,����������:");
                scanf("%d",&choose);
                if(1 == choose || 2 == choose)
                    break;

            }
        }


        if(1 == choose)
        {
                printf("������ת���ϼ��˵�....");
                Sleep(4000);
                system("cls");
                Bus_Query(Menu);
        }
        else if(2 == choose)
        {
            exit(1);
        }

}

