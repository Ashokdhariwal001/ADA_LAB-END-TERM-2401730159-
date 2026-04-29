#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
using namespace std;
using namespace chrono;

// -- Merge Sort ---------------------
void merge(vector<int>& a, int l, int m, int r){
    vector<int> L(a.begin()+l, a.begin()+m+1);
    vector<int> R(a.begin()+m+1, a.begin()+r+1);

    int i=0, j=0, k=l;

    while(i<L.size() && j<R.size())
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while(i<L.size()) a[k++] = L[i++];
    while(j<R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

// -- Quick Sort ---------------------
int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(a[j] < pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i+1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

// -- Time Measurement ---------------------
long long measureMerge(vector<int> a){
    auto start = high_resolution_clock::now();
    mergeSort(a, 0, a.size()-1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();
}

long long measureQuick(vector<int> a){
    auto start = high_resolution_clock::now();
    quickSort(a, 0, a.size()-1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();
}

// -- MAIN ---------------------
int main(){
    vector<int> sizes = {1000, 2000, 3000, 4000};

    cout << "Size\tMerge(us)\tQuick(us)\n";
    cout << "--------------------------------\n";

    for(int n : sizes){
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        reverse(arr.begin(), arr.end()); // worst case input

        cout << n << "\t"
             << measureMerge(arr) << "\t\t"
             << measureQuick(arr) << endl;
    }

    return 0;
}
