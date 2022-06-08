// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& ar1, vector<int>& ar2)
    {
        int m=ar2.size(),n=ar1.size();
        int i = 0; 
        int j = 0; 
        int count;
        int m1 = -1, m2 = -1;
        for (count = 0; count <= (m + n)/2; count++)
        {
            m2=m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        if((m + n) % 2 == 1){
            return m1;
        }
        else{
            return (m1+m2)/2.0000;
        }
        
        }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends