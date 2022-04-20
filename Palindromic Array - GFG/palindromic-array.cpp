// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
int isPalindrome(int N)
    {
        string str = to_string(N);
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i])
                return 0;
        }
        return 1;
    }
    int PalinArray(int arr[], int n)
    {
    	// code here
    	for (int i = 0; i < n; i++) {
            int ans = isPalindrome(arr[i]);
            if (ans == 0)
                return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends