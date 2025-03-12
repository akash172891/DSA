//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:

    vector<string> ans;
    
    void fxn(int n, string s) {
        
        if(n<=0) {
            ans.push_back(s);
            return;
        }
    
        
        //take
        
        if(s.size()==0) {
            fxn(n-1, s+"0");
            fxn(n-1, s+"1");
        }
        else {
            int x = s.length();
            fxn(n-1, s+"0");
            if(s[x-1]!='1') {
                fxn(n-1, s+"1");
            }
            
        }
        
        //notake
        
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        
        fxn(num, "");
        
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends