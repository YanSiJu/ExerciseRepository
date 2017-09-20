
#include"FILE.h"
#include"Graph_Save.h"
#include"Bus_Save.h"
#include"Station_Management.h"
#include"Line_Management.h"
#include"Bus_Management.h"
#include"Bus_Query.h"

                /*
                            �û�ģ��
                    �����û�ע�ᡢ�û���¼���û���Ϣ�޸ĺ��û�ע��4����
                */



        //ȫ�ֱ�����ֵ����
            void(*Menu)();
        //��������
void    menu(void(*main_menu)());
void    Choose();
void Skip(void(*Menu)());
void    User_Register();
void    User_Login();
void    Change_Information();
void    User_Logout();      //ע��
int    check_acc(long acc);
void Input_ACC_and_PAWD(char    *Pawd,long    *acc);
void  Login_Success(MGraph *G);
int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior);

        //�û�ע��
void    User_Register()
{
            User_Ptr q,P = (User *)malloc(sizeof(User));        //��̬���ٿռ�
            if(!P)
            {
                printf("");

            }

                    //���������Ϣ�����ע��
            printf("\t\t\t\t\t\t�û�ע��\t\t\t\t\n\t\t\t����д������Ϣ�����ע��\n");
            printf("�ǳ�:");
            scanf("%s",P->Name);
            printf("����:");
            scanf("%s",P->Password);


            srand(time(NULL));      //ʹ������������˺ţ��ұ�֤ÿ���û����˺Ų�ͬ
            long acc = rand()%(999999-100000)+100000;
                        //���ɵ��˺���[100000,999999]������   rand()%(y-x+1)+x:����[x,y]��Χ�ڵ������
            if(!check_acc(acc))     //���ɵ��˺����������˺��ظ�����������
            {
                while(1)
                {
                    acc = rand()%(999999-100000)+100000;
                    if(check_acc(acc))      //���ɵ��˺Ų����ظ�
                        break;
                }
            }
            printf("\t\t\tע��ɹ��������˺���:%ld,���μ��˺�\n",acc);
            P->Account = acc;
            P->next = NULL;

            if(!head)		//ͷ���Ϊ��
            {
                head = P;
            }
            else		//��P����head���棬��Ϊ��2�����
            {
                P->next = head;
                head = P;
            }


}


        //�û���¼
void    User_Login()
{
            char    Pawd[PAWD+1];
            long    acc;
            printf("\t\t\t\t\t��¼����\n");
            User_Ptr p,prior;

            Input_ACC_and_PAWD(Pawd,&acc);      //�����˺ź�����
            if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))     //�˺Ż������������
            {
                 while(1)
                 {
                     printf("\t\t\t\t\t�˺Ż������������,����������\n");

                            //�����˺ź�����
                     Input_ACC_and_PAWD(Pawd,&acc);
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))   //�˺ź�����������ȷ,����ѭ����(pΪ��ɾ���,priorΪ��ǰ�����)
                        break;

                 }

            }
            printf("\n��¼�ɹ�,������ת�����˵�......");
            Sleep(2000);
            system("cls");
            Bus_Query(menu);

}


        //�û�ע��
void    User_Logout()
{
            char    Pawd[PAWD+1];
            long    acc;
            User_Ptr q,p = NULL,prior = NULL;
            printf("       ������������Ϣ    \n");
            Input_ACC_and_PAWD(Pawd,&acc);      //�����˺ź�����

            if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))     //�˺Ż������������
            {
                 while(1)
                 {
                    // system("cls");
                     printf("\t\t\t\t\t�˺Ż������������,����������\n");
                     Input_ACC_and_PAWD(Pawd,&acc);
                     //int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior)
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))   //�˺ź�����������ȷ,pΪ��ɾ���,priorΪ��ǰ�����
                            break;
                 }

            }


                    //ɾ�����
            if(p == head)       //��ɾ���Ϊͷ���
            {
                head = head->next;      //��2�����Ϊ�µ�ͷ���

            }

            else if(!p->next)       //��ɾ���Ϊβ���
            {
                prior->next = NULL;     //��prior��Ϊ�µ�β���

            }

            else            //��ɾ���Ȳ���ͷ���,Ҳ����β���
            {
                prior->next = p->next;

            }
            free(p);        //�ͷ�p
            printf("\nע���ɹ�!\n");
}




        //�޸���Ϣ
void    Change_Information()
{
        printf("\t\t\t\t\t��Ϣ�޸Ľ���\n");
        char    Pawd[PAWD+1];
        long    acc;
        User_Ptr p = NULL,prior = NULL;
        printf("       ������������Ϣ    \n");
        Input_ACC_and_PAWD(Pawd,&acc);      //�����˺ź�����


        if(!Check_ACC_and_Pawd(Pawd,acc,&p,&prior))
        {
                 while(1)
                 {
                     system("cls");
                     printf("\t\t\t\t\t�˺Ż������������,����������\n");
                     Input_ACC_and_PAWD(Pawd,&acc);
                     if(Check_ACC_and_Pawd(Pawd,acc,&p,&prior))    //�˺ź�����������ȷ
                            break;
                 }

         }

         printf("\n��    ��        ��  ��        ��  ��\n");
         printf("%s    %ld     %s\n",p->Name,p->Account,p->Password);
         printf("\t\t\t\t\t(1)�޸�����    (2)�޸�����\n");
         int  choose;
         scanf("%d",&choose);
         switch(choose)
         {
                   case 1:printf("������������:");
                   scanf("%s",p->Password);
                   printf("��Ϣ�޸ĳɹ�������������Ϊ:%s  ���μǴ�����\n",p->Password);
                   break;

            case 2:printf("���������ǳ�:");
                    scanf("%s",p->Name);
                   printf("��Ϣ�޸ĳɹ����������ǳ�Ϊ:%s\n",p->Name);
                   break;
         }



}


