// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends

int transitionPoint(int arr[], int n) {

      int st=0,en=n-1,mid;
      while(st<=en){
          mid=(st+en)/2;
          if(arr[mid]==0)
             st=mid+1;
          else if(arr[mid]==1)
          {
              if(arr[mid-1]!=0)
                en=mid-1;
              else 
              return mid;
          }
         
      }
       return -1;
}