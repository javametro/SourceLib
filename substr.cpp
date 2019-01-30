#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int substr(const char* source, const char* sub){
	if(source == NULL || sub == NULL){
		return -1;
	}

	int souLen = strlen(source);
	int subLen = strlen(sub);
	if(souLen < subLen){
		return -1;
	}

	int cmpCount = souLen - subLen;
	for(int i=0; i<=cmpCount; i++){
		int j= 0;
		for(; j<subLen; j++){
			if(source[i+j] != sub[j]){
				break;
			}
		}

		if(j == subLen){
			return i;
		}
	}

	return -1;
}

int main(){
	const char *test = "Hello World";
	const char *target = "World";
	int result = substr(test, target);
	cout << result << endl;
	return 0;	
}
