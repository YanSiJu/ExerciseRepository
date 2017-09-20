
        //包含头文件
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>        //时间函数,生成随机数时用于设置种子
#include<windows.h>     //Sleep()函数头文件
#include<string.h>      //字符串处理函数
#include<limits.h>      //包含INT_MAX(整型最大值)
#include"Graph_define.h"        //图的类型定义
#include"Graph.h"       //图的基本操作
#include"Bus_define.h"
#include"User_Structure.h"  //用户结构定义
#include"User.h"        //用户模块

        char  Administrator[15] = "960101";     //管理员密码

    //函数声明
void  Identity_Choose();
void  Administrator_Menu();

    //主函数
int  main()
{


        system("title Bus_Query");      //cmd窗口标题

            //从文件中读取信息
        G = Graph_Read(G);
        head = read(head);  //读取用户信息
        City_Buses = Bus_read(City_Buses);
        Identity_Choose();

        system("pause");
        return 0;
}


        //身份选择
void  Identity_Choose()
{

        printf("1 管理员  2 普通用户\n\n请选择您的身份(0-退出程序):");
        char  administrator[15];    //记录输入的密码,与管理员密码进行比对
        int choose;

         while(1)
         {
            scanf("%d",&choose);        //输入功能选项
            switch(choose)
            {
                case 1:printf("管理员密码:");        //管理员登录
                        scanf("%s",administrator);

                        while(0 != strcmp(administrator,Administrator))
                        {
                            printf("输入错误，请重新输入:");
                            scanf("%s",administrator);
                        }

                        printf("\n登录成功,即将跳转至管理界面......");
                        Sleep(700);
                        system("cls");
                        Administrator_Menu();
                        break;

                case 2:menu(Identity_Choose);       //用户登录
                       break;

                case 0:exit(1);     //退出程序

                default:printf("输入错误,请重新输入:");
                        break;
            }
        }
}


        //管理员菜单
void  Administrator_Menu()
{


                //进行功能选择
            while(1)
            {
                printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t ------管理员菜单------  \t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t(1)站点管理\t\t(2)线路管理\t\t\t\t\t□\n\n");
                printf("\t\t\t□\t(3)公交管理\t\t\t\t\t\t(4)返回上级菜单\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
                printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
                printf("请输入您的选项:");
                int choose;

                scanf("%d",&choose);
                switch(choose)
                {
                    case 1:printf("即将跳转至站点管理菜单......");     //站点管理
                            Sleep(700);
                            system("cls");
                            Station_Management(&G,Administrator_Menu);
                            break;

                    case 2:printf("即将跳转至线路管理菜单......");     //线路管理(相邻站点间)
                            Sleep(700);
                            system("cls");
                            Line_Management(&G,Administrator_Menu);
                            break;

                    case 3:printf("即将跳转至公交管理菜单......");     //公交车管理
                            Sleep(700);
                            system("cls");
                            Bus_Management(&G,Administrator_Menu);
                            break;

                    case 4:printf("即将跳转至上级菜单......");
                           getchar();
                           system("cls");
                           Identity_Choose();
                           break;

                    default:printf("输入错误,请重新输入:");      //输入错误,提示用户重新输入
                            break;
                }
            }
}
