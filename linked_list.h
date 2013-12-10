/* 
 * File:   linked_list.h
 * Author: sig2
 * 
 * Description : Defines the structure of a linked list and linked list
 *  nodes which accept generic pointers to data.
 * Specifies functions for initialising nodes, linked lists and adding
 * nodes to lists.
 *               
 * Created December 2013
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

  typedef struct link_node {
    void* node_data;
    struct link_node * next; 
  } node;

  
  typedef struct node_list {
    node* head;
    node* tail;
  } linked_list;

  typedef node * node_ptr;
  typedef linked_list * list_ptr;

  /*Function prototype for function that adds nodes to a list*/
  void add_to_list(node_ptr * to_add, list_ptr * list);
  
  /*Function prototype for function that initialises a list node*/
  void init_node(node_ptr * new_node, void* in_data);
  
  /*Function prototype for function that initialises a linked list*/
  void init_list(list_ptr * list);

#ifdef	__cplusplus
}
#endif

#endif	/* LINKED_LIST_H */

