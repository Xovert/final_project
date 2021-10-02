
void merge (int arr[], int left, int mid, int right){
	//initialize 
	int i,j,k;
	int n1 = mid - left + 1	;
	int n2 = right - mid; 
	
	/*create temp arrays >>buat tempat kosong untuk menampung
	 right size,left size*/
	int Left[n1], Right[n2];
	
	/*Masukkan data ke temp arrays left[] & right[]*/
	for(int a = 0 ; a < n1 ; a++){
		Left[a]= arr[left + a];
	}	
	for(int b = 0 ; b < n2 ;b++){
		Right[b]= arr[mid + 1 + b];
	}	
	//gabungin array dari array left dan right
	i = 0 ; //inisial index sub array pertama 
	j = 0 ; // inisial index sub array kedua 
	k = left; //inisial index pengabungan 
	while(i < n1 && j < n2){
		if(Left[i] < Right[j]){
			arr[k] = Left[i];
			i++;
			
		}else
		{
			arr[k] = Right[j];
			j++;
			
		}
		k++;
	}	
	//Masukkan elemen yang tersisa dari left[] & right[], jika ada	
	while(i < n1 ){
		arr[k] = Left[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = Right[j];
		j++;
		k++;
	}	
		
		
		
}

//pertama buat fungsi ini dulu untuk membagi 2 data array, dan rekursif untuk memanggil mergeSort
void mergeSort(int arr[], int left, int right){
	if(left >= right){
		return;
	}
	int mid = left+(right - left)/2; //untuk membagi data menjadi 2
	//sort first and scond halves
	mergeSort (arr, left, mid);
	mergeSort (arr, mid + 1, right );
	
	merge(arr, left, mid, right);
} 

//funtion untuk print array
void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    puts("");
}

