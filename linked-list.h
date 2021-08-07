#ifndef SIZE_STRING
#define SIZE_STRING 8
#endif
#ifndef SIZE_DETAIL
#define SIZE_DETAIL 40
#endif
#ifndef NODE
#define NODE 1
#include "boolean-lib.h"
/**************************************************************
*   you can read the readme for more documents .
*	this library is just made by me (amateur) not that professional 
*	feel free to contribute or suggest or help when you find any 
*	fix or upgrade for this modest project .
*	
*	author : AZZEDINE LAKHDAR
*	 EMBEDDED SYSTEMS student 
*		8/7/2021
*						thanks for using this .    .
											   .  .
											    ..
*****************************************************************/
typedef enum action_type{
INT,BOOL,FLOAT,CHAR
}action_type;
typedef struct node_string{
    char* self;
    char* short_self;
    char* detail;
    struct node_string* next;
    char data_fullness;
    char required;
    void (*action_int)(int);
    void (*action_char)(char*);
    void (*action_bool)(void);
    bool status;
    int index;
    action_type type;
}node_string;
typedef struct linked_list_string{
    node_string* head;
    node_string* tail;
    int len;
}linked_list_string;

void init_linked_list_string(linked_list_string* my_linked_list);
void append_node_string_to_list(node_string* my_node,linked_list_string* my_linked_list);
void print_linked_list_string(linked_list_string* my_linked_list);
void create_node(node_string* tmp,char* short_self,char required);
void create_node_full(node_string* tmp,char* self,char* short_self,char required);
void create_node_with_help(node_string* tmp,char* self,char* short_self,char* detail,char required);
int create_node_with_help_and_action(node_string* tmp,char* self,char* short_self,char* detail,char required,action_type type,void (*action_int)(int),void (*action_char)(char*),void (*action_bool)(void));
node_string* get_node_by_self(char* self,linked_list_string* mylist);
#endif