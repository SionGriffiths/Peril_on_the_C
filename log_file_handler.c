//fprintf to append


#include <stdio.h>
#include <stdlib.h>

static FILE * log_file;

void start_logging(){
  log_file = fopen("log.txt", "a");
  
  if(log_file == NULL){
    printf("Error opening log file");
    
  }
  else{
    fprintf(log_file, "\n\n######\tLog Entry Start\t##### \n");
  }
}

FILE * get_log_file(){
  return log_file;
}

void end_logging(){
  fclose(log_file);
}