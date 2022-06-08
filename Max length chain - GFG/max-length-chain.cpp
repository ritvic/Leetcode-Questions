// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    v.push_back(make_pair(p[i].first,p[i].second));
    sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
    int c=1,end=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>end)
        {
            c++;end=v[i].second;
        }
    }
    return c;
    
    return 0;
}