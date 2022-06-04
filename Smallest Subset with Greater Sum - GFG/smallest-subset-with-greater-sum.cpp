// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &A,int N){
        
        long long s = accumulate(A.begin(), A.end(), 0ll), sum = 0;
        sort(A.begin(), A.end(), greater<int>());
        for(int i=0; i<N; i++){
            sum += A[i];
            s -= A[i];
            if(sum > s)
                return i+1;
        }
        return N;
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends