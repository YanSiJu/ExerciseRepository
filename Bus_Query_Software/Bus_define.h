        //������·�ṹ
     typedef  struct   bus
     {
         int  Bus_Name;     //������·����
         int *stations;
         int  Station_Num;
         struct  bus  *next;
     }Bus;
        Bus  *City_Buses = NULL;
