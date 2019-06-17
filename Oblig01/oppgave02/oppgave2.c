
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int stringsum(char* s){
  
   int i;
   int total=0; 

  for(i=0;i<strlen(s);i++){
     if(isalpha(s[i])){
       total=total + i;
     }
        else 
   return -1;
  }
    

   return total;
}

  
int distance_between(char* s,char c){

   int i=0;
   int j=0;
   int avstand;
    int  temp;
   int t;
    int num[3];
  while(i<=strlen(s)){
      if(s[i]==c){
     temp=i;
     num[j]=temp;
    
      j++;
   }
   
  i++;
} 
   for(t=0; t<3; t++) {
     if(num[1] != '\0'){
    avstand= num[1] - num[0];
     return avstand;}
   }
  return -1;
    
}

 char* string_between(char*s, char c){

     char* newString=malloc(strlen(s)+1);
    int i,temp;
  for(i=0;i<strlen(s);i++){
    if(s[i]==c){
     temp=i;
      while(s[temp+1]!=c){

        newString[i]=s[temp+1];
       temp++;
}
}
   }
      char* second=newString;
      free(newString);

     return newString;
    
}
 

char** split(char* s){

  char* list[strlen(s)+1];
   int i;
   for(i=0;i<strlen(s);i++){
      if(s[i] != ' '){
        list[i]=s[i];
       
        printf(" %c, ",list[i]); 
         continue;
     } 
        
    printf("%i",list[strlen(s)+1]);
     
       
  }
   printf("\n");

 return list;

}

void stringsum2(char* s,int* res){
  
   int i;
   int total=0; 
  int ret=-1;
  for(i=0;i<strlen(s);i++){
     if(isalpha(s[i])){
       total=total + i;
       res= &total;
     }
        else 
      res=&ret;
  }
    

   
}

 int main(void){


  return 0;
}
