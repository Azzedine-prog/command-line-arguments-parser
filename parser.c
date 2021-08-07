#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "string.h"
#include "linked-list.h"
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
linked_list_string* argument_init(){
    linked_list_string* new_list = malloc(sizeof(linked_list_string));
    init_linked_list_string(new_list);
    return new_list;
}
void add_argument(char* normal,char* shor_t,char required,linked_list_string* my_list){
    node_string* tmp = malloc(sizeof(node_string));
    create_node_full(tmp,normal,shor_t,required);
    append_node_string_to_list(tmp,my_list);
}
void add_argument_with_help(char* normal,char* shor_t,char required,char* help,linked_list_string* my_list){
    node_string* tmp= malloc(sizeof(node_string));
    create_node_with_help(tmp,normal,shor_t,help,required);
    append_node_string_to_list(tmp,my_list);
}
void add_argument_with_help_and_action(char* normal,char* shor_t,char required,action_type type,char* help,void (*action_int)(int),void (*action_char)(char*),void (*action_bool)(void),linked_list_string* my_list){
    node_string* tmp= malloc(sizeof(node_string));
    //create_node_with_help_and_action(tmp,normal,shor_t,help,required,action);
    create_node_with_help_and_action(tmp,normal,shor_t,help,required,type,action_int,action_char,action_bool);
    append_node_string_to_list(tmp,my_list);
}
int manage_arguments(int argc,char** argv,linked_list_string* my_arguments){
    if(argc<2){
		printf("not enough arguments\n");
		print_linked_list_string(my_arguments);
		return 1;
	}
    node_string* tmp = my_arguments->head;
	for(int i =0;i<(my_arguments->len);i++){
		for(int j=0;j<argc;j++){
			//printf("--> %s\n",argv[i]+2);
			if(str_cmp((argv[j])+2,tmp->self)==1){
				//printf("--> %s\n",(argv[j])+2);
				tmp->index = j;
                tmp->status = True;
				//printf("hell yeah\n");
			}
		}
		tmp = tmp->next;
	}
    tmp = my_arguments->head;
    for(int i=0;i<my_arguments->len;i++){
    if(tmp->required == 1){
        if(tmp->status == False){
            printf("argument %s is required\n",tmp->self);
            return 1;
        }
    }
    /*else
        printf("not required\n");*/
    tmp = tmp->next;
    }
    tmp = my_arguments->head;
	for(int i=0;i<my_arguments->len;i++){
		//printf("index : %d \n",tmp->index);
		if(((tmp->index) != 0) && ((tmp->data_fullness) == 4)){
            if(tmp->type == INT){
			(*(tmp->action_int))(((string_to_int(argv[(tmp->index)+1]))));
			//printf("hooyah : %s\n",(argv[(tmp->index)+1]));
            }
            if(tmp->type == CHAR){
			(*(tmp->action_char))(argv[(tmp->index)+1]);
			//printf("hooyah : %s\n",(argv[(tmp->index)+1]));
            }
            if(tmp->type == BOOL){
			(*(tmp->action_bool))();
			//printf("hooyah :\n");
            }
		}
		/*else if(((tmp->index) != 0) && ((tmp->data_fullness) == 3)){
			printf("hooyah %s : %s\n",(tmp->self),(argv[(tmp->index)+1]));
		}*/
		tmp = tmp->next;
	}
return 0;
}