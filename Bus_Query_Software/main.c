
        //����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>        //ʱ�亯��,���������ʱ������������
#include<windows.h>     //Sleep()����ͷ�ļ�
#include<string.h>      //�ַ���������
#include<limits.h>      //����INT_MAX(�������ֵ)
#include"Graph_define.h"        //ͼ�����Ͷ���
#include"Graph.h"       //ͼ�Ļ�������
#include"Bus_define.h"
#include"User_Structure.h"  //�û��ṹ����
#include"User.h"        //�û�ģ��

        char  Administrator[15] = "960101";     //����Ա����

    //��������
void  Identity_Choose();
void  Administrator_Menu();

    //������
int  main()
{


        system("title Bus_Query");      //cmd���ڱ���

            //���ļ��ж�ȡ��Ϣ
        G = Graph_Read(G);
        head = read(head);  //��ȡ�û���Ϣ
        City_Buses = Bus_read(City_Buses);
        Identity_Choose();

        system("pause");
        return 0;
}


        //���ѡ��
void  Identity_Choose()
{

        printf("1 ����Ա  2 ��ͨ�û�\n\n��ѡ���������(0-�˳�����):");
        char  administrator[15];    //��¼���������,�����Ա������бȶ�
        int choose;

         while(1)
         {
            scanf("%d",&choose);        //���빦��ѡ��
            switch(choose)
            {
                case 1:printf("����Ա����:");        //����Ա��¼
                        scanf("%s",administrator);

                        while(0 != strcmp(administrator,Administrator))
                        {
                            printf("�����������������:");
                            scanf("%s",administrator);
                        }

                        printf("\n��¼�ɹ�,������ת���������......");
                        Sleep(700);
                        system("cls");
                        Administrator_Menu();
                        break;

                case 2:menu(Identity_Choose);       //�û���¼
                       break;

                case 0:exit(1);     //�˳�����

                default:printf("�������,����������:");
                        break;
            }
        }
}


        //����Ա�˵�
void  Administrator_Menu()
{


                //���й���ѡ��
            while(1)
            {
                printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t ------����Ա�˵�------  \t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t(1)վ�����\t\t(2)��·����\t\t\t\t\t��\n\n");
                printf("\t\t\t��\t(3)��������\t\t\t\t\t\t(4)�����ϼ��˵�\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
                printf("\t\t\t������������������������������������������������������������������������������\n");
                printf("����������ѡ��:");
                int choose;

                scanf("%d",&choose);
                switch(choose)
                {
                    case 1:printf("������ת��վ�����˵�......");     //վ�����
                            Sleep(700);
                            system("cls");
                            Station_Management(&G,Administrator_Menu);
                            break;

                    case 2:printf("������ת����·����˵�......");     //��·����(����վ���)
                            Sleep(700);
                            system("cls");
                            Line_Management(&G,Administrator_Menu);
                            break;

                    case 3:printf("������ת����������˵�......");     //����������
                            Sleep(700);
                            system("cls");
                            Bus_Management(&G,Administrator_Menu);
                            break;

                    case 4:printf("������ת���ϼ��˵�......");
                           getchar();
                           system("cls");
                           Identity_Choose();
                           break;

                    default:printf("�������,����������:");      //�������,��ʾ�û���������
                            break;
                }
            }
}
