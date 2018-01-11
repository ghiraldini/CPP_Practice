#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;    
    return;
}


void bSort(std::vector<int> a, int n) {
    int swapCnt = 0;
    for (int i = 0; i < n; i++) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
                swapCnt++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
    }
    std::cout << "Array is sorted in " << swapCnt << " swaps." << std::endl;
    std::cout << "First Element: " << a[0] << std::endl;
    std::cout << "Last Element: " << a[n-1] << std::endl;

    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    bSort(a, n);
    return 0;
}