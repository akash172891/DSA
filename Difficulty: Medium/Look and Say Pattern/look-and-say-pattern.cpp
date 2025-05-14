//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
         string str = "1";
        for(int i=1;i<n;i++)
        {
            int count =1;
            string temp = "";
            for(int j=1;j<str.length();j++)
            {
                if(str[j] == str[j-1])
                {
                    count++;
                }
                else{
                    temp += to_string(count)+str[j-1];
                    count =1;
                }
            }
            
            temp+=to_string(count)+str.back();
            str = temp;
        }
        
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends