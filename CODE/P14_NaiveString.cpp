	#include <iostream>
	#include <string>
	using namespace std;
	
	void naiveSearch(string text, string pattern){
	
	    int n = text.size();
	    int m = pattern.size();
	    int count = 0;
	
	    cout << "Text    : " << text << endl;
	    cout << "Pattern : " << pattern << endl;
	
	    cout << "\nPattern found at positions: ";
	
	    for(int i = 0; i <= n - m; i++){
	
	        int j = 0;
	
	        // check character by character
	        for(j = 0; j < m; j++){
	            if(text[i + j] != pattern[j])
	                break;
	        }
	
	        if(j == m){
	            cout << i << " ";
	            count++;
	        }
	    }
	
	    if(count == 0)
	        cout << "None";
	
	    cout << "\nTotal occurrences: " << count << endl;
	}
	
	int main(){
	
	    string text = "AABAACAADAABAABA";
	    string pattern = "AABA";
	
	    naiveSearch(text, pattern);
	
	    return 0;
	}
