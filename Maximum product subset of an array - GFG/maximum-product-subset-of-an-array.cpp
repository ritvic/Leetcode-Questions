// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
const int mod=1e9+7;
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        long long int s=1;
        sort(a.begin(),a.end());
        
        int c=0;
        for(auto i:a)
        if(i<0)
        c++;
        if(c==1 && a[n-1]==0)
        return 0;
        if(n==1)
        return a[0];
        if(c%2==0)
        {
            for(auto i:a)
            if(i!=0)
            s=((s%mod)*i)%mod;
            return s%mod;
        }
        else
        {
            for(auto i:a)
            {
                c--;
                if(i!=0 && c!=0)
                s=((s%mod)*i)%mod;
                
            }
            return s%mod;
            
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
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends