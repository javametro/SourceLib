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
