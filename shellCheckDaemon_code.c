#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   
   #define true 1
   while(true){

      

      if(system(command)!=-1){
         break;
      }

   }
   free(command);

   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   FILE* fil = fopen("output.txt","r");
   // 2. Fetch line by line using getline()
   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result



   //-------------------------------------------------------- SECOND TODO IS A COPY OF shellCountLine.c-----------------------------------------------------
   ssize_t readfunc;
   
   char *ptr=NULL;
   size_t size=0;
   int counter=0;
    
    

    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
   if( fil!=NULL ){
        

    
       
        while((readfunc = getline(&ptr,&size,fil))!=-1){
            live_daemons+=1;
            fwrite(ptr, readfunc, 1, stdout);
            

        }

        

   }
   free(ptr);
   fclose(fil);
   printf("Number of daemons present are: %i\n", live_daemons);

    







//---------------------------------------------------------------------------------------------------------------------------------------------------------------





   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }


   // TODO: close any file pointers and free any statically allocated memory 

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}
