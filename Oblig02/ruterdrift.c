# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct rute {
  unsigned char ruterId;
  unsigned char FLAGG;
  unsigned char length;
  char modell[253];

};
static struct rute *mainarray[1000]; // global variable to hold all the file that is read
int static counter=0; 

// method prints out the ruter info given the id
void printId(int id){
  
  //struct rute* rut= (struct rute * ) malloc (sizeof(struct rute));
   
 
  printf("Ruter id : %d\n",mainarray[id]->ruterId);
  printf("flagg : %x \n",mainarray[id]->FLAGG);
  printf("length : %d \n",mainarray[id]->length);
  printf("modell:%s \n",mainarray[id]->modell);
 
}
void endreFlagg(int id){
  int current,previous;
  unsigned int newvalue,t,flagid;
  unsigned char rutid,lengthe;
  char modelle[253], *temp;
  struct rute *rut=(struct rute *) malloc (sizeof(struct rute));
   
  current=rut->FLAGG << 4;
  previous=rut->FLAGG >> 4;

  if(previous <= 15){
    printf("enter the id for the flag \n");
    scanf("%d",&flagid);

    printf("enter the new flag value \n");

    scanf("%d",&newvalue);
    t= 4 >> newvalue;
    previous++;
    previous = previous << 4;
    flagid = t | previous;
 
    rut->ruterId=rutid;
    rut->length=lengthe;
    temp = strncpy(rut->modell,mainarray[id]->modell,mainarray[id]->length+3);
    mainarray[id]=rut;
     
  }
  

  
   

}
void endreModell(int id){
  char *newValue;
  char *temp;
  newValue = (char *) malloc (20 * sizeof(char));
  printf("enter the new modell  value \n"); 
  scanf("%s", newValue);
  temp = strncpy(mainarray[id]->modell, newValue, mainarray[id]->length+3);
  free(newValue);
}
void leggInNyRuter(){
  struct rute* rut= (struct rute *) malloc (sizeof(struct rute));
  unsigned char newId,newLength;
  char *newModell,newFlagg;
  newModell= (char *) malloc(20 * sizeof(char));
   
  printf("enter routerid \n");
  scanf("%c",&newId);  
  rut->ruterId=newId;
 
  printf("enter new flagg \n");
  scanf("%c",&newFlagg); 
  rut->FLAGG=newFlagg;
  printf("enter lenght \n");
  scanf("%c",&newLength);
  rut->length= newLength;
  printf("enter modell  \n");
  scanf("%s",newModell);
  char* tempp= strncpy(rut->modell,newModell,rut->length+3);
  mainarray[newId]= rut;
  counter++;
  free(newModell);
}
void slettRuter(int id){
  int i=id;
  while(mainarray[i+1] != NULL){
    mainarray[i]=mainarray[i+1];
    i++;
  }
  mainarray[i]= '\0'; 

}

void skriveFil(){
  int count ;
  FILE* fil=fopen("newdata.dat","w+");
 
  if(fil == NULL)
    printf("filname  \n");
  else{
    while(mainarray[count] != NULL){
      fputc(mainarray[count]->ruterId,fil);
      fputc(mainarray[count]->FLAGG,fil);
      fputc(mainarray[count]->length,fil);
      fputs(mainarray[count]->modell,fil);
  
      count++;
    }
  }
  fclose(fil);
}


void choices(){

  printf(" print info of ruter enter A \n");
  printf(" endre flag for en Id enter B \n");
  printf(" endre producent/modell enter C \n");
  printf(" legg in en ny ruter enter D \n");
  printf(" slett en ruter fra databasen enter E \n");
  printf(" to write  out file enter G \n");
  printf(" avslutte programmet enter F\n");
} 

void menu(){
  char valg;
  int id;
  printf("======MENU=======\n");
  choices();
  scanf("%s",&valg);
  
  while(valg!='F'){
  
    if(valg=='A'){
      printf("enter the id to see the informaton \n");
      scanf("%i",&id);
      printId(id);
    }
    if(valg=='B'){
      printf("enter the id to change the falgg \n");
      scanf("%i",&id);
      endreFlagg(id);
    }
    if (valg=='C'){
      printf("enter the id to change the modell \n");
      scanf("%i",&id);
      endreModell(id);
  
    }
    if(valg=='D'){
      leggInNyRuter();
    }
    if(valg=='E'){
      printf("enter the id to delet the information \n");
      scanf("%d",&id);
      slettRuter(id);
    }
    if(valg=='G')
      skriveFil();
    choices();
    scanf("%s",&valg);
  }
  
  printf(" EXITING PROGRAMM \n");
  
}

int main(int argc,char* argv[]){
  int holder=1;
  int size;
  char cast;
  int x=0; int i=0;
  

 
  
  if(argc != 2){

    fprintf(stderr,"usage %s <filename>\n",argv[0]);
    return -1;
  }

  FILE* fil=fopen(argv[1],"r");
  if(fil == NULL){
    fprintf(stderr, "couldnt open file %s \n",argv[1]);
    return -1;
  } 
  counter=fgetc(fil); 
  while(holder==1){ 
    struct rute* rut= (struct rute *) malloc (sizeof(struct rute));
    cast=fgetc(fil);
    if(cast == '\n'){
      while(!feof(fil)){

	int ss=fgetc(fil);
        rut->ruterId=ss; 
       
       
       
        rut->FLAGG=fgetc(fil);
       
        rut->length=fgetc(fil);
        
        
        char* tempp=fgets(rut->modell,(int)rut->length +20,fil);
        mainarray[rut->ruterId]=rut; 
        
	

	//if want to print out the file remove the indetation
	/**
	   printf("ID %d\n",rut->ruterId);
	   printf("flagg %d \n",rut->FLAGG);
	   printf("length %d\n",rut->length);
	   printf("modell: %s\n",rut->modell);
  
	**/
   
    
 
	i++; 
      }
      holder=0; 

    }


  }
 
    
  menu(); // after reading the file the menu will call the loop
  int inc;
  for(inc=0; mainarray[i] != NULL;i++){
    free(mainarray[i]);
  } 

 

  fclose(fil);
  return 0;
}






