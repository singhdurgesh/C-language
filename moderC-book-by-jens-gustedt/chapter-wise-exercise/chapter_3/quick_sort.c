#include <stdlib.h>
#include <stdio.h>

void quick_sort(int* arr, int start, int end);
int partition_array(int* arr, int start, int end, int pivot);
void merge(int* arr, int start, int mid, int end);
void test_array(int* arr, int size);
int* test_case_generator(int size);
void print_array(int* arr, int size);

int main(int argv, char* argc[argv+1]){
  printf("Starting Quick Sort\n");

  int a[argv];
  for (int i=1; i<argv; i++){
    a[i] = atoi(argc[i]);
  }

  for(int i=0; i<5; i++){
    int* test_case = test_case_generator(10);
    printf("Before Sorting\n");
    print_array(test_case, 10);
    quick_sort(test_case, 0, 9);
    printf("After Sorting\n");
    print_array(test_case, 10);
  }
  return EXIT_SUCCESS;
}

void quick_sort(int* arr, int start, int end){
  if (start < end){
    int pivot = arr[end];
    int pivot_index;
    pivot_index = partition_array(arr, start, end, pivot);
    quick_sort(arr, start, pivot_index-1);
    quick_sort(arr, pivot_index+1, end);
    merge(arr, start, pivot_index, end);
  }
}

int partition_array(int* arr, int start, int end, int pivot){
  int i, j;
  i = start;
  j = start;
  while (j <= end){
    while (arr[i] < pivot){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
    }
    j++;
  }

  return i;
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

int test_arr_sorted(int* arr, int size){
  for (int i=0; i<size-1; i++){
    if (arr[i] > arr[i+1]){
      return 0;
    }
  }
  return 1;
}

int* test_case_generator(int size){
  int* arr = malloc(size * sizeof(int));
  for (int i=0; i<size; i++){
    arr[i] = rand() % 10;
  }
  return arr;
}
