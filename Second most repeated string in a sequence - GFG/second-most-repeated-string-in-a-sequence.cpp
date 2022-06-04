// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
         unordered_map<string, int> um;
        string ans;
        for(int i=0; i<n; i++){
            um[arr[i]]++;
        }
        //to find second largest 
        vector<int> v;
        for(auto it: um){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int sec_repeating = v[v.size()-2];
        
        //returning its key
        for(auto it :um){
            if(it.second == sec_repeating) ans = it.first;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends