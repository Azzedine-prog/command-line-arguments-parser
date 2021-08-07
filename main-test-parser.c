 /* filename : parser-project
 author : azzedine
 date of creation : 2021/8/4
 */
#include<stdio.h>
#include "parser.h"
#include "string.h"
void add(int number){
	printf("that number is : %d \n",number);
}
void fun(char* mychar){
	printf("char string : %s\n",mychar);
}
void version(void){
	printf("this is version 15.0.2 \n open source library \n \t made by : A Z Z E D I N E  L A K H D A R \n");
}
int main(int argc,char**argv){ 
	linked_list_string* my_arguments = argument_init();
	add_argument_with_help_and_action("add","a",1,INT,"this is for adding",&add,NULL,NULL,my_arguments);
	//print_linked_list_string(my_arguments);
	add_argument_with_help_and_action("version","v",0,BOOL,"this is for version",NULL,NULL,&version,my_arguments);
	add_argument_with_help_and_action("name","n",0,CHAR,"this is for printing name",NULL,&fun,NULL,my_arguments);
	//node_string* tmp=my_arguments->head;
	manage_arguments(argc,argv,my_arguments);
	
}
