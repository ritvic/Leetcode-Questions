// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


#include<stack>
stack<char>rev;
char* reverse(char *S, int len)
{
   //code here
   for(int i=0;i<len;i++ ){
       rev.push(S[i]);
   }
  int i=0;
   while(!rev.empty()){
    S[i]=rev.top();
    i++;
    rev.pop();
   }
  return S;
   
   
}