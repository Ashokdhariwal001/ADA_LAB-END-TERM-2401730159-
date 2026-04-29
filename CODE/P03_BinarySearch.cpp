#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
using namespace std;
using namespace chrono;

// Binary Search
int binarySearch(vector<int>& arr, int target){
    int low = 0, high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Repeated execution for measurable time
long long measure(vector<int> arr, int target){
    auto start = high_resolution_clock::now();

    volatile int res;
    for(int i = 0; i < 100000; i++)  // ?? repeat to get measurable time
        res = binarySearch(arr, target);

    auto end = high_resolution_clock::now();

    return duration_cast<microseconds>(end - start).count();
}

int main(){
    vector<int> sizes = {1000, 5000, 10000, 20000};

    cout << "Size\tBest(us)\tAvg(us)\tWorst(us)\n";
    cout << "--------------------------------------\n";

    for(int n : sizes){
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);

        long long best = measure(arr, arr[n/2]);  // best case
        long long avg = measure(arr, arr[n/3]);   // average case
        long long worst = measure(arr, -1);       // worst case

        cout << n << "\t"
             << best << "\t\t"
             << avg << "\t\t"
             << worst << endl;
    }

    return 0;
}
