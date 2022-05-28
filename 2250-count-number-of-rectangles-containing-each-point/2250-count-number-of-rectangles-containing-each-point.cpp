class Solution {
    int t[105];
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n=rectangles.size(),q=points.size(),i,j,k;
        vector<int> ans(q);
        sort(rectangles.begin(),rectangles.end());
        vector<pair<int,int>> a(q);
        for(i=0;i<q;i++)a[i]=make_pair(points[i][0],i);
        sort(a.begin(),a.end());
        for(i=q-1,j=n-1;~i;i--)
        {
            for(;~j&&rectangles[j][0]>=a[i].first;j--)for(k=rectangles[j][1];k<101;k+=k&-k)t[k]++;
            for(k=points[a[i].second][1]-1;k;k^=k&-k)ans[a[i].second]+=t[k];
            ans[a[i].second]=n-1-j-ans[a[i].second];
        }
        return ans;
    }
};