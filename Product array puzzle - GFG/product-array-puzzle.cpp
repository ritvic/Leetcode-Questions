// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        int c=0;
        for(auto i:nums)
        if(i==0)
        c++;
        if(c>1)
        return vector<long long int> (n,0);
        else if(c==1)
        {
            long long int j,mul=1;
            for(int i=0;i<n;i++)
                if(nums[i]!=0)
                    mul=mul*nums[i];
                else
                    j=i;
            vector<long long int> v(n,0);
            v[j]=mul;
            return v;
        }
        else
        {
            long long int mul=1;
            for(auto i:nums)
            mul*=i;
            vector<long long int> v(n,0);
            for(int i=0;i<n;i++)
            {
                v[i]=mul/nums[i];
            }
            return v;
        }
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends