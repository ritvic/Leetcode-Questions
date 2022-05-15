// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a1[], int a2[], int a3[], int n1, int n2, int n3)
        {
            vector<int> v;
            int i=0,j=0,k=0;
            while (i < n1 && j < n2 && k < n3) {
        if (a1[i] == a2[j] && a2[j] == a3[k]) {
            v.push_back(a1[i]);
            i++;
            j++;
            k++;
        }
        else if (a1[i] < a2[j])
            i++;
        else if (a2[j] < a3[k])
            j++;
        else
            k++;
    }
    vector<int>::iterator ip;
  
    ip = std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(), ip));
            return v;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends