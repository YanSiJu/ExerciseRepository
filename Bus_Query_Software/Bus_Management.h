void  skip3(MGraph *G,void (*main_menu)(MGraph *));
void  Add_Bus(Bus **head);
void Look_Over_Bus(MGraph G,Bus *head);

void   Bus_Management(MGraph *G,void(*Main_Menu)(MGraph *))
{
            printf("\n\n\n\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t ------管路员菜单------  \t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t(1)查看公交车信息\t\t(2)增加公交车\t\t\t\t\t□\n\n");
            printf("\t\t\t□\t(3)返回上级菜单\t\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□\t\t\t\t\t\t\t\t\t\t□\n");
            printf("\t\t\t□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            printf("请输入您的选项:");
            int choose;
            int Station_Num,i;
           // char Name[STATION_NAME+1];
            scanf("%d",&choose);
            if(1 != choose && 2 != choose && 3 != choose)
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
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

                case 3:printf("即将跳转至菜单......");
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
        printf("请输入公交车的数量:");
        scanf("%d",&Bus_Num);

        for(i = 0;i < Bus_Num;i++)
        {
            p = (Bus *)malloc(sizeof(Bus));
            if(!p)
            {
                printf("ERROR\n");
                return;
            }
            printf("请输入第%d辆公交车的名称以及所路经站点的数量:",i+1);
            scanf("%d%d",&p->Bus_Name,&station_Num);
            p->Station_Num = station_Num;

            p->stations = (int*)malloc(station_Num*sizeof(int));
            if(!p->stations)
            {
                printf("ERROR\n");
                return;
            }
            printf("请输入各站点的编号(0--%d):",G.vexnum-1);
            for(j = 0;j < station_Num;j++)
                    scanf("%d",&(p->stations[j]));

            p->next = NULL;
            if(!(*head))        //头结点为空
                *head = p;      //将头结点指向p
            else                    //头结点不为空
            {
                p->next = *head;        //将p插在表头
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
            printf("\n\n%d路公交车经过的站点有:",p->Bus_Name);

            for(i = 0;i < p->Station_Num;i++)       //打印站点
            {
                 n = p->stations[i];
                 printf("%s  ",G.vexs[n].name);
            }
            printf("\n");
        }
}



void  skip3(MGraph *G,void (*main_menu)(MGraph *))
{
        printf("\n(1)返回上级菜单   (2)退出程序");
        int choose;
        printf("\n请输入您的选项:");
        fflush(stdin);
        scanf("%d",&choose);
        if(1 != choose && 2 != choose )
            {
                        while(1)
                        {
                            printf("输入错误,请重新输入:");
                            scanf("%d",&choose);
                            if(1 == choose || 2 == choose)
                            {

                                break;
                            }
                        }
            }

        if(1 == choose)
        {
                printf("即将跳转至上级菜单....");
                Sleep(4000);
                system("cls");
                Bus_Management(G,main_menu);
        }
        else  if(2  == choose)
        {
            exit(1);
        }

}
