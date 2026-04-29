#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int>& arr, vector<int>& subset,
               int index, int target, int current){

    // If target achieved
    if(current == target){
        cout << "{ ";
        for(int x : subset)
            cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // Try remaining elements
    for(int i = index; i < arr.size(); i++){

        // include element only if sum does not exceed target
        if(current + arr[i] <= target){

            subset.push_back(arr[i]);

            subsetSum(arr, subset, i + 1, target, current + arr[i]);

            subset.pop_back(); // backtrack
        }
    }
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 6;

    cout << "Set    : { 1 2 3 4 5 }\n";
    cout << "Target : " << target << "\n";
    cout << "Subsets with sum = " << target << ":\n";

    vector<int> subset;

    subsetSum(arr, subset, 0, target, 0);

    return 0;
}
