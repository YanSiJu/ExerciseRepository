                //宏定义
#define     Line_Add     InsertArc   //增加线路即为在图中插入边
#define     Line_Delete  DeleteArc   //删除线路即为在图中删除边

void    Option2(int choose,MGraph  *G,void main_menu(MGraph *));
void  Line_Management(MGraph  *G,void main_menu(MGraph *G));
void  Check_Line(MGraph *G);
void  skip2(MGraph *G,void main_menu(MGraph *));

    //菜单
void  Line_Management(MGraph  *G,void main_menu(MGraph *))
{
            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------公交线路管理------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)增加线路\t\t(2)删除线路\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(3)线路信息修改\t\t\t\t\t(4)查看当前公交线路\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t(5)返回上级菜单\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("请输入您的选项:");
            int choose;
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose  && 4 != choose  && 5 != choose)
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose || 3 == choose  || 4 == choose  || 5 == choose)
                            {

                                break;
                            }
                        }
            }

                Option2(choose,G,main_menu);
}



 //输入功能选项后跳转至相应的功能界面
void    Option2(int choose,MGraph  *G,void main_menu(MGraph *))
{
            VerTexType V,W;
            int i;
            switch(choose)
            {
                case 1:printf("请输入欲增加的线路的数目:");
                       int Line_Num;
                       scanf("%d",&Line_Num);
                       //printf("请输入欲增加的%d条线路的名称:",Vex_Num);
                       for(i = 0;i < Line_Num; i++)
                       {
                           printf("请输入第%d条线路上的2个站点:",i+1);
                           scanf("%s%s",V.name,W.name);
                           Line_Add(G,V,W);
                           //void   InsertArc(MGraph  *G,VerTexType   v,VerTexType   w)
                       }

                       Graph_Write(G);
                       skip2(G,main_menu);

                       break;

                case 2:printf("请输入欲删除的线路的数目:");
                       int Num;
                       scanf("%d",&Num);
                      // printf("请输入欲删除的%d个站点的名称:",Vex_Num);
                       for(i = 0;i < Num; i++)
                       {
                           printf("请输入第%d条线路上的2个站点:",i+1);
                           scanf("%s%s",V.name,W.name);
                           Line_Delete(G,V,W);
                        }
                        Graph_Write(G);
                       skip2(G,main_menu);

                       break;

                case 4:PrintMatrix(*G);


                       skip2(G,main_menu);

                        break;

                case 5:printf("请按任意键跳转至上级菜单......");
                        getchar();
                        system("cls");
                        main_menu(G);
                        break;
            }


}


void  skip2(MGraph *G,void main_menu(MGraph *))
{
        printf("\n(1)返回上级菜单   (2)退出程序");
        int choose;
        printf("\n请输入您的选项:");
        fflush(stdin);
        scanf("%d",&choose);
        if(1 == choose)
        {
                printf("即将跳转至上级菜单....");
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
        printf("当前的站点有:");
        for(i = 0;i < G->vexnum; i++)
        {
            printf("%s   ",G->vexs[i].name);
        }
}
*/
