#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Print optimal parenthesization
void printParenthesis(vector<vector<int>>& s, int i, int j){
    if(i == j){
        cout << "A" << i;
        return;
    }

    cout << "(";
    printParenthesis(s, i, s[i][j]);
    printParenthesis(s, s[i][j] + 1, j);
    cout << ")";
}

// Matrix Chain Multiplication
int matrixChain(vector<int>& p){

    int n = p.size() - 1;

    vector<vector<int>> m(n+1, vector<int>(n+1, 0));
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));

    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){

            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k < j; k++){

                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum scalar multiplications: " << m[1][n] << endl;
    cout << "Optimal Parenthesization: ";
    printParenthesis(s, 1, n);
    cout << endl;

    return m[1][n];
}

int main(){

    vector<int> p = {30, 35, 15, 5, 10};

    cout << "Matrix dimensions: 30x35, 35x15, 15x5, 5x10\n";

    matrixChain(p);

    return 0;
}
