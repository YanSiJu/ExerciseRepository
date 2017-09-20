void  write(User *head);
//write(head)
        char  FILE_Name[30] = "UserInfomation.txt";

void  write(User *head)
{
        FILE *fp = fopen("UserInfomation.txt","w");
        if(!fp)
            {
                printf("error\n");
                exit(1);
            }
        User *p = head;
        while(p)
        {
            fprintf(fp,"%s  %ld  %s\n",p->Name,p->Account,p->Password);
            p = p->next;
        }
        fclose(fp);
        printf("\nwrite\n");
}




User* read(User* head)
{

        char    Name[NAME+1];
        char    Password[PAWD+1];
        long    Account;
        User *p,*q;

        head = NULL;

        FILE *fp = fopen("UserInfomation.txt","r");
        if(!fp)
        {
                printf("error2\n");
                exit(1);
        }

        while(!feof(fp))
        {
             fscanf(fp,"%s%ld%s",Name,&Account,Password);
             q = (User *)malloc(sizeof(User));
            if(!q)
            {
                    printf("error3\n");
                    exit(1);
            }
            strcpy(q->Name,Name);
            strcpy(q->Password,Password);
            q->Account = Account;
            q->next = NULL;

            if(!head)		//头结点为空
            {
                head = q;
            }
            else		//将P接在head后面，作为第2个结点
            {
                q->next = head;
                head = q;
            }
        }
        fclose(fp);
        return head->next;
}
