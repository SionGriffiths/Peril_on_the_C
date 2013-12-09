
#include "linked_list.h"
#include <stdlib.h>



void add_to_list(void* to_add, list_ptr list ){
  
  node* iterate = list->head;

  if (list->head == NULL) {
    list->head->node_data = to_add;

  } else if (list->head->next == NULL) {
    list->head->next = to_add;

  } else {
    while (iterate != NULL) {
      if (iterate -> next == NULL) {
        iterate -> next = to_add;

        break;
      }
      iterate = iterate -> next;
    }
  }
}
