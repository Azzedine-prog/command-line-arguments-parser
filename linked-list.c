#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"
#include "string.h"
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
void init_linked_list_string(linked_list_string* my_linked_list){
    /*my_linked_list->head = malloc(sizeof(node_string));
    my_linked_list->tail = malloc(sizeof(node_string));
   (my_linked_list->head)->next = my_linked_list->tail ;
    (my_linked_list->head)->self = malloc(SIZE_STRING*sizeof(char));
    (my_linked_list->tail)->next = my_linked_list->head;
    (my_linked_list->tail)->self = malloc(SIZE_STRING*sizeof(char));*/
    my_linked_list->len = 0;
}
void append_node_string_to_list(node_string* my_node,linked_list_string* my_linked_list){
    if(my_linked_list->len == 0){
        my_linked_list->head = my_node;
        my_node->next = my_node;
        my_linked_list->len =my_linked_list->len + 1;
    }
    else if(my_linked_list->len == 1){
        my_linked_list->tail = my_node;
        (my_linked_list->head)->next = my_node;
        my_linked_list->len =my_linked_list->len + 1;
    }
    else{
        (my_linked_list->tail)->next = my_node;
        my_node->next = my_linked_list->head;
        my_linked_list->tail = my_node;
        my_linked_list->len = my_linked_list->len + 1;
    }
}
void print_linked_list_string(linked_list_string* my_linked_list){
    int i;
    node_string* tmp;
    tmp = (my_linked_list->head);
    printf("this is a help about this program showed if arg is -h or --help\n");
    for(i=0;i<(my_linked_list->len);i++){
        if(tmp->type == INT)
        printf("\t %s : --%s [integer] or -%s [integer]\n",tmp->detail,tmp->self,tmp->short_self);
        if(tmp->type == CHAR)
        printf("\t %s : --%s [string] or -%s [string]\n",tmp->detail,tmp->self,tmp->short_self);
        if(tmp->type == BOOL)
        printf("\t %s : --%s or -%s\n",tmp->detail,tmp->self,tmp->short_self);
        //printf("%s | ",tmp->self);
        tmp = tmp->next;
    }
    printf("\n");

}
void init_node(node_string* mynode){
    mynode->self = malloc(SIZE_STRING*sizeof(char));
}
void create_node(node_string* tmp,char* short_self,char required){
    //tmp=malloc(sizeof(node_string));
    tmp->self = malloc(SIZE_STRING*sizeof(char));
    str_cp(tmp->short_self,short_self);
    tmp->data_fullness = 1;
    tmp->index = 0;
}
void create_node_full(node_string* tmp,char* self,char* short_self,char required){
    //tmp=malloc(sizeof(node_string));
    tmp->self = malloc(SIZE_STRING*sizeof(char));
    tmp->short_self = malloc(SIZE_STRING*sizeof(char));
    str_cp(tmp->short_self,short_self);
    str_cp(tmp->self,self);
    tmp->data_fullness = 2;
    tmp->index = 0;
}
void create_node_with_help(node_string* tmp,char* self,char* short_self,char* detail,char required){
    //tmp=malloc(sizeof(node_string));
    tmp->self = malloc(SIZE_STRING*sizeof(char));
    tmp->short_self = malloc(SIZE_STRING*sizeof(char));
    tmp->detail = malloc(SIZE_DETAIL*sizeof(char));
    str_cp(tmp->short_self,short_self);
    str_cp(tmp->self,self);
    str_cp(tmp->detail,detail);
    tmp->data_fullness = 3;
    tmp->index = 0;
}
int create_node_with_help_and_action(node_string* tmp,char* self,char* short_self,char* detail,char required,action_type type,void (*action_int)(int),void (*action_char)(char*),void (*action_bool)(void)){
    //tmp=malloc(sizeof(node_string));
    tmp->self = malloc(SIZE_STRING*sizeof(char));
    tmp->short_self = malloc(SIZE_STRING*sizeof(char));
    tmp->detail = malloc(SIZE_DETAIL*sizeof(char));
    //tmp->action = action;
    tmp->type = type;
    if(type == INT){
        if(action_int)
        tmp->action_int = action_int;
        else
        return 0;
    }
    else if(type == CHAR){
        if(action_char)
        tmp->action_char = action_char;
        else
        return 0;
    }
    else if(type == BOOL){
        if(action_bool)
        tmp->action_bool = action_bool;
        else
        return 0;
    }
    else 
        return 0;
    tmp->status = False;
    tmp->required = required;
    str_cp(tmp->short_self,short_self);
    str_cp(tmp->self,self);
    str_cp(tmp->detail,detail);
    tmp->data_fullness = 4;
    tmp->index = 0;
    return 1;
}
node_string* get_node_by_self(char* self,linked_list_string* mylist){
    node_string* tmp = mylist->head;
    while(tmp->next != mylist->head){
        if((str_cmp(tmp->self,self) == 1) || (str_cmp(tmp->short_self,self) == 1)){
            //printf("i have found it\n");
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}
/*int main(){
    linked_list_string* new_list = malloc(sizeof(linked_list_string));
    node_string* head=create_node("firsto");
    node_string* tail=create_node("secondo");
    node_string* first_node=create_node("thirdo");
    append_node_string_to_list(head,new_list);
    append_node_string_to_list(tail,new_list);
    print_linked_list_string(new_list);
    append_node_string_to_list(first_node,new_list);
    print_linked_list_string(new_list);
}*/