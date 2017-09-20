#define     MAX_VERTEX_NUM      100      //��󶥵���
#define     MAX_NAME            30      //��󶥵����Ƹ���
#define     INFINITY           0
#define     MAX_INFO        20
typedef   char    InfoType;
typedef   int   VRType;   //���嶥���ϵ����
typedef    enum     GraphKind{DG,DN,UDG,UDN}  GraphKind;            //{����ͼ,������,����ͼ,������}



       /* ����Ϣ�ṹ  */
   typedef   struct
   {
       VRType   adj;        //�����ϵ����,������Ȩͼ��0��ʾ�����ڣ�1��ʾ���ڡ�������Ȩͼ����ʾȨֵ
       InfoType      *info;      //�û������Ϣ��ָ��
   }ArcCell,AdjMaTrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά����


     /*  ����ṹ  */
     typedef  struct
     {
         char  name[MAX_NAME+1];       //��������
         int  *Buses;
         int   Buses_Num;
     }VerTexType;


     /*  ͼ�ṹ  */
   typedef   struct  MGraph
   {
       VerTexType   vexs[MAX_VERTEX_NUM];   //��������
       AdjMaTrix    arcs;                   //�ڽӾ���(��ά����)
       int          vexnum,arcnum;          //��(��)��Ŀ��������Ŀ
       GraphKind    kind;                  //ͼ�������־
   }MGraph;

        MGraph  G;      //ͼ(�洢������·��վ��)

void  InputArc(InfoType  **arc)
{
        char  s[MAX_INFO];
        int   m;
        gets(s);
        m = strlen(s);
        if(m)
        {
            *arc = (InfoType *)malloc(m*sizeof(InfoType));
            strcpy(*arc,s);
        }
}
