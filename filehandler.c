#include <stdio.h>
//Make this take a resource struct - fscanf the things!
int read_resources_file(char * resrouces_filename) {

  FILE * resources_file;

  resources_file = fopen(resrouces_filename, "r");

  int read_status;

  if (resources_file != NULL) {

    read_status = fscanf(resources_file);

    while (read_status != EOF) {
        
    }

  } else {
    printf("Failed to open resources file \n");
    return NULL;
  }

  fclose(resources_file);

}
