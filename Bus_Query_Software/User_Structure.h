#define     NAME            10      //姓名长度
#define     PAWD            6      //密码长度



            //用户结构体定义(采用单链表存储)
        typedef  struct user
        {
            char    Name[NAME+1];
            char    Password[PAWD+1];
            long    Account;

            struct  user  *next;
        }User,*User_Ptr;


        User_Ptr head = NULL;      //用户信息链表头指针(全局变量)
