

void Bus_Write(Bus *head);

void Bus_Write(Bus *head)
{
        FILE *fp = fopen("Bus.txt","w");

        if(!fp)
        {
            printf("文件打开失败\n");
            return;
        }

        int i;
        Bus *p = head;
        for(; p; p = p->next)
        {
            fprintf(fp,"%d  %d\n",p->Bus_Name,p->Station_Num);
            for(i = 0; i < p->Station_Num; i++)
                fprintf(fp,"%d ",p->stations[i]);
            fprintf(fp,"\n");
        }
        fclose(fp);

        printf("Bus_Write\n");
}




Bus* Bus_read(Bus *head)
{
        FILE *fp = fopen("Bus.txt","r");

        if(!fp)
        {
            printf("文件打开失败\n");
    //        return;
        }

        int i;
        Bus *p;
        while(!feof(fp))
        {
            p = (Bus *)malloc(sizeof(Bus));
            if(!p)
            {
                printf("内存分配失败\n");
//                return;
            }

            fscanf(fp,"%d  %d\n",&p->Bus_Name,&p->Station_Num);

            p->stations = (int *)malloc(p->Station_Num*sizeof(int));
            if(!p->stations)
            {
                printf("内存分配失败\n");
//                return;
            }
            for(i = 0; i < p->Station_Num; i++)
                fscanf(fp,"%d ",&p->stations[i]);

            fscanf(fp,"\n");

            p->next = NULL;
            if(!head)
                head = p;
            else
            {
                p->next = head;
                head = p;
            }
        }
        fclose(fp);
        return head;
}
