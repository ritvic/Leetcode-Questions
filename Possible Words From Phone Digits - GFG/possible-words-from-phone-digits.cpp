// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

unordered_map<int,string>mp;
class Solution
{
   public:
   
   void fun(string &str,vector<string>&ans,int i,int a[],int N)
   {
       if(i>=N)
       {
           ans.push_back(str);
           return;
       }
      string str1=mp[a[i]];
      for(int j=0;j<str1.size();j++)
      {
          str.push_back(str1[j]);
          fun(str,ans,i+1,a,N);
          str.pop_back();
      }
      
       
   }
   //Function to find list of all words possible by pressing given numbers.
   vector<string> possibleWords(int a[], int N)
   {
       vector<string>ans;
       string str;
       mp[2]="abc";
       mp[3]="def";
       mp[4]="ghi";
       mp[5]="jkl";
       mp[6]="mno";
       mp[7]="pqrs";
       mp[8]="tuv";
       mp[9]="wxyz";
       fun(str,ans,0,a,N);
       sort(ans.begin(),ans.end());
       return ans;
   }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends