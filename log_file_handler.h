/* 
 * File:   log_file_handler.h
 * Author: sig2
 * Description: Defines functions used to facilitate event logging to a text file.
 * Created December 2013
 */

#ifndef LOG_FILE_HANDLER_H
#define	LOG_FILE_HANDLER_H

void start_logging();
FILE * get_log_file();
void end_logging();
#endif	/* LOG_FILE_HANDLER_H */

