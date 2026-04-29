#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int> a){
    int n = a.size();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

// Selection Sort
void selectionSort(vector<int> a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++)
            if(a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

// Insertion Sort
void insertionSort(vector<int> a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int key = a[i], j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// Time function (FIXED)
template <typename Func>
long long measureTime(Func func, vector<int> a){
    auto start = high_resolution_clock::now();
    func(a);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();
}

int main(){
    vector<int> sizes = {100, 200, 300, 400};

    cout << "Size\tBubble(us)\tSelection(us)\tInsertion(us)\n";
    cout << "----------------------------------------------------\n";

    for(int n : sizes){
        vector<int> arr(n);

        // Worst case (reverse sorted)
        for(int i=0;i<n;i++)
            arr[i] = n - i;

        cout << n << "\t"
             << measureTime(bubbleSort, arr) << "\t\t"
             << measureTime(selectionSort, arr) << "\t\t"
             << measureTime(insertionSort, arr)
             << endl;
    }

    return 0;
}
