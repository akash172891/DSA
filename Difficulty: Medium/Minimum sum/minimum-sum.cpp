//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    string add(vector<int> &f, vector<int> &s) {
        string ans = "";
        int i = f.size() - 1;
        int j = s.size() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += f[i--];
            if (j >= 0) sum += s[j--];
            
            ans.push_back('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string minSum(vector<int> &arr) {
         sort(arr.begin(),arr.end());
        int n = arr.size();
        int i=0;
        int j=1;
        int num1;
        int num2;
        string s1="";
        string s2="";
        while(i<n && j<n){
            s1+=arr[i]+'0';
            s2+=arr[j]+'0';
            i+=2;
            j+=2;
        }
        if(i<n){
            s1+=arr[i]+'0';
        }
        int k = s1.size();
        int l = s2.size();
        i = k-1;
        j = l-1;
        int num;
        int carry = 0;
        string ans = "";
        while(i>=0 && j>=0){
            num = s1[i] - '0'+s2[j]-'0'+carry;
            carry = num/10;
            ans+='0'+num%10;
            i--;
            j--;
        }
        if(i>=0){
            num = s1[i]-'0'+carry;
            carry = num/10;
            ans+='0'+num%10;
            i--;
        }
        if(carry){
            ans+='0'+carry;
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(ans[i]=='0'){
            i++;
        }
        return ans.substr(i,ans.size());
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends