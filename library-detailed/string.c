#include "string.h"
#include "math.h"
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