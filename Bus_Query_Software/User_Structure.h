#define     NAME            10      //��������
#define     PAWD            6      //���볤��



            //�û��ṹ�嶨��(���õ�����洢)
        typedef  struct user
        {
            char    Name[NAME+1];
            char    Password[PAWD+1];
            long    Account;

            struct  user  *next;
        }User,*User_Ptr;


        User_Ptr head = NULL;      //�û���Ϣ����ͷָ��(ȫ�ֱ���)
