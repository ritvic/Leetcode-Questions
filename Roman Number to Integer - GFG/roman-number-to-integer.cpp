// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<char,int> roman;
        roman['I'] = 1;
      roman['V'] = 5;
      roman['X'] = 10;
      roman['L'] = 50;
      roman['C'] = 100;
      roman['D'] = 500;
      roman['M'] = 1000;
      
      int num = 0;
      for(int i = 0; i<str.length(); i++) {
          if(roman[str[i]] < roman[str[i+1]]) {
              num = num + roman[str[i+1]] - roman[str[i]];
              i++;
            } else {
              num = num + roman[str[i]];
           }
      }
      return num;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends