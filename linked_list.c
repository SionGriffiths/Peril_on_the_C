
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

  }

}

void init_node(node_ptr * new_node, void* in_data) {
  (*new_node) = calloc(1, sizeof (struct link_node));
  (*new_node)->next = NULL;
  (*new_node)->node_data = in_data;
}

void init_list(list_ptr * list) {
  (*list) = calloc(1, sizeof (struct node_list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
}
