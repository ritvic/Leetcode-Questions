// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &v,int n,int k){
        int sum;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=v[j];
                if(q.size()<k) q.push(sum);
                else if(q.top()>sum) continue;
                else
                {
                    q.pop();q.push(sum);
                }
                // cout<<q.top()<<" ";
            }
        }
        return q.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends