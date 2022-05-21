// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> v, int n) 
    { 
        // Your code goes here
        vector<int> res(n,-1);
        stack<pair<int,int>> st;
        st.push({v[0],0});
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && v[i]<st.top().first)
            {
                res[st.top().second]=v[i];
                st.pop();
            }
            st.push({v[i],i});
        }
        return res;
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
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends