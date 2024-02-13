#include <stdio.h>
//Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, small;
    for (i = 0; i < n-1; i++) {
        small = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[small])
                small = j;
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}
//Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;  // Adjust the starting index for left to be one position after the pivot
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Swap the pivot with the element at the right pointer (right position)
    arr[low] = arr[right];
    arr[right] = pivot;

    return right;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot= partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int  swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
//HeapSort
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not the root
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Function to build a max heap
void buildHeap(int arr[], int n) {
    // Build the max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
// Function to perform heap sort on an array
void heapSort(int arr[], int n) {
    // Build the max heap
    buildHeap(arr, n);
    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the current root with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void display(int arr[],int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
        printf("\n");
}
int main() {
    int arr[100],n,choice;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array: \n");
    display(arr,n);
    printf("MENU\n");
    printf("1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort\n6.Heap Sort");
    printf("Enter choice");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            bubbleSort(arr,n);
            printf("Sorted array: \n");
            display(arr,n);
            break;
        case 2:
            insertionSort(arr,n);
            printf("Sorted array: \n");
            display(arr,n);
            break;
        case 3:
            selectionSort(arr,n);
            printf("Sorted array: \n");
            display(arr, n);
            break;
        case 4:
            quickSort(arr,1,n-1);
            printf("Sorted array: \n");
            display(arr,n);
            break;
        case 5:
            mergeSort(arr,0,n-1);
            printf("Sorted array: \n");
            display(arr, n);
            break;
        
        case 6:
            heapSort(arr,n);
            printf("Sorted array: \n");
            display(arr,n);
            break;
        default:
            printf("Invalid choice!!");
            break;
    }

    return 0;
}

