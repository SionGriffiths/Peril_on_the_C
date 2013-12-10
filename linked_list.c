/* 
 * File:   linked_list.c
 * Author: sig2
 * 
 * Description : Specifies linked list functionality. Initialises nodes and lists
 * and defines how nodes are added to lists.
 *               
 * Created December 2013
 */

#include "linked_list.h"
#include <stdlib.h>

/*Adds the passed in node to the list, list also passed via paramater
 */
void add_to_list(node_ptr * to_add, list_ptr * list) {

  //Check the list is empty
  if ((*list)->head == NULL) {

    //first item in a list added to both head and tail
    (*list)->head = (*to_add);
    (*list)->tail = (*to_add);

  } else {
    
    /*Hold the current tail, add the new node to it's next,
     set tail to be the new node.*/
    node * old_tail = (*list)->tail;
    old_tail->next = (*to_add);
    (*list)->tail = (*to_add);

  }

}

/*Initialises a node; allocates memory, populates the node with 
 * passed in data, set default values.
 */
void init_node(node_ptr * new_node, void* in_data) {
  (*new_node) = calloc(1, sizeof (struct link_node));
  (*new_node)->next = NULL;
  (*new_node)->node_data = in_data;
}

/*Initialises a linked list; allocates memory and set
 default values
 */
void init_list(list_ptr * list) {
  (*list) = calloc(1, sizeof (struct node_list));
  (*list)->head = NULL;
  (*list)->tail = NULL;
}
