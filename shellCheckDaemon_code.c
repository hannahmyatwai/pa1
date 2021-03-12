#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int num = system(command);
   while(true){

      if(num==-1){
         break;
      }

   }
   free(command);

   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   // 2. Fetch line by line using getline()
   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result



   //-------------------------------------------------------- SECOND TODO IS A COPY OF shellCountLine.c-----------------------------------------------------
   ssize_t readfunc;
   FILE* fp = fopen(args[1],"r");
   char *ptr=NULL;
   size_t size=0;
   

   if( fp!=NULL ){
        readfunc = getline(&ptr, &size, fp);
        while(size>0){

            counter+=1;
            readfunc = getline(&ptr, &size, fp);



        }

    }

    else{

        fclose(fp);
        return 1;




    }







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