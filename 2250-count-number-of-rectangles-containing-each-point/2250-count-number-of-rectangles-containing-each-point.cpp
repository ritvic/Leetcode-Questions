class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        
        vector<vector<int>> v(101);
        for(auto i:r)
        {
            v[i[1]].push_back(i[0]);
        }
        // for(auto jj:v)
        // sort(jj.begin(),jj.end());
        for (int i = 1; i <= 100; ++i)
            sort(v[i].begin(), v[i].end());
        vector<int> co;
        for(auto t:p)
        {
            int kk=0;
            for(int j=t[1];j<=100;j++)
            {
                // for(int i=0;i<v[j].size();i++)
                //     if(v[j][i]>=t[0])
                    kk+=v[j].end()-lower_bound(v[j].begin(), v[j].end(), t[0]);
                        // break;
                
            }
            co.push_back(kk);
        }
        return co;
    }
    
//     vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
//         vector<vector<int>> v(111);
//         for (auto& e : rectangles)
//         {
//             int x = e[0], y = e[1];
//             v[y].push_back(x);
//         }
//         for (int i = 1; i <= 100; ++i)
//             sort(v[i].begin(), v[i].end());
        
//         vector<int> res;
//         for (auto& e : points)
//         {
//             int tmp = 0;
//             int x = e[0], y = e[1];
//             for (int i = y; i <= 100; ++i)
//             {
//                 tmp += v[i].end() - lower_bound(v[i].begin(), v[i].end(), x);
//             }
//             res.push_back(tmp);
//         }
//         return res;
//     }
};