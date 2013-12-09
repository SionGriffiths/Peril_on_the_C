
#include "linked_list.h"
#include <stdlib.h>

void add_to_list(node_ptr * to_add, list_ptr * list) {

  if ((*list)->head == NULL) {
    (*list)->head = (*to_add);
    (*list)->tail = (*to_add);

  } else {

    node * old_tail = (*list)->tail;
    old_tail->next = (*to_add);
    (*list)->tail = (*to_add);

    /*node_ptr iterate = (*list)->head;
    while (iterate != NULL) {
      
      if (iterate->next == NULL) {
        iterate->next = (*to_add);
        break;
      }
    }
    iterate = iterate -> next;*/
  }

}

void init_list(list_ptr * list) {
  (*list) = malloc(sizeof (list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
}
