// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) 
{
    queue<int>a,b;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        a.push(arr[i]);
        else
        b.push(arr[i]);
    }
    int k=0;
    while(!a.empty()&&!b.empty())
    {
        arr[k++]=a.front();
        a.pop();
        arr[k++]=b.front();
        b.pop();
    }
    while(!a.empty())
    {
         arr[k++]=a.front();
         a.pop();
    }
   
     while(!b.empty())
    {
         arr[k++]=b.front();
         b.pop();
    }
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends