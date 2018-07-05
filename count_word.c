#include <string.h>
#include <stdio.h>
#include <ctype.h>

int wordCount(char *str){
	int flag = 0;
	int word = 0;
	int i, n;

	n = strlen(str);

	for(i=0; i<n; i++){
		if(flag == 0 && isalnum(str[i])){
			word++;
		}

		if(isalnum(str[i])){
			flag = 1;
		}else{
			flag = 0;
		}
	}

	return word;
}

int main(void){
	char str[] = "You may not do any of the following.";
	printf("string \"%s\" word count is %d\n", str, wordCount(str));
	return 0;
}
