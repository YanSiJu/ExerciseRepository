                //�궨��
#define     Line_Add     InsertArc   //������·��Ϊ��ͼ�в����
#define     Line_Delete  DeleteArc   //ɾ����·��Ϊ��ͼ��ɾ����

void    Option2(int choose,MGraph  *G,void main_menu(MGraph *));
void  Line_Management(MGraph  *G,void main_menu(MGraph *G));
void  Check_Line(MGraph *G);
void  skip2(MGraph *G,void main_menu(MGraph *));

    //�˵�
void  Line_Management(MGraph  *G,void main_menu(MGraph *))
{
            printf("\n\n\n\t\t\t������������������������������������������������������������������������������\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t ------������·����------  \t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(1)������·\t\t(2)ɾ����·\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t(3)��·��Ϣ�޸�\t\t\t\t\t(4)�鿴��ǰ������·\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t(5)�����ϼ��˵�\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t��\t\t\t\t\t\t\t\t\t\t��\n");
            printf("\t\t\t������������������������������������������������������������������������������\n");
            printf("����������ѡ��:");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose  && 4 != choose  && 5 != choose)
            {
                        while(1)
                        {
                            printf("�������,����������:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose  || 4 == choose  || 5 == choose)
                            {

                                break;
                            }
                        }
            }

                Option2(choose,G,main_menu);
}



 //���빦��ѡ�����ת����Ӧ�Ĺ��ܽ���
void    Option2(int choose,MGraph  *G,void main_menu(MGraph *))
{
            VerTexType V,W;
            int i;
            switch(choose)
            {
                case 1:printf("�����������ӵ���·����Ŀ:");
                       int Line_Num;
                       scanf("%d",&Line_Num);
                       //printf("�����������ӵ�%d����·������:",Vex_Num);
                       for(i = 0;i < Line_Num; i++)
                       {
                           printf("�������%d����·�ϵ�2��վ��:",i+1);
                           scanf("%s%s",V.name,W.name);
                           Line_Add(G,V,W);
                           //void   InsertArc(MGraph  *G,VerTexType   v,VerTexType   w)
                       }

                       Graph_Write(G);
                       skip2(G,main_menu);

                       break;

                case 2:printf("��������ɾ������·����Ŀ:");
                       int Num;
                       scanf("%d",&Num);
                      // printf("��������ɾ����%d��վ�������:",Vex_Num);
                       for(i = 0;i < Num; i++)
                       {
                           printf("�������%d����·�ϵ�2��վ��:",i+1);
                           scanf("%s%s",V.name,W.name);
                           Line_Delete(G,V,W);
                        }
                        Graph_Write(G);
                       skip2(G,main_menu);

                       break;

                case 4:PrintMatrix(*G);


                       skip2(G,main_menu);

                        break;

                case 5:printf("�밴�������ת���ϼ��˵�......");
                        getchar();
                        system("cls");
                        main_menu(G);
                        break;
            }


}


void  skip2(MGraph *G,void main_menu(MGraph *))
{
        printf("\n(1)�����ϼ��˵�   (2)�˳�����");
        int choose;
        printf("\n����������ѡ��:");
        fflush(stdin);
        scanf("%d",&choose);
        if(1 == choose)
        {
                printf("������ת���ϼ��˵�....");
                Sleep(4000);
                system("cls");
                Line_Management(G,main_menu);
        }
        else
        {
            exit(1);
        }

}

/*void  Check_Line(MGraph *G)
{
        int i;
        printf("��ǰ��վ����:");
        for(i = 0;i < G->vexnum; i++)
        {
            printf("%s   ",G->vexs[i].name);
        }
}
*/
