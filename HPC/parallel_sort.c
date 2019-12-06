#include<stdio.h>
#include<omp.h>
#define ll long long int

void  bubblesort(ll size) {
	ll arr[size];
	//ll t=size;
	#pragma omp for
	for(ll i=0;i<size-1;++i) {
		arr[i]=size-i;
	}
	double start_Serial = omp_get_wtime();
	for(ll i=0;i<size-1;++i) {
		for(ll j=i+1;j<size;++j) {
			if(arr[i] > arr[j]) {
				ll temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nSerial time : %f",(omp_get_wtime()-start_Serial));
	
}

void parallelsort(ll size) {
	ll arr[size];
	#pragma omp for
	for(ll i=0;i<size-1;++i) {
		arr[i]=size-i;
	}
	double start_Serial = omp_get_wtime();
	
	for(ll i=0;i<(size/2)+1;++i) {
		
		#pragma omp for
		for(ll j=0;j<size-1;j+=2) {
			if(arr[j] > arr[j+1]) {
				ll temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		#pragma omp for
		for(ll j=1;j<size-1;j+=2) {
			if(arr[j] > arr[j+1]) {
				ll temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nSerial time : %f",(omp_get_wtime()-start_Serial));
}
int main() {
	ll size,n;
	printf("\nEnter the size of array : ");
	scanf("%lld",&size);
	
	printf("\nenter choice 0 or 1:");
	scanf("%lld",&n);
	
	if(!n) 
		bubblesort(size);
	else
		parallelsort(size);
}
