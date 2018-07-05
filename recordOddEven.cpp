void RecordOddEven(int A[], int len){
	int i=0, j = len - 1;
	while(i < j){
		while(i<len && A[i] % 2 == 1)
			i++;

		while(j>=0 && A[j] % 2 == 0)
			j--;

		if(i<j){
			A[i] ^= A[j] ^= A[i] ^= A[j];
		}
	}
}

void RecordOddEvenTest(){
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11};
	int len = sizeof(A) / sizeof(A[0]);
	RecordOddEven(A, len);
	for(int i=0; i<len; i++){
		cout << A[i] << " ";
	}

	cout << endl;

	for(int i=0; i<len; i++){
		A[i] = 2;
	}

	RecordOddEven(A, len);
	for(int i=0; i<len; i++){
		cout << A[i] << " ";
	}

	cout << endl;
	
	for(int i=0; i<len; i++){
		A[i] = 1;
	}

	RecordOddEven(A, len);

	for(int i=0; i<len; i++){
                A[i] = 1;
        }
}
