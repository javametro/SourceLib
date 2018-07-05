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
	for(int i=0; i<cmpCount; i++){
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
