#include<stdio.h>
#include<string.h>

struct dest{
	char city[100];
	int price;
};


//use this sample
//3000
//newyork
//9000
//new jersey
//4000
//texas

void bubbleSort(struct dest *deslist, int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(deslist[j].price > deslist[j+1].price){
				dest temp = deslist[j];
				deslist[j] = deslist[j+1];
				deslist[j+1] = temp;
			}
		}
	}
}

void merge(struct dest *deslist, int left, int mid, int right){
	int n = right-left+ 1;
	struct dest tempList[n];
	int i = left, j = mid+1, k = 0;
	while(i <= mid && j <= right){
		if(deslist[i].price > deslist[j].price){
			tempList[k++] = deslist[i++];
		}
		else{
			tempList[k++] = deslist[j++];
		}
	}
	while(i<=mid){
		tempList[k++] = deslist[i++];
	}
	while(j<=right){
		tempList[k++] = deslist[j++];
	}
	int ind = 0;
	for(int i=left; i<=mid; i++){
		deslist[i] = tempList[ind++];
	}
	for(int j=mid+1; j<=right; j++){
		deslist[j] = tempList[ind++];
	}
}

void mergeSort(struct dest *list, int left, int right){
	if(left < right){
		int mid = (left + right)/2;
		mergeSort(list, left, mid);
		mergeSort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	dest desList[n];
	for(int i=0; i<n; i++){
		scanf("%d", &desList[i].price);
		getchar();
		scanf("%[^\n]", &desList[i].city);
		getchar();
	}
	for(int i=0; i<n; i++){
		printf("%d %s\n", desList[i].price, desList[i].city);
		
	}
	char sort[10];
	do{
		puts("what sort u want to use?");
		scanf("%[^\n]", &sort);
		getchar();
		if((strcmpi(sort, "simple") == 0)){
			bubbleSort(desList, n);
//			for(int i=0; i<n; i++){
//					for(int j=n-1; j>=0; j--){
//			if(desList[j].price > desList[j+1].price){
//				dest temp = desList[j];
//				desList[i] = desList[j+1];
//				desList[j+1] = temp;
//			}
//		}
//	}
		}
		else if(strcmpi(sort, "advance") == 0){
//			puts("sucess");
			mergeSort(desList, 0, n-1);	
		}
	}while(strcmpi(sort, "simple") != 0 && strcmpi(sort, "advance") != 0);
	for(int i=0; i<n; i++){
		printf("%d %s\n", desList[i].price, desList[i].city);
		
	}
	return 0;
}
