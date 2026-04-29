#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

// Knapsack function
double fractionalKnapsack(int W, vector<Item>& items){

    // Sort by value/weight ratio (descending)
    sort(items.begin(), items.end(),
        [](Item a, Item b){
            return a.ratio > b.ratio;
        });

    double profit = 0.0;

    cout << "Item selection (fraction taken): ";

    for(auto &it : items){

        if(W == 0){
            cout << "0 ";
            continue;
        }

        if(it.weight <= W){
            cout << "1 ";
            profit += it.value;
            W -= it.weight;
        }
        else{
            double frac = (double)W / it.weight;
            cout << frac << " ";
            profit += frac * it.value;
            W = 0;
        }
    }

    cout << endl;
    return profit;
}

int main(){

    int W = 50;

    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    // calculate ratio
    for(auto &it : items)
        it.ratio = (double)it.value / it.weight;

    cout << "Knapsack Capacity: " << W << endl;
    cout << "Items (w,v): (10,60), (20,100), (30,120)\n";

    double profit = fractionalKnapsack(W, items);

    cout << "Maximum Profit = " << fixed << setprecision(2) << profit << endl;

    return 0;
}
