// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image ,vector<vector<bool>>&visited,int i, int j , int oc,int nc){
    if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=oc||visited[i][j])
            return;
        visited[i][j]=true;
        image[i][j]=nc;
        dfs(image,visited,i+1,j,oc,nc);
        dfs(image,visited,i-1,j,oc,nc);
        dfs(image,visited,i,j+1,oc,nc);
        dfs(image,visited,i,j-1,oc,nc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        dfs(image,visited,sr,sc,image[sr][sc],newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends