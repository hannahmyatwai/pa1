#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    ssize_t readfunc;
    FILE* fp = fopen(args[1],"r");
    char **ptr;
    size_t *size;
    int counter;
    
    

    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if( fp ){
        readfunc = getline(**ptr, *size, fp);
        while(readfunc==1 || readfunc==6){

            counter+=1;



        }

    }

    else{

        fclose(fp);
        return 1;




    }



    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    // 6. Close the FILE*
    // 7. Print out how many lines are there in this particular filename
    // 8. Return 1, to exit program

    
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}