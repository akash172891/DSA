//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        // code here
        int n = arr.size();
      vector < int > v_min(n), v_max(n);
      v_min[0] = arr[0];
      v_max[n - 1] = arr[n - 1];
      for (int i = 1; i < n; i++) {
        v_min[i] = min(v_min[i - 1], arr[i]);
        v_max[n - i - 1] = max(v_max[n - i], arr[n - i - 1]);
      }
      int ans = 0, i = 0, j = 0;
      while (i < n && j < n) {
        if (v_min[i] <= v_max[j]) {
          ans = max(ans, j - i);
          j++;
        } else i++;
      }
      return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends