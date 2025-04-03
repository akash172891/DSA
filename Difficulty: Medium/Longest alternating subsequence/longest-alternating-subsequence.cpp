//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
         int flag=-1;
        int cnt=1;
        for(int i=1;i<arr.size();i++){
            if((flag==-1||flag==0)&&arr[i-1]<arr[i]){
                flag=1;
                cnt++;
            }
            else if((flag==-1||flag==1)&&arr[i-1]>arr[i]){
                flag=0;
                cnt++;
            }
        
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends