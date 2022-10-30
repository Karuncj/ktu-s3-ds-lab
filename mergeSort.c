/************************************************************************
 * File         :   mergeSort.c
 * Description  :   C Program to  implement merge sort algorithm
 * Author       :   Tomin Joy
 * Version      :   1.0
 * Date         :   17/01/2022
 ************************************************************************/

#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	i = 0; 
	j = 0;
	k = left; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		int mid = (left + right ) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void main(){
    int a[20],size;
    printf("Enter the number of elements : ");
    scanf("%d",&size);
    printf("Enter the elements : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Before sorting..\n");
    printArray(a,size);
    mergeSort(a, 0,size-1);
    printf("After sorting..\n");
    printArray(a, size);
}
