/* 
 * File:   log_file_handler.c
 * Author: sig2
 * 
 * Description: Specifies functionality related to logging events during the 
 * course of program execution.
 * 
 * Created December 2013
 */


#include <stdio.h>
#include <stdlib.h>

/*log_file needs file wide scope - 
 * static to prevent global access*/
static FILE * log_file; 

/*Initial logging function called at start of program execution.
 Provides the means to easily distinguish program runs in the log file*/
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

/*Prints the parameter message to file and stdout*/
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
