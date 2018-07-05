int Find1Count(int num){
	if(num == 0){
		return 0;
	}

	int count = 1;
	while(num = num & (num - 1)){
		count ++;
	}

	return count;
}
