
                //Station_Management.h:增加 、删除、修改 、查看站点信息

                //宏定义
#define     Station_Add     InsertVex   //增加站点即为在图中插入顶点
#define     Station_Delete  DeleteVex   //删除站点即为在图中删除顶点


        //函数声明
void  Station_Management(MGraph  *G,void main_menu(MGraph *G));
void  Check_Station(MGraph G);
void  skip(MGraph *G,void main_menu(MGraph *));     //跳转函数
void Station_Info_Change(VerTexType *V);        //修改站点信息
void Show_Station_Info(VerTexType V);


    //站点管理菜单
void  Station_Management(MGraph  *G,void main_menu(MGraph *))
{


            while(1)
            {
                printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------公交站点管理------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)增加站点\t\t(2)删除站点\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(3)站点信息修改\t\t\t\t\t(4)查看当前站点\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t(5)返回上级菜单\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("请输入您的选项:");

            int choose,flag = 0,t;
            char  name[MAX_NAME+1];
                scanf("%d",&choose);

                switch(choose)
                {
                    case 1:system("cls");       //增加站点
                           printf("请输入欲增加的站点数目:");
                           VerTexType V;
                           int Vex_Num,Bus_Num;
                           scanf("%d",&Vex_Num);

                            for(int i = 0;i < Vex_Num; i++)
                            {
                                printf("\n\n\n请输入第%d个站点的名字以及其所停靠的公交车数目:",i+1);
                                scanf("%s%d",&V.name,&Bus_Num);
                                Station_Add(G,V);       //循环调用Station_Add(G,V)函数增加站点

                                    //,存储停靠在该站点的公交车
                                G->vexs[G->vexnum-1].Buses =(int *)malloc(Bus_Num*sizeof(int));
                                if(!G->vexs[G->vexnum-1].Buses)
                                    return;

                                G->vexs[G->vexnum - 1].Buses_Num = Bus_Num;
                                printf("请输入%d条公交线路名:",Bus_Num);
                                for(int j = 0; j < Bus_Num; j++)        //输入停靠在该站点的公交车
                                    scanf("%d",&G->vexs[G->vexnum-1].Buses[j]);
                            }

                            Graph_Write(G);     //将信息存入文件
                            skip(G,main_menu);      //调用跳转函数

                            break;

                case 2:printf("请输入欲删除的站点数目:");      //删除站点
                       int Num;
                       scanf("%d",&Num);
                       printf("请输入欲删除的%d个站点的名称:",Num);

                        //循环输入欲删除的站点名称
                       for(int i = 0;i < Num; i++)
                       {
                           scanf("%s",&V.name);
                           Station_Delete(G,V);     //调用Station_Delete(G,V)函数删除站点
                           fflush(stdin);
                       }

                       Graph_Write(G);     //将信息存入文件
                       skip(G,main_menu);      //调用跳转函数

                       break;

                case 4:Check_Station(*G);        //查看站点信息
                       skip(G,main_menu);
                        break;


                    //修改站点信息
                case 3:system("cls");
                        flag = 0;
                        printf("请输入欲修改的站点:");

                        while(1)
                        {
                            scanf("%s",name);

                                    //遍历站点数组,与输入的站点名相比较
                            for(int i = 0; i < G->vexnum; i++)
                                if(!strcmp(name,G->vexs[i].name))   //查找到欲修改的站点,结束for循环
                                {
                                        flag = 1;   //flag标志域:初始化为0,查找到欲修改的站点则置为1
                                        t = i;
                                        break;
                                }

                            if(flag)
                                break;      //跳出while循环
                            else
                                printf("输入错误,请重新输入:");
                        }

                        Station_Info_Change(&G->vexs[t]);

                       // skip(G,main_menu);      //调用跳转函数

                        break;

                case 5:printf("即将跳转至上级菜单......");
                        Sleep(5000);
                        system("cls");
                        main_menu(G);
                        break;

                default:printf("输入错误,请重新输入:");
                        break;
                }
            }
}



        //跳转函数
