//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int cnt =0;
        int ele = 0;
        
        for(int i=0;i<n;i++) {
            if(cnt==0) {
                ele = arr[i];
                cnt++;
            }
            else if(arr[i]==ele) cnt++;
            else cnt--;
        }
        
        cnt =0;
        
        for(int i=0;i<n;i++) if(ele==arr[i])cnt++;
        
        if(cnt>n/2) return ele;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends