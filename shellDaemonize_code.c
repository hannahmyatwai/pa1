/*
 * daemonize.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 60 seconds and terminates afterwards.
 */

// To test compile: gcc Daemonize.c -o summond
// ./summond
// see output at Console : search the log message or process name i.e: summond
// can check using ps aux | grep summond
// for better formatted:  ps -ejf | egrep 'STIME|summond'

#include "shellPrograms.h"

//TODO: change to appropriate path
char *path = "home/myat00/Desktop/ProgrammingAssignment1/PA1/logfile_test.txt";

/*This function summons a daemon process out of the current process*/
static int create_daemon()
{

    /* TASK 7 */
    // Incantation on creating a daemon with fork() twice
    int fd0;
    int fd1;
    int fd2;
    
    // 1. Fork() from the parent process
    pid_t pid1 = fork();
    
    if (pid1 == -1){
    	printf("Child creation failed.\n");
    }
    else if (pid1 == 0){
    	//printf("Child has successfully created.\n");
    	// 3. On child process (this is intermediate process), call setsid() so that the child becomes session leader to lose the controlling TTY
    	setsid();
    	// 4. Ignore SIGCHLD, SIGHUP
    	signal(SIGCHLD, SIG_IGN);
    	signal(SIGHUP, SIG_IGN);
    	// 5. Fork() again, parent (the intermediate) process terminates
    	pid_t pid2 = fork();
    	
    	if (pid2 == -1){
    		printf("Child creation failed.\n");
    	}
    	else if (pid2 == 0){
    		// 6. Child process (the daemon) set new file permissions using umask(0). Daemon's PPID at this point is 1 (the init)
    		umask(0);
    		// 7. Change working directory to root
    		chdir("/");
    		// 8. Close all open file descriptors using sysconf(_SC_OPEN_MAX) and redirect fd 0,1,2 to /dev/null
    		int x;
    		for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--){
    			close(x);
    		}
    		fd0 = open("/dev/null", O_RDWR);
    		fd1 = dup(0);
    		fd2 = dup(0);
    	}
    	else if (pid2 > 0){
    		exit(1);
    	}
    	
    	
    	
    } 
    else if(pid1 > 0){
    	// 2. Close parent with exit(1)
    	exit(1);
    }
    // 9. Return to main

    return 1;
}

static int daemon_work()
{

    int num = 0;
    FILE *fptr;

    //write PID of daemon in the beginning
    fptr = fopen(path, "a");
    if (fptr == NULL)
    {
        return EXIT_FAILURE;
    }

    fprintf(fptr, "%d with FD %d\n", getpid(), fileno(fptr));
    fclose(fptr);

    while (1)
    {

        //use appropriate location if you are using MacOS or Linux
        //TODO: Change to appropriate path
        fptr = fopen(path, "a");

        if (fptr == NULL)
        {
            return EXIT_FAILURE;
        }

        fprintf(fptr, "PID %d Daemon writing line %d to the file.  \n", getpid(), num);
        num++;

        fclose(fptr);

        sleep(10);

        if (num == 10)
            break;
    }

    return EXIT_SUCCESS;
}
int main(int argc, char **args)
{
    create_daemon();

    /* Open the log file */
    openlog("customdaemon", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "Daemon started.");
    closelog();

    return daemon_work();
}
