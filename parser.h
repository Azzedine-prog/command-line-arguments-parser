#include "linked-list.h"
linked_list_string* argument_init(void);
void add_argument(char* normal,char* shor_t,char required,linked_list_string* my_list);
void add_argument_with_help(char* normal,char* shor_t,char required,char* help,linked_list_string* my_list);
void add_argument_with_help_and_action(char* normal,char* shor_t,char required,action_type type,char* help,void (*action_int)(int),void (*action_char)(char*),void (*action_bool)(void),linked_list_string* my_list);
int manage_arguments(int argc,char** argv,linked_list_string* my_arguments);