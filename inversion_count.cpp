#include <bits/stdc++.h>

using namespace std;

void merge(std::vector<int> arr, int l, int m, int r, long &invs);

// Recursively split and merge each side
void merge_sort(std::vector<int> arr, int l, int r, long &invs){
    if (l < r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m, invs);        
        merge_sort(arr, m+1, r, invs);        
        merge(arr, l, m, r, invs);
    }
    return;
}

// Merge each side by smalled of each side into arr
void merge(std::vector<int> arr, int l, int m, int r, long &invs){
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
            invs++;
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


long countInversions(std::vector<int> arr) {
    // Complete this function
    long invs = 0;
    merge_sort(arr,0,arr.size()-1,invs);
    return invs;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        } 
        long result = countInversions(arr);        
        cout << result << endl;
    }
    return 0; 
}


/* Sample Input
3
5
1 1 1 2 2
5
2 1 3 1 2
5
9492052 241944 5743396 5758608 6053545
*/
// Output: 0 4 4