 /* filename : parser-project
 author : azzedine
 date of creation : 2021/8/4
 */
/**************************************************************
*	this is a test file for this library where you will know 
*	it will work , and you can read the readme also 
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
#include<stdio.h>
#include "parser.h"
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
	add_argument_with_help_and_action("add","a",0,INT,"this is for adding",&add,NULL,NULL,my_arguments);
	add_argument_with_help_and_action("version","v",0,BOOL,"this is for version",NULL,NULL,&version,my_arguments);
	add_argument_with_help_and_action("name","n",0,CHAR,"this is for printing name",NULL,&fun,NULL,my_arguments);
	if(manage_arguments(argc,argv,my_arguments) != 0){
		return 1;
	}

	
}
