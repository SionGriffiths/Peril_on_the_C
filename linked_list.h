/* 
 * File:   linked_list.h
 * Author: sig2
 *
 * Created on 09 December 2013, 15:15
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

 typedef struct link_node{
    void* node_data;
    struct link_node * next;
  }node;
  
  typedef struct node_list{
    node* head;
    node* tail;
  }linked_list;
  
  typedef node * node_ptr;
  typedef linked_list * list_ptr;

  void add_to_list(node_ptr * to_add, list_ptr * list);
  void init_node(node_ptr * new_node ,void* in_data);
  void init_list(list_ptr * list);

#ifdef	__cplusplus
}
#endif

#endif	/* LINKED_LIST_H */

