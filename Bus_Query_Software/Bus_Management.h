void  skip3(MGraph *G,void (*main_menu)(MGraph *));
void  Add_Bus(Bus **head);
void Look_Over_Bus(MGraph G,Bus *head);

void   Bus_Management(MGraph *G,void(*Main_Menu)(MGraph *))
{
            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------��·Ա�˵�------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)�鿴��������Ϣ\t\t(2)���ӹ�����\t\t\t\t\t��\n\n");
            printf("\t\t\t��\t(3)�����ϼ��˵�\t\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");
            printf("����������ѡ��:");
            int choose;
            int Station_Num,i;
           // char Name[STATION_NAME+1];
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose)
            {
                        while(1)
                        {
                            printf("�������,����������:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose)
                            {

                                break;
                            }
                        }
            }

             switch(choose)
            {
                case 1:Look_Over_Bus(*G,City_Buses);
                        skip3(G,Main_Menu);
                        break;

                case 2: Add_Bus(&(City_Buses));
                        Bus_Write(City_Buses);
                        skip3(G,Main_Menu);
                        break;

                case 3:printf("������ת���˵�......");
                        Sleep(1000);
                        system("cls");
                        Main_Menu(G);
                        break;
            }



}



void  Add_Bus(Bus **head)
{
        //printf(":");
        int Bus_Num,station_Num,i,j;
        Bus *p;
        printf("�����빫����������:");
        scanf("%d",&Bus_Num);

        for(i = 0;i < Bus_Num;i++)
        {
            p = (Bus *)malloc(sizeof(Bus));
            if(!p)
            {
                printf("ERROR\n");
                return;
            }
            printf("�������%d���������������Լ���·��վ�������:",i+1);
            scanf("%d%d",&p->Bus_Name,&station_Num);
            p->Station_Num = station_Num;

            p->stations = (int*)malloc(station_Num*sizeof(int));
            if(!p->stations)
            {
                printf("ERROR\n");
                return;
            }
            printf("�������վ��ı��(0--%d):",G.vexnum-1);
            for(j = 0;j < station_Num;j++)
                    scanf("%d",&(p->stations[j]));

            p->next = NULL;
            if(!(*head))        //ͷ���Ϊ��
                *head = p;      //��ͷ���ָ��p
            else                    //ͷ��㲻Ϊ��
            {
                p->next = *head;        //��p���ڱ�ͷ
                *head = p;
            }
        }

}





void Look_Over_Bus(MGraph G,Bus *head)
{
    //Look_Over_Bus(City_Buses)
        Bus *p = head;
        int i,n;
        for(; p; p = p->next)
        {
            printf("\n\n%d·������������վ����:",p->Bus_Name);

            for(i = 0;i < p->Station_Num;i++)       //��ӡվ��
            {
                 n = p->stations[i];
                 printf("%s  ",G.vexs[n].name);
            }
            printf("\n");
        }
}



void  skip3(MGraph *G,void (*main_menu)(MGraph *))
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
                            {

                                break;
                            }
                        }
            }

        if(1 == choose)
        {
                printf("������ת���ϼ��˵�....");
                Sleep(4000);
                system("cls");
                Bus_Management(G,main_menu);
        }
        else  if(2  == choose)
        {
            exit(1);
        }

}
