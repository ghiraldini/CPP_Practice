#include <iostream>

/* MERGE SORT */
void merge_sort(int [], int, int);
void merge(int [], int, int ,int);
void printArr(int [],int);

/* QUICK SORT */
void quick_sort(int [], int, int);
int partition(int [], int, int);
void swap(int *, int *);


int main(int argc, char* argv[])
{
    int myArr[6] = {9,4,1,7,11,5};
    int arrSize = sizeof(myArr)/sizeof(myArr[0]);
    std::cout << "Unordered array" << std::endl;
    printArr(myArr,arrSize);

    /*
    merge_sort(myArr, 0, arrSize);

    arrSize = sizeof(myArr)/sizeof(myArr[0]);
    std::cout << "Ordered array" << std::endl;
    printArr(myArr,arrSize);
    */

    arrSize = sizeof(myArr)/sizeof(myArr[0]);
    quick_sort(myArr,0,arrSize-1);
    std::cout << "Ordered array" << std::endl;
    printArr(myArr,arrSize);

    return 0;
}

// Recursively split and merge each side
void merge_sort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    return;
}

// Merge each side by smalled of each side into arr
void merge(int arr[], int l, int m, int r){
    int i=0, // idx of L
        j=0, // idx of R
        k=l; // idx of Merged

    int s1 = m-l+1;
    int s2 = r-m;

    // Create temp arrays of left and right
    int L[s1];
    int R[s2];

    // Copy original array into each half
    for(int i=0; i<s1; i++){
        L[i] = arr[l+i];
    }
    for(int i=0; i<s2; i++){
        R[i] = arr[i+m+1];
    }

    // Compare and insert into merged array
    while( i<s1 && j<s2){
        if( L[i] <= R[j] ){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Empty rest of Left side
    while(i<s1){
        arr[k] = L[i];
        i++; k++;
    }
    // Empty rest of Right side
    while(j<s2){
        arr[k] = R[j];
        j++; k++;
    }

    return;
}


void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
    return;
}


// Choose last idx to partition
int partition(int arr[], int low, int high){
    int p = arr[high];
    int i = low-1;

    for(int j=low; j<high-1; j++){
        if(arr[j] <= p){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap pivot and last element
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

// Swap elements
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


// Utility method to print array
void printArr(int arr[], int s){
    std::cout << "Array: ";
    for(int i=0; i<s; i++){
        std::cout << arr[i];
        if(i<s-1){ std::cout << ", "; }
    }
    std::cout << " " << std::endl;
}
