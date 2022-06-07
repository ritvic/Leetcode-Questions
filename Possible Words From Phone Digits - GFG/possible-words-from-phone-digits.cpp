// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

 vector<string> mp={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution
{
   public:
   
   void fun(string s,vector<string>&v,string ans)
   {
       if(s.length()==0)
       {
           v.push_back(ans);
           return;
       }
      string str1=mp[s[0]-'0'];
      char ch=s[0];
      string ros=s.substr(1);
      for(int j=0;j<str1.size();j++)
      {
         fun(ros,v,ans+str1[j]);
      }
      return;
      
       
   }
   //Function to find list of all words possible by pressing given numbers.
   vector<string> possibleWords(int a[], int N)
   {
       vector<string>v;
       string str="";
       for(int i=0;i<N;i++)
       str+=to_string(a[i]);
       fun(str,v,"");
       sort(v.begin(),v.end());
       return v;
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