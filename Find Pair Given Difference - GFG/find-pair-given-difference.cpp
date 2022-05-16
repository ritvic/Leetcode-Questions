// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int n, int k){
    //code
    int i = 0;
    int j = 1;
 
    sort(arr,arr+n);
    while (i < n && j < n)
    {
        if (i != j && (arr[j] - arr[i] == k || arr[i] - arr[j] == k) )
        {
            return true;
        }
        else if (arr[j]-arr[i] < k)
            j++;
        else
            i++;
    }
 
    return false;


}