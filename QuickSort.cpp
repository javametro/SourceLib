#include <iostream>
using namespace std;

void Qsort(int a[], int low, int high){
	if(low >= high){
		return;
	}

	int first = low;
	int last = high;
	int key = a[first];

	while(first < last){
		while(first < last && a[last] >= key) --last;
		a[first] = a[last];
		while(first < last && a[first] <= key) ++ first;
		a[last] = a[first];
	}

	a[first] = key;
	Qsort(a, low, first-1);
	Qsort(a, last+1, high);
}

void QsortTest(){
	int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8 , 10};
	int len = sizeof(a) / sizeof(a[1]) - 1;
	Qsort(a, 0, len);
	for(int i=0; i<=len; i++){
		cout << a[i] << " ";
	}

	cout << endl;
}

int main(){
	QsortTest();
	return 0;
}
