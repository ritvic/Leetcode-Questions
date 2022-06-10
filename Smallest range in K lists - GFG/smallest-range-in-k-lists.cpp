// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range

class Solution {
    public:
    
    pair<int, int> findSmallestRange(int arr[][N], int n, int k) {
        
        int a=0,b=INT_MAX;
         int sokth[k]={0};
         
         multiset<pair<int,int> > mst;
         for(int i=0;i<k;i++)
         mst.insert({arr[i][0], i});
         
         for(int i=0;i<n*k;i++){
             pair<int,int> front=*mst.begin(), back=*mst.rbegin();
             if(abs(back.first-front.first)<abs(b-a)){
                 a=front.first; b=back.first;
             }
             mst.erase(mst.begin());
             sokth[front.second]++;
             if(sokth[front.second]==n) break;
             mst.insert({arr[front.second][sokth[front.second]], front.second});
         }
         return {a,b};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends