/*Write the following two sorting functions

   

      1. Fastest sorting algorithm that you know

      2. Second fastest sorting algorithm that you know

 

     compare them by sorting 100000 randomly generated integers in range 1 to 100 & also print the time taken by both of them.*/
#include<iostream>
#include <algorithm> 
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
int partition (int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h- 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            i++; 
            swap (&arr[i], &arr[j]); 
        } 
    } 
    swap (&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
void quickSort(int A[], int l, int h) 
{ 
    if (l < h) 
    {      
        int p = partition(A, l, h);  
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h); 
    } 
      
} 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {  
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int main()
{
int ar1[100],ar2[100],i;
srand(time(NULL));
int min = 1;
int max = 100; 
for(i=0;i<100;i++)
{
ar1[i] = (min + (rand() % (int)(max - min + 1)));
ar2[i] = (min + (rand() % (int)(max - min + 1)));
}
clock_t begin_time,end_time,elapsed_time,begin_time2,end_time2,elapsed_time2;
begin_time = clock();
quickSort(ar1, 0, 99); 
end_time = clock();
elapsed_time = end_time - begin_time;
double time_taken=((double)elapsed_time) / CLOCKS_PER_SEC;
cout<<"time taken by quick sort:" << time_taken<<"miliseconds\n";
begin_time2 = clock();
mergeSort(ar2, 0, 99);
end_time2 = clock();
elapsed_time2 = end_time2 - begin_time2;
double time_taken2=((double)elapsed_time2) / CLOCKS_PER_SEC;
cout<<"time taken by quick sort:" << time_taken2<<"miliseconds\n";
for(i=0;i<100;i++)
{
	cout<<ar1[i]<<"\t"<<ar2[i]<<"\n";
}
return 0; 
}
