#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
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
    int argument_number_with_parameter=0;
    node_string* tmp = my_arguments->head;
	for(int i =0;i<(my_arguments->len);i++){
		for(int j=0;j<argc;j++){
			//printf("--> %s\n",argv[i]+2);
			if((str_cmp((argv[j])+2,tmp->self)==1) || (str_cmp((argv[j])+1,tmp->short_self)==1) ){
				//printf("--> %s\n",(argv[j])+2);
				tmp->index = j;
                tmp->status = True;
                if((tmp->type == INT) || tmp->type == CHAR)
                    argument_number_with_parameter = argument_number_with_parameter +2;
                else 
                    argument_number_with_parameter = argument_number_with_parameter +1;
				//printf("hell yeah\n");
			}
		}
		tmp = tmp->next;
	}
    if(argc != (argument_number_with_parameter+1)){
        printf("\t some arguments need paramaters \n");
        print_linked_list_string(my_arguments);
        return 1;
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
                tmp->int_value = string_to_int(argv[(tmp->index)+1]);
			//printf("hooyah : %s\n",(argv[(tmp->index)+1]));
            }
            if(tmp->type == CHAR){
			    (*(tmp->action_char))(argv[(tmp->index)+1]);
                tmp->string = argv[(tmp->index)+1];
			//printf("hooyah : %s\n",(argv[(tmp->index)+1]));
            }
            if(tmp->type == BOOL){
                (*(tmp->action_bool))();
                tmp->bool_value = True;
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
        printf("\t--> %s : --%s [integer] or -%s [integer]\n",tmp->detail,tmp->self,tmp->short_self);
        else if(tmp->type == CHAR)
        printf("\t--> %s : --%s [string] or -%s [string]\n",tmp->detail,tmp->self,tmp->short_self);
        else if(tmp->type == BOOL)
        printf("\t--> %s : --%s or -%s\n",tmp->detail,tmp->self,tmp->short_self);
        //printf("%s | ",tmp->self);
        tmp = tmp->next;
    }
    //printf("\n");

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
	tmp->status = False;
    tmp->required = required;
    str_cp(tmp->short_self,short_self);
    str_cp(tmp->self,self);
    str_cp(tmp->detail,detail);
    tmp->data_fullness = 4;
    tmp->index = 0;
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
    return 1;
}
node_string* get_node_by_self(char* self,linked_list_string* mylist){
    node_string* tmp = mylist->head;
	int i = 0;
    while(i<(mylist->len)){
        if((str_cmp(tmp->self,self) == 1) || (str_cmp(tmp->short_self,self) == 1)){
            //printf("i have found it\n");
            return tmp;
        }
        tmp = tmp->next;
		i++;
    }
    return NULL;
}
int po_w(int base,int power){
  int output = 1;
  for(int i=0;i<power;i++){
    output *= base;
  }
  return output;
}
void str_cp(char* destination,char* source){
  char *tmp_source = source,*tmp_destination = destination;
  //printf("%s\n", source);
  while(*tmp_source != '\0'){
    *tmp_destination = *tmp_source;
    //printf("destination = %c,source = %c\n",*tmp_destination,*tmp_source );
     tmp_destination++;
     tmp_source++;
  }
  *tmp_destination = '\0';
  //printf("destination = %s\n",destination);
}
char str_cmp(char* destination,char* source){
  char *tmp_source = source,*tmp_destination=destination;
  while(*tmp_destination != '\0'){
    if(*tmp_destination != *tmp_source)
      return 0;
     tmp_destination++;
     tmp_source++;
  }
  if(*tmp_source != '\0')
    return 0;
  return 1;
}
int le_n(char* string){
	int output=0;
	char* tmp_string = string;
	while(*tmp_string != '\0'){
		//printf("char : %c\n",*tmp_string);
		output++;
		tmp_string++;
	}
	return output;
}
int string_to_int(char* number_string){
  char* tmp_number = number_string;
  int number_int=0,i=0,len=0;
  len = le_n(number_string);
  //printf("before %d len of %s : %d\n",len,number_string,le_n(number_string)/2);
  for(i=len-1;i>-1;i--){
	//printf("char as char: %c\n",*tmp_number);
	//printf("char as int : %d\n",((int)(*(tmp_number)))-48);
	number_int = number_int + (((int)(*(tmp_number))-48))*po_w(10,i);    
  	//printf("char after power : %d\n",number_int);
	//i=i+1;
	tmp_number = tmp_number+1;
  }
  return number_int;
}