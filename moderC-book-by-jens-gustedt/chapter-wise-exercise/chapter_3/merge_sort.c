#include <stdlib.h>
#include <stdio.h>

void merge_sort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);
void print_array(int* arr, int size);

int main(int argv, char* argc[argv+1]){
  printf("Starting Merge Sort\n");

  int a[argv];
  for (int i=1; i<argv; i++){
    a[i] = atoi(argc[i]);
  }

  printf("Before Sorting\n");
  print_array(a, argv);

  merge_sort(a, 0, argv-1);
  printf("After Sorting\n");
  print_array(a, argv);
  return EXIT_SUCCESS;
}

void merge_sort(int* arr, int start, int end){
  if (start < end){
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}

void merge(int* arr, int start, int mid, int end){
  int i, j, k;
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int L[n1], R[n2];

  for (i=0; i<n1; i++){
    L[i] = arr[start + i];
  }
  for (j=0; j<n2; j++){
    R[j] = arr[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = start;

  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void print_array(int* arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