void  Login_Success(MGraph *G)
{
            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------�û����˵�------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)վ�����\t\t(2)��·����\t\t\t\t\t��\n\n");
            printf("\t\t\t��\t(3)��������\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(4)�����ϼ��˵�\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");


            printf("����������ѡ��:");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose  && 4 != choose)
            {
                        while(1)
                        {
                            printf("�������,����������:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose  || 4 == choose)
                                break;
                        }
            }
            switch(choose)
            {
                case 1:printf("������ת��վ�����˵�......");
                        Sleep(1000);
                        system("cls");
                        Station_Management(G,Login_Success);
                        break;

                case 2:printf("������ת����·����˵�......");
                        Sleep(1000);
                        system("cls");
                        Line_Management(G,Login_Success);
                        break;

                 case 3:printf("������ת����������˵�......");
                        Sleep(1000);
                        system("cls");
                        Bus_Management(G,Login_Success);
                        //void   Bus_Management(MGraph *G,void(*Main_Menu)())
                        break;

                case 4:printf("������ת���ϼ��˵�......");
                        Sleep(1000);
                        system("cls");
                        menu(Menu);
                        break;
            }

}



            //�����˺ź�����
void Input_ACC_and_PAWD(char    *Pawd,long    *acc)
{
            printf("�˺�:");
            scanf("%ld",acc);
            //Input_ACC_and_PAWD(Pawd,&acc);
            printf("����:");
            scanf("%s",Pawd);
}



      /*
                �����˺�ʱ���ж����ɵ��˺��Ƿ��������˺��ظ�
                �����ظ��򷵻�1�����򷵻�0
            */
int check_acc(long acc)
{
        User_Ptr q = head;      //qָ���һ�����
        for(; q; q = q->next)
        {
            if(acc == q->Account)   //��ĳ�˺��ظ�,����0
                return 0;

        }
        return 1;       //���ظ�������1
}


                /*
                    ���������˺ź������Ƿ���ȷ��
                    ����ȷ���򷵻�1����Pָ����˺�
                    �������Ӧ�Ľ��,priorָ����ǰ
                    �����;���򷵻�0
                */
int  Check_ACC_and_Pawd(char    Pawd[PAWD+1],long    acc,User_Ptr *p,User_Ptr *prior)
{
            User_Ptr q = head;
            for(; q; q = q->next)
            {
                if(acc == q->Account && !strcmp(Pawd,q->Password))
                {
                        *p = q;
                        return 1;       //������ȷ������1
                }
                *prior = q;
            }
            return 0;       //������󣬷���0
}



        //��ת�����˵�
void Skip(void(*Menu)())
{

            printf("\n7�����ת��������......\n");
            Sleep(7000);
            system("cls");
            menu(Menu);
}




    //�˵�
void  menu(void(*main_menu)())
{
            Menu = main_menu;
            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------��ӭʹ�ù�����ѯ���------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)�û�ע��\t\t(2)�û���¼\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(3)��Ϣ�޸�\t\t(4)�û�ע��\t\t\t\t\t��\n\n");
            printf("\t\t\t��\t(5)�����ϼ��˵�\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");


            printf("����������ѡ��(0-�˳�����):");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose && 4 != choose && 0 != choose && 5 != choose)
            {
                        while(1)
                        {
                            printf("�������,����������:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose || 4 == choose  || 0 == choose  || 5 == choose)
                                break;
                        }
            }


            switch(choose)
            {
                case 1:printf("3�����ת��ע�����......\n");
                       Sleep(3000);
                       system("cls");
                       User_Register();     //�û�ע��
                        write(head);
                       Skip(main_menu);          //��ת�����˵�
                       break;

                case 2:printf("1�����ת����¼����......\n");
                       Sleep(500);
                       system("cls");
                       User_Login();    //��¼
                        write(head);
                     //  Skip();          //��ת�����˵�
                       break;

                case 3:printf("3�����ת����Ϣ�޸Ľ���......\n");
                       Sleep(3000);
                       system("cls");
                       Change_Information();    //�޸���Ϣ
                        write(head);
                       Skip(main_menu);          //��ת�����˵�
                       break;

                case 4:printf("3�����ת��ע������......\n");
                       Sleep(3000);
                       system("cls");
                       User_Logout();       //ע���û�
                       write(head);
                       Skip(main_menu);          //��ת�����˵�
                       break;

                case 0:write(head);
                        exit(1);

                case 5:printf("\n������ת���ϼ��˵�......");
                        Sleep(2000);
                        system("cls");
                        Menu();
                        break;


            }
}
