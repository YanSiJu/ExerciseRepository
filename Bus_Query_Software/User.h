
#include"FILE.h"
#include"Graph_Save.h"
#include"Bus_Save.h"
#include"Station_Management.h"
#include"Line_Management.h"
#include"Bus_Management.h"
#include"Bus_Query.h"

                /*
                            用户模块
                    包括用户注册、用户登录、用户信息修改和用户注销4大功能
                */



        //全局变量赋值问题
            void(*Menu)();
        //函数定义
void    menu(void(*main_menu)());
void    Choose();
void Skip(void(*Menu)());
void    User_Register();
void    User_Login();
void    Change_Information();
void    User_Logout();      //注销
int    check_acc(long acc);
void Input_ACC_and_PAWD(char    *Pawd,long    *acc);
void  Login_Success(MGraph *G);
int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior);

        //用户注册
void    User_Register()
{
            User_Ptr q,P = (User *)malloc(sizeof(User));        //动态开辟空间
            if(!P)
            {
                printf("");

            }

                    //输入相关信息，完成注册
            printf("\t\t\t\t\t\t用户注册\t\t\t\t\n\t\t\t请填写以下信息，完成注册\n");
            printf("昵称:");
            scanf("%s",P->Name);
            printf("密码:");
            scanf("%s",P->Password);


            srand(time(NULL));      //使用随机数生成账号，且保证每个用户的账号不同
            long acc = rand()%(999999-100000)+100000;
                        //生成的账号在[100000,999999]区间内   rand()%(y-x+1)+x:生成[x,y]范围内的随机数
            if(!check_acc(acc))     //生成的账号与其他的账号重复，重新生成
            {
                while(1)
                {
                    acc = rand()%(999999-100000)+100000;
                    if(check_acc(acc))      //生成的账号不再重复
                        break;
                }
            }
            printf("\t\t\t注册成功，您的账号是:%ld,请牢记账号\n",acc);
            P->Account = acc;
            P->next = NULL;

            if(!head)		//头结点为空
            {
                head = P;
            }
            else		//将P接在head后面，作为第2个结点
            {
                P->next = head;
                head = P;
            }


}


        //用户登录
void    User_Login()
{
            char    Pawd[PAWD+1];
            long    acc;
            printf("\t\t\t\t\t登录界面\n");
            User_Ptr p,prior;

            Input_ACC_and_PAWD(Pawd,&acc);      //输入账号和密码
            if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))     //账号或密码输入错误
            {
                 while(1)
                 {
                     printf("\t\t\t\t\t账号或密码输入错误,请重新输入\n");

                            //输入账号和密码
                     Input_ACC_and_PAWD(Pawd,&acc);
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))   //账号和密码输入正确,跳出循环。(p为待删结点,prior为其前驱结点)
                        break;

                 }

            }
            printf("\n登录成功,即将跳转至主菜单......");
            Sleep(2000);
            system("cls");
            Bus_Query(menu);

}


        //用户注销
void    User_Logout()
{
            char    Pawd[PAWD+1];
            long    acc;
            User_Ptr q,p = NULL,prior = NULL;
            printf("       请输入以下信息    \n");
            Input_ACC_and_PAWD(Pawd,&acc);      //输入账号和密码

            if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))     //账号或密码输入错误
            {
                 while(1)
                 {
                    // system("cls");
                     printf("\t\t\t\t\t账号或密码输入错误,请重新输入\n");
                     Input_ACC_and_PAWD(Pawd,&acc);
                     //int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior)
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))   //账号和密码输入正确,p为待删结点,prior为其前驱结点
                            break;
                 }

            }


                    //删除结点
            if(p == head)       //待删结点为头结点
            {
                head = head->next;      //第2个结点为新的头结点

            }

            else if(!p->next)       //待删结点为尾结点
            {
                prior->next = NULL;     //将prior作为新的尾结点

            }

            else            //待删结点既不是头结点,也不是尾结点
            {
                prior->next = p->next;

            }
            free(p);        //释放p
            printf("\n注销成功!\n");
}




        //修改信息
void    Change_Information()
{
        printf("\t\t\t\t\t信息修改界面\n");
        char    Pawd[PAWD+1];
        long    acc;
        User_Ptr p = NULL,prior = NULL;
        printf("       请输入以下信息    \n");
        Input_ACC_and_PAWD(Pawd,&acc);      //输入账号和密码


        if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))
        {
                 while(1)
                 {
                     system("cls");
                     printf("\t\t\t\t\t账号或密码输入错误,请重新输入\n");
                     Input_ACC_and_PAWD(Pawd,&acc);
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))    //账号和密码输入正确
                            break;
                 }

         }

         printf("\n姓    名        账  号        密  码\n");
         printf("%s    %ld     %s\n",p->Name,p->Account,p->Password);
         printf("\t\t\t\t\t(1)修改密码    (2)修改姓名\n");
         int  choose;
         scanf("%d",&choose);
         switch(choose)
         {
                   case 1:printf("请输入新密码:");
                   scanf("%s",p->Password);
                   printf("信息修改成功，您的新密码为:%s  请牢记此密码\n",p->Password);
                   break;

            case 2:printf("请输入新昵称:");
                    scanf("%s",p->Name);
                   printf("信息修改成功，您的新昵称为:%s\n",p->Name);
                   break;
         }



}


void  Login_Success(MGraph *G)
{
            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------用户主菜单------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)站点管理\t\t(2)线路管理\t\t\t\t\t□\n\n");
            printf("\t\t\t□\t(3)公交管理\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(4)返回上级菜单\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");


            printf("请输入您的选项:");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose  && 4 != choose)
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose  || 4 == choose)
                                break;
                        }
            }
            switch(choose)
            {
                case 1:printf("即将跳转至站点管理菜单......");
                        Sleep(1000);
                        system("cls");
                        Station_Management(G,Login_Success);
                        break;

                case 2:printf("即将跳转至线路管理菜单......");
                        Sleep(1000);
                        system("cls");
                        Line_Management(G,Login_Success);
                        break;

                 case 3:printf("即将跳转至公交管理菜单......");
                        Sleep(1000);
                        system("cls");
                        Bus_Management(G,Login_Success);
                        //void   Bus_Management(MGraph *G,void(*Main_Menu)())
                        break;

                case 4:printf("即将跳转至上级菜单......");
                        Sleep(1000);
                        system("cls");
                        menu(Menu);
                        break;
            }

}



            //输入账号和密码
void Input_ACC_and_PAWD(char    *Pawd,long    *acc)
{
            printf("账号:");
            scanf("%ld",acc);
            //Input_ACC_and_PAWD(Pawd,&acc);
            printf("密码:");
            scanf("%s",Pawd);
}



      /*
                生成账号时，判断生成的账号是否与其他账号重复
                若不重复则返回1，否则返回0
            */
int check_acc(long acc)
{
        User_Ptr q = head;      //q指向第一个结点
        for(; q; q = q->next)
        {
            if(acc == q->Account)   //与某账号重复,返回0
                return 0;

        }
        return 1;       //不重复，返回1
}


                /*
                    检查输入的账号和密码是否正确。
                    若正确，则返回1且用P指向该账号
                    和密码对应的结点,prior指向其前
                    驱结点;否则返回0
                */
int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior)
{
            User_Ptr q = head;
            for(; q; q = q->next)
            {
                if(acc == q->Account && !strcmp(Pawd,q->Password))
                {
                        *p = q;
                        return 1;       //输入正确，返回1
                }
                *prior = q;
            }
            return 0;       //输入错误，返回0
}



        //跳转至主菜单
void Skip(void(*Menu)())
{

            printf("\n7秒后将跳转到主界面......\n");
            Sleep(7000);
            system("cls");
            menu(Menu);
}




    //菜单
void  menu(void(*main_menu)())
{
            Menu = main_menu;
            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------欢迎使用公交查询软件------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)用户注册\t\t(2)用户登录\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(3)信息修改\t\t(4)用户注销\t\t\t\t\t□\n\n");
            printf("\t\t\t□\t(5)返回上级菜单\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");


            printf("请输入您的选项(0-退出程序):");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose && 4 != choose && 0 != choose && 5 != choose)
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose || 4 == choose  || 0 == choose  || 5 == choose)
                                break;
                        }
            }


            switch(choose)
            {
                case 1:printf("3秒后将跳转到注册界面......\n");
                       Sleep(3000);
                       system("cls");
                       User_Register();     //用户注册
                        write(head);
                       Skip(main_menu);          //跳转至主菜单
                       break;

                case 2:printf("1秒后将跳转到登录界面......\n");
                       Sleep(500);
                       system("cls");
                       User_Login();    //登录
                        write(head);
                     //  Skip();          //跳转至主菜单
                       break;

                case 3:printf("3秒后将跳转到信息修改界面......\n");
                       Sleep(3000);
                       system("cls");
                       Change_Information();    //修改信息
                        write(head);
                       Skip(main_menu);          //跳转至主菜单
                       break;

                case 4:printf("3秒后将跳转到注销界面......\n");
                       Sleep(3000);
                       system("cls");
                       User_Logout();       //注销用户
                       write(head);
                       Skip(main_menu);          //跳转至主菜单
                       break;

                case 0:write(head);
                        exit(1);

                case 5:printf("\n即将跳转至上级菜单......");
                        Sleep(2000);
                        system("cls");
                        Menu();
                        break;


            }
}
