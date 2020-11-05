#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<sys/wait.h> 

int main (int argc, char **argv) {
  int pipefd[2];
  int pipefd2[2];
  int pid, pid2;

   char *cat_args[] = {"cat", "scores", NULL};
  
  
  char *grep_args_args[] = {"grep", argv[1], NULL};
  
  
  char *sort_args[] = {"sort", NULL};
 
  if( pipe(pipefd) == -1 ) {
      fprintf(stderr, "The Pipe Failed" );
      return 1; 
   }
  if( pipe(pipefd2 == -1) ) {
      fprintf(stderr, "The Pipe Failed" );
      return 1;
   }
   
   pid = fork();

if (pid == 0){
       pid2 = fork();
       if (pid2 == 0) {
         dup2(pipefd2[0], 0);
         
         close(pipefd[1]);
         close(pipefd[0]);
         
         close(pipefd2[1]);
         close(pipefd2[0]);
         
         execvp(sort_args[0], sort_args);
         
       } else{
         
         //dup2(pipefd[0], 0);
         dup2(pipefd2[1],1);
         
         close(pipefd[1]);
         close(pipefd[0]);
         
         close(pipefd2[1]);
         close(pipefd2[0]);
         
         execvp("28", grep_args);
       }

}
  //else {
  //dup2(pipefd[1],1);
  //
  //              close(pipefd[0]);
  //              close(pipefd[1]);
  //
  //            close(pipefd2[0]);
  //              close(pipefd2[1]);
  //
  // execvp("cat", cat_args);

//}
}  
