// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}// } Driver Code Ends



long long int countStr(long long int n){
    //complete the function here
         // 1length -> 1-b, 1-c --> 2
   // 2length -> 1-b:1-c, 2-c --> 2+1
   // 3length -> 1-b:2-c; --> 3
   
   int onelength = 2;
   int twolength = 3;
   int threelength = 3;
   
   if(n == 1){
       return onelength+1;
   }
   
   long long int count = 1;
   if(n == 2){
       return count+4+2+1;
   }
   
   // For 1 case
   count += n*2;
   
   // For 2 case;
   count += n*(n-1) + (n*(n-1))/2;
   
   // For 3 case;
   count += (n*(n-1)*(n-2))/2;
   
   return count;

}