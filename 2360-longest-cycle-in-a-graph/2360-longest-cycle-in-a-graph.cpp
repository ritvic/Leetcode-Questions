class Solution {
public:
    int cyc=-1;
    void dfs(int i,vector<int> &edges,vector<bool> &visited){
        int length=1;
        unordered_map<int,int> df;
        while(i!=-1){
            if(df.find(i)!=df.end()){
                cyc=max(cyc,length-df[i]);
                return;
            }
            if(visited[i]==true)return;
            visited[i]=1;
            df[i]=length;
            i=edges[i];
            length++;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++)
            if(visited[i]==0)
                dfs(i,edges,visited);
        return cyc;
        
    }
};