class Solution {
public:
    int jump(vector<int>& arr) {

        int n=arr.size();
        int farthest=0,jumps=0,current=0;
        for(int i=0;i<n-1;i++)
        {
          farthest=max(farthest,i+arr[i]);
          if(i==current)
          {
              jumps++;
              current=farthest;
          }
               
        }
        if(current<n-1)
        return -1;
        return jumps;

        
    }
};