
#include <stdio.h>
#include <stdlib.h>

 struct datetime {
  int timer,minuter,sekunder;
  int dato,moned,or;
  };

 void init_datetime(struct datetime* dt,int newOr,
 int newMoned,int newDato,int newtimer,int newMinuter,int newSekunder){

  dt->timer= newtimer;
  dt->minuter=newMinuter;
  dt->sekunder=newSekunder;
  dt->dato=newDato;
  dt->moned=newMoned;
  dt->or=newOr;
}


void datetime_set_date(struct datetime* dt,int newdato, int newmoned, int newor){

 dt->dato=newdato;
 dt->moned=newmoned;
 dt->or=newor;

}

void datetime_set_time(struct datetime* dt,int newtimer, int newminuter, int newsekunder){
 
  dt->timer=newtimer;
  dt->minuter=newminuter;
  dt->sekunder=newsekunder;

}

void datetime_diff(struct datetime* dt_from,
                   struct datetime* dt_to,struct datetime* dt_res
                   ){
int orr= dt_to->or - dt_from->or;
int month=dt_to->moned - dt_from->moned;
int date=dt_to->dato - dt_from->dato;

int hour=dt_to->timer - dt_from->timer;
int minutes=dt_to->minuter - dt_from->minuter;
int seconds=dt_to->sekunder - dt_from->sekunder;

dt_res->or=orr;
dt_res->moned=month;
dt_res->dato=date;

dt_res->timer=hour;
dt_res->minuter=minutes;
dt_res->sekunder=seconds;

 int year=dt_res->or;
 int monthe=dt_res->moned;
 int dates=dt_res->dato;

  int hours=dt_res->timer;
  int min=dt_res->minuter;
  int sek=dt_res->sekunder;
   
  
printf("%d years %d month %d date %d hours %d minutes %d seconds  \n",year,monthe,dates,hours,min,sek);
}


 

 int main (int argc, char* argv[]){
   struct datetime date1;
   struct datetime date2;
   struct datetime time1;
   struct datetime time2;
   struct datetime dateRes;
    
   datetime_set_date(&date1,12,12,2016);
   datetime_set_date(&date2,10,10,2000);

   datetime_set_time(&time1,12,45,50);
   datetime_set_time(&time2,8,30,35);
    

   

   datetime_diff(&date2,&date1,&dateRes);
   datetime_diff(&time1,&time2,&dateRes);
   
    


 return 0;

}















