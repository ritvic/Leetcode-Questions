// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes herez
        vector <int>v;
       int size1=nums1.size();
        int size2=nums2.size();
          int i,j;
       double Median=0.0;
       for(i=0,j=0;i<size1&&j<size2;){
           if(nums1[i]<=nums2[j]){
               v.push_back(nums1[i]);
               i++;
           }
           else{
               v.push_back(nums2[j]);
               j++;
           }
       }
           if(i==size1){
               while(j<size2){
                   v.push_back(nums2[j]);
               j++;
               }
           }
               
           if(j==size2){
               while(i<size1){
                   v.push_back(nums1[i]);
                    i++;
               }
           }
       int n=v.size();
       
       
       
       
       
       if(n%2==0){
           int r1=v[n/2];
           int r2=v[(n-2)/2];
           Median=(r1+r2)/2.000000;
       }
       
       else{
           Median=v[(n-1)/2];
       }
       
       return Median;
    
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