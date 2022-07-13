// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> ans;
    int fac(int num,int count)
    {
        int carry=0;
        for(int i=0;i<count;i++)
        {
            int val=ans[i]*num+carry;
            ans[i]=val%10;
            carry=val/10;
        }
        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
            count++;
        }
        return count;
    }
    vector<int> factorial(int N)
    {
        ans.push_back(1);
        int count=1;
        for(int i=2;i<=N;i++)
            count=fac(i,count);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends