
                //Station_Management.h:���� ��ɾ�����޸� ���鿴վ����Ϣ

                //�궨��
#define     Station_Add     InsertVex   //����վ�㼴Ϊ��ͼ�в��붥��
#define     Station_Delete  DeleteVex   //ɾ��վ�㼴Ϊ��ͼ��ɾ������


        //��������
void  Station_Management(MGraph  *G,void main_menu(MGraph *G));
void  Check_Station(MGraph G);
void  skip(MGraph *G,void main_menu(MGraph *));     //��ת����
void Station_Info_Change(VerTexType *V);        //�޸�վ����Ϣ
void Show_Station_Info(VerTexType V);


    //վ�����˵�
void  Station_Management(MGraph  *G,void main_menu(MGraph *))
{


            while(1)
            {
                printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------����վ�����------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)����վ��\t\t(2)ɾ��վ��\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(3)վ����Ϣ�޸�\t\t\t\t\t(4)�鿴��ǰվ��\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t(5)�����ϼ��˵�\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");
            printf("����������ѡ��:");

            int choose,flag = 0,t;
            char  name[MAX_NAME+1];
                scanf("%d",&choose);

                switch(choose)
                {
                    case 1:system("cls");       //����վ��
                           printf("�����������ӵ�վ����Ŀ:");
                           VerTexType V;
                           int Vex_Num,Bus_Num;
                           scanf("%d",&Vex_Num);

                            for(int i = 0;i < Vex_Num; i++)
                            {
                                printf("\n\n\n�������%d��վ��������Լ�����ͣ���Ĺ�������Ŀ:",i+1);
                                scanf("%s%d",&V.name,&Bus_Num);
                                Station_Add(G,V);       //ѭ������Station_Add(G,V)��������վ��

                                    //,�洢ͣ���ڸ�վ��Ĺ�����
                                G->vexs[G->vexnum-1].Buses =(int *)malloc(Bus_Num*sizeof(int));
                                if(!G->vexs[G->vexnum-1].Buses)
                                    return;

                                G->vexs[G->vexnum - 1].Buses_Num = Bus_Num;
                                printf("������%d��������·��:",Bus_Num);
                                for(int j = 0; j < Bus_Num; j++)        //����ͣ���ڸ�վ��Ĺ�����
                                    scanf("%d",&G->vexs[G->vexnum-1].Buses[j]);
                            }

                            Graph_Write(G);     //����Ϣ�����ļ�
                            skip(G,main_menu);      //������ת����

                            break;

                case 2:printf("��������ɾ����վ����Ŀ:");      //ɾ��վ��
                       int Num;
                       scanf("%d",&Num);
                       printf("��������ɾ����%d��վ�������:",Num);

                        //ѭ��������ɾ����վ������
                       for(int i = 0;i < Num; i++)
                       {
                           scanf("%s",&V.name);
                           Station_Delete(G,V);     //����Station_Delete(G,V)����ɾ��վ��
                           fflush(stdin);
                       }

                       Graph_Write(G);     //����Ϣ�����ļ�
                       skip(G,main_menu);      //������ת����

                       break;

                case 4:Check_Station(*G);        //�鿴վ����Ϣ
                       skip(G,main_menu);
                        break;


                    //�޸�վ����Ϣ
                case 3:system("cls");
                        flag = 0;
                        printf("���������޸ĵ�վ��:");

                        while(1)
                        {
                            scanf("%s",name);

                                    //����վ������,�������վ������Ƚ�
                            for(int i = 0; i < G->vexnum; i++)
                                if(!strcmp(name,G->vexs[i].name))   //���ҵ����޸ĵ�վ��,����forѭ��
                                {
                                        flag = 1;   //flag��־��:��ʼ��Ϊ0,���ҵ����޸ĵ�վ������Ϊ1
                                        t = i;
                                        break;
                                }

                            if(flag)
                                break;      //����whileѭ��
                            else
                                printf("�������,����������:");
                        }

                        Station_Info_Change(&G->vexs[t]);

                       // skip(G,main_menu);      //������ת����

                        break;

                case 5:printf("������ת���ϼ��˵�......");
                        Sleep(5000);
                        system("cls");
                        main_menu(G);
                        break;

                default:printf("�������,����������:");
                        break;
                }
            }
}



        //��ת����
void  skip(MGraph *G,void main_menu(MGraph *))
{
        printf("\n(1)�����ϼ��˵�   (2)�˳�����");
        int choose;
        printf("\n����������ѡ��:");
        fflush(stdin);


            //���빦��ѡ��
        while(1)
        {
            scanf("%d",&choose);

            if(1 == choose)     //��ת��վ�����˵�
            {
                printf("������ת���ϼ��˵�....");
                Sleep(700);
                system("cls");
                Station_Management(G,main_menu);
                break;
            }

            else if(2 == choose)        //�˳�����
                exit(1);
            else
                printf("�������,����������:");
        }
}


    //�鿴վ����Ϣ
void  Check_Station(MGraph G)
{


            //���������������飬��������ѯ��վ������
        for(int i = 0;i < G.vexnum; i++)
        {

                printf("վ����:%s  ",G.vexs[i].name);

                if(0 == G.vexs[i].Buses_Num)
                    printf("��վ���޹���ͣ��\n");
                else
                {
                    printf("�����Ĺ�����:");
                    for(int j = 0; j < G.vexs[i].Buses_Num; j++)       //��ӡ��վ����ͣ���Ĺ�����
                        printf("%d   ",G.vexs[i].Buses[j]);
                }


                printf("\n");

        }
}



        //վ����Ϣ�޸�
void Station_Info_Change(VerTexType *V)
{

            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------����վ�����------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)�޸�վ������\t\t(2)���Ӹ�վ��Ĺ�����\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(3)ɾ����վ��Ĺ���\t\t\t\t\t(4)�����ϼ��˵�\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");

            int choose,t;
            while(1)
            {


                printf("\n����������ѡ��:");
                scanf("%d",&choose);    //���빦��ѡ��

                    //����ѡ��
                switch(choose)
                {
                        //�޸�վ������
                    case 1:printf("�������µ�վ������:");
                           scanf("%s",V->name);      //�����µ�վ����
                           Show_Station_Info(*V);   //��ʾվ����Ϣ
                           break;


                            //���Ӹ�վ��Ĺ�����
                    case 2:printf("�����������ӵĹ�������Ŀ:");
                            int Add_Station_Num;
                            scanf("%d",&Add_Station_Num);       //���빫������Ŀ

                            int * Buses;
                            Buses = (int *)realloc(V->Buses,(V->Buses_Num + Add_Station_Num) * sizeof(int));      //��̬���ٿռ�,�洢������
                            if(!Buses)
                                return;

                            V->Buses = Buses;
                            printf("������%d��������·:",Add_Station_Num);
                            for(int i = 0; i < Add_Station_Num; i++)        //���빫������
                                       scanf("%d",&V->Buses[V->Buses_Num + i]);
                             V->Buses_Num += Add_Station_Num;   //�޸Ĺ�������Ŀ

                             Show_Station_Info(*V);   //��ʾվ����Ϣ

                             break;

                    case 3:printf("��������ɾ���Ĺ�����·��:");
                            int Bus_Name,flag = 0;

                                //�ж�����Ĺ���·�����Ƿ���ȷ
                            while(1)
                            {
                                    scanf("%d",&Bus_Name);  //������ɾ���Ĺ���·��

                                        for(int j = 0; j < V->Buses_Num; j++)   //��������,��������ƥ��Ĺ���·����
                                            if(Bus_Name == V->Buses[j])
                                            {
                                                t = j;
                                                flag = 1;
                                                break;
                                            }

                                            if(flag)    //�������ù���·�ߣ�����whileѭ��
                                                break;

                                            printf("�����������������:");
                            }

                                    //�ƶ���ɾ��Ԫ�غ����Ԫ��
                            for(int j = t + 1; j < V->Buses_Num; j++)
                                V->Buses[j-1] = V->Buses[j];
                            V->Buses_Num--;     //��������Ŀ��1

                            Show_Station_Info(*V);   //��ʾվ����Ϣ

                            break;

                    case 4:system("cls");
                           return;

                    default:printf("�������,����������:");
                            break;
                }
               Graph_Write(&G);     //����Ϣ�����ļ�
            }
}




void Show_Station_Info(VerTexType V)
{
            //��ʾվ����Ϣ
            printf("��Ϣ�޸ĳɹ�,�޸ĺ����ϢΪ:\n");
            printf("վ����:%s  ",V.name);

            if(0 == V.Buses_Num)
                printf("��վ���޹���ͣ��\n");
            else
            {
                printf("�����Ĺ�����:");
                for(int j = 0; j < V.Buses_Num; j++)       //��ӡ��վ����ͣ���Ĺ�����
                    printf("%d   ",V.Buses[j]);
            }

}
