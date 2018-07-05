int compare(const void *str1, const void* str2){
	char cmp1[MaxLen*2 + 1];
	char cmp2[MaxLen*2 + 1];
	strcpy(cmp1, *(char **)str1);
	strcat(cmp1, *(char **)str2);
	strcpy(cmp2, *(char **)str2);
	strcat(cmp2, *(char **)str1);
		
	return strcmp(cmp1, cmp2);
}

void GetLinkMin(int a[], int len){
	char **str = (char **)new int[len];
	for(int i=0; i<len; i++){
		str[i] = new char[MaxLen + 1];
		sprintf(str[i], "%d", a[i]);
	}

	qsort(str, len, sizeof(char *), compare);
	for(int i=0; i<len; i++){
		cout << str[i] << " ";
		delete[] str[i];
	}

	delete[] str;
}

void GetLinkMinTest(){
	int arr[] = {123, 132, 213, 231, 321, 312};
	GetLinkMin(arr, sizeof(arr) / sizeof(int));
}
