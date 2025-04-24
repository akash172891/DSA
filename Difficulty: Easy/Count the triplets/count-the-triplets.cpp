//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplet(vector<int>& arr) {
        // code here
        int n =arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        int cnt =0;
        for(int k = 0;k<n;k++) {
            int num = arr[k];
            
            int i = k+1, j = n-1;
            
            while(i<j) {
                if(arr[i]+arr[j]==num) {
                    cnt++;
                    j--;
                    i++;
                }
                else if(arr[i]+arr[j]<num) {
                    j--;
                }
                else i++;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.countTriplet(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends