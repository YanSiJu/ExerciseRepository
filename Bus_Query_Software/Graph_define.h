#define     MAX_VERTEX_NUM      100      //最大顶点数
#define     MAX_NAME            30      //最大顶点名称个数
#define     INFINITY           0
#define     MAX_INFO        20
typedef   char    InfoType;
typedef   int   VRType;   //定义顶点关系类型
typedef    enum     GraphKind{DG,DN,UDG,UDN}  GraphKind;            //{有向图,有向网,无向图,无向网}



       /* 弧信息结构  */
   typedef   struct
   {
       VRType   adj;        //顶点关系类型,对于有权图：0表示不相邻，1表示相邻。对于有权图，表示权值
       InfoType      *info;      //该弧相关信息的指针
   }ArcCell,AdjMaTrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组


     /*  顶点结构  */
     typedef  struct
     {
         char  name[MAX_NAME+1];       //顶点名称
         int  *Buses;
         int   Buses_Num;
     }VerTexType;


     /*  图结构  */
   typedef   struct  MGraph
   {
       VerTexType   vexs[MAX_VERTEX_NUM];   //顶点向量
       AdjMaTrix    arcs;                   //邻接矩阵(二维数组)
       int          vexnum,arcnum;          //弧(边)数目、顶点数目
       GraphKind    kind;                  //图的种类标志
   }MGraph;

        MGraph  G;      //图(存储公交线路及站点)

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
