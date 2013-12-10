/* 
 * File:   log_file_handler.h
 * Author: sig2
 * 
 * Description: Defines functions used to facilitate event message display and 
 * appending to a log file.
 * 
 * Created December 2013
 */

#ifndef LOG_FILE_HANDLER_H
#define	LOG_FILE_HANDLER_H

/*Function prototype for the initial logging function*/
void start_logging();
/*Function prototype for the function that outputs a message to stdout 
 and file*/
void output_event(char * message);
#endif	/* LOG_FILE_HANDLER_H */

