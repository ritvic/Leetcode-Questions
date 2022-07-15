class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<int> a(n,0),b(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i]=max(a[i],grid[i][j]);
                b[j]=max(b[j],grid[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=max(grid[i][j],min(a[i],b[j]))-grid[i][j];
            }
        }
        return sum;
        
    }
};