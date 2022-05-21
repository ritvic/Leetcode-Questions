// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   int getMaxArea(int v[], int n)
    {
        vector<int> r1(n,n),r2(n,-1);
       stack<pair<int,int>> st,st1;
       st.push({v[0],0});
       for(int i=0;i<n;i++)
       {
           while(!st.empty() && st.top().first>v[i])
           {
               r1[st.top().second]=i;
               st.pop();
           }
           st.push({v[i],i});
       }
       st1.push({v[n-1],n-1});
        for(int i=n-2;i>=0;i--)
       {
           while(!st1.empty() && st1.top().first>v[i])
           {
               r2[st1.top().second]=i;
               st1.pop();
           }
           st1.push({v[i],i});
       }
       int maxx=-1;
       for(int i=0;i<n;i++)
           maxx=max(maxx,(r1[i]-r2[i]-1)*v[i]);
           
    return maxx;
    }
    int maxArea(int v[MAX][MAX], int n, int m) {
         int mm=0,a=0;
         for(int i=1;i<n;i++)
             for(int j=0;j<m;j++)
                 if(v[i][j]==1)
                 v[i][j]+=v[i-1][j];
                
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     cout<<v[i][j]<<" ";
        //     cout<<endl;
        // }
         for(int i=0;i<n;i++)
         {
             a=getMaxArea(v[i],m);
            //  cout<<a<<" ";
             mm=max(mm,a);
         }
         return mm;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends