// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int v[], int n, int x, int y) {
        // code here
        int a=-1,b=-1,minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(v[i]==x)a=i;
            if(v[i]==y)b=i;
            if(a!=-1 && b!=-1)minn=min(minn,abs(a-b));
        }
        
        if(a==-1 ||b==-1)return -1;
        return minn;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends