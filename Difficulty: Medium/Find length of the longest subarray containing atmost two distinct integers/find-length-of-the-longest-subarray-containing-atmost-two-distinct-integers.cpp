//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int i=-1,j=-1;
        unordered_map<int,int>st;
        int ans=0;
        int n =arr.size();
        while(i<n){
            if(st.size()<=2){
                i++;
               if(i<n) st[arr[i]]++;
               if(i<n && st.size()<=2) ans = max(ans, i-j);
            }
            else{
                while(st.size()>2) {
                    j++;
                    st[arr[j]]--;
                    if(st[arr[j]]==0) st.erase(arr[j]);
                    
                }
            }
        }
        return ans;
    }
};
 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends