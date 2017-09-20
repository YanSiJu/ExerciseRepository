        //公交线路结构
     typedef  struct   bus
     {
         int  Bus_Name;     //公交线路名称
         int *stations;
         int  Station_Num;
         struct  bus  *next;
     }Bus;
        Bus  *City_Buses = NULL;
