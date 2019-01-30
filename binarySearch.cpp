#include <iostream>
using namespace std;

int binarySearch(int a[], int len, int val){
	int start = 0;
	int end = len - 1;
	int index = -1;
	
	while(start <= end){
		index = start + (end -start) /2 ;
		if(a[index] == val){
			return index;
		}else if(a[index] < val){
			start = index + 1;
		}else{
			end = index - 1;
		}
	}

	return -1;
}

int main(){
	int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 19};
//	cout << sizeof(a) / sizeof(a[0]) << endl;
	int result = binarySearch(a, sizeof(a)/sizeof(a[0]), 11);
	cout << result << endl;

	return 0;
}
