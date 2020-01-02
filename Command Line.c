/*
    author Ariya Rasekh <ariya.rasekh@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void parse(char *buf, char **args);
void execute(char **args);
char *gets(char *s);

int main(int argc, char *argv[])
{
    char buf[1024];
    char *args[64];

    for (;;) {
        /*
         * Prompt for and read a command.
         */
        printf("Command: ");

        if (fgets(buf,1024,stdin) == NULL) {
            printf("\n");
            exit(0);
        }

        /*
         * Split the string into arguments.
         */
        parse(buf, args);

        /*
         * Execute the command.
         */
        execute(args);
    }
}

/*
 * parse--split the command in buf into
 *         individual arguments.
 */
void parse(char *buf, char **args)
{
    while (*buf != '\0') {
        /*
         * Strip whitespace.  Use nulls, so
         * that the previous argument is terminated
         * automatically.
         */
        while ((*buf == ' ') || (*buf == '\t'))
            *buf++ = '\0';

        /*
         * Save the argument.
         */
        *args++ = buf;

        /*
         * Skip over the argument.
         */
        while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))
                    buf++;
            }

            *args = NULL;
        }

        /*
         * execute--spawn a child process and execute
         *           the program.
         */
        void execute(char **args)
        {
            id_t pid;
            
            if((pid=fork())<0)
                 perror("unable to fork");

            if (pid==0){ /*child*/
                execl("/bin/bash", "bash", "-c", *args, (char*)0);
                perror("excel");
                    exit(1);
            }

            //code for parent
            wait((int *)0);
            
        }

