int binarySearchString(char arr[][10], int n, char target[]){
	int min = 0, max = n-1;
	while(min <= max){
		int mid = (min + max)/2;
		if (stricmp(target, arr[mid])<0){
			max = mid-1;
		}else if (stricmp(target,arr[mid])>0){
			min = mid+1;
		}else return mid;
	}
	return -1;
}
