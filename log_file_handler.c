//fprintf to append


#include <stdio.h>
#include <stdlib.h>

static FILE * log_file;

void start_logging(){
  log_file = fopen("log_Main.txt", "a");
  
  if(log_file == NULL){
    printf("Error opening log file");
    
  }
  else{
    fprintf(log_file, "\n\n######\tLog Entry Start\t##### \n");
  }
  
  fclose(log_file);
}

void output_event(char * message){
  
  log_file = fopen("log_Main.txt", "a");
  
  if(log_file == NULL){
    printf("Error opening log file");
    
  }
  else{
    fprintf(log_file, "%s", message);
    printf("%s", message);
  }
  
  fclose(log_file);
  
}
/*
FILE * get_log_file(){
  return log_file;
}

void end_logging(){
  fclose(log_file);
}
  */