void  skip(MGraph *G,void main_menu(MGraph *))
{
        printf("\n(1)返回上级菜单   (2)退出程序");
        int choose;
        printf("\n请输入您的选项:");
        fflush(stdin);


            //输入功能选项
        while(1)
        {
            scanf("%d",&choose);

            if(1 == choose)     //跳转至站点管理菜单
            {
                printf("即将跳转至上级菜单....");
                Sleep(700);
                system("cls");
                Station_Management(G,main_menu);
                break;
            }

            else if(2 == choose)        //退出程序
                exit(1);
            else
                printf("输入错误,请重新输入:");
        }
}


    //查看站点信息
void  Check_Station(MGraph G)
{


            //遍历顶点向量数组，搜索欲查询的站点名称
        for(int i = 0;i < G.vexnum; i++)
        {

                printf("站点名:%s  ",G.vexs[i].name);

                if(0 == G.vexs[i].Buses_Num)
                    printf("该站点无公交停靠\n");
                else
                {
                    printf("经过的公交有:");
                    for(int j = 0; j < G.vexs[i].Buses_Num; j++)       //打印出站点所停靠的公交车
                        printf("%d   ",G.vexs[i].Buses[j]);
                }


                printf("\n");

        }
}



        //站点信息修改
void Station_Info_Change(VerTexType *V)
{

            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------公交站点管理------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)修改站点名称\t\t(2)增加该站点的公交车\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(3)删除该站点的公交\t\t\t\t\t(4)返回上级菜单\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

            int choose,t;
            while(1)
            {


                printf("\n请输入您的选项:");
                scanf("%d",&choose);    //输入功能选项

                    //功能选择
                switch(choose)
                {
                        //修改站点名称
                    case 1:printf("请输入新的站点名称:");
                           scanf("%s",V->name);      //输入新的站点名
                           Show_Station_Info(*V);   //显示站点信息
                           break;


                            //增加该站点的公交车
                    case 2:printf("请输入欲增加的公交车数目:");
                            int Add_Station_Num;
                            scanf("%d",&Add_Station_Num);       //输入公交车数目

                            int * Buses;
                            Buses = (int *)realloc(V->Buses,(V->Buses_Num + Add_Station_Num) * sizeof(int));      //动态开辟空间,存储公交车
                            if(!Buses)
                                return;

                            V->Buses = Buses;
                            printf("请输入%d条公交线路:",Add_Station_Num);
                            for(int i = 0; i < Add_Station_Num; i++)        //输入公交车名
                                       scanf("%d",&V->Buses[V->Buses_Num + i]);
                             V->Buses_Num += Add_Station_Num;   //修改公交车数目

                             Show_Station_Info(*V);   //显示站点信息

                             break;

                    case 3:printf("请输入欲删除的公交车路线:");
                            int Bus_Name,flag = 0;

                                //判断输入的公交路线名是否正确
                            while(1)
                            {
                                    scanf("%d",&Bus_Name);  //输入欲删除的公交路线

                                        for(int j = 0; j < V->Buses_Num; j++)   //遍历数组,搜索与相匹配的公交路线名
                                            if(Bus_Name == V->Buses[j])
                                            {
                                                t = j;
                                                flag = 1;
                                                break;
                                            }

                                            if(flag)    //搜索到该公交路线，跳出while循环
                                                break;

                                            printf("输入错误，请重新输入:");
                            }

                                    //移动欲删除元素后面的元素
                            for(int j = t + 1; j < V->Buses_Num; j++)
                                V->Buses[j-1] = V->Buses[j];
                            V->Buses_Num--;     //公交车数目减1

                            Show_Station_Info(*V);   //显示站点信息

                            break;

                    case 4:system("cls");
                           return;

                    default:printf("输入错误,请重新输入:");
                            break;
                }
               Graph_Write(&G);     //将信息存入文件
            }
}




void Show_Station_Info(VerTexType V)
{
            //显示站点信息
            printf("信息修改成功,修改后的信息为:\n");
            printf("站点名:%s  ",V.name);

            if(0 == V.Buses_Num)
                printf("该站点无公交停靠\n");
            else
            {
                printf("经过的公交有:");
                for(int j = 0; j < V.Buses_Num; j++)       //打印出站点所停靠的公交车
                    printf("%d   ",V.Buses[j]);
            }

}
