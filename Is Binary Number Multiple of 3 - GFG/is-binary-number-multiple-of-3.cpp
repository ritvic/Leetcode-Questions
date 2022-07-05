// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string A){
	    //complete the function here
	    int oddbits = 0, evenbits = 0;
    for (int counter = 0; counter < A.length(); counter++) {
        // checking if the bit is nonzero
        if (A[counter] == '1') {
            // checking if the nonzero bit is at even
            // position
            if (counter % 2 == 0) {
                evenbits++;
            }
            else {
                oddbits++;
            }
        }
    }
    // Checking if the difference of non-zero oddbits and
    // evenbits is divisible by 3.
    if (abs(oddbits - evenbits) % 3 == 0) return 1;
    else return 0;
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends