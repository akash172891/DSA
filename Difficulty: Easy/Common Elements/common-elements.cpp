//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b) {
        // Your code here
        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans;
     
        int i,j;
        i=j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<n1 && j<n2)
        {
            if(a[i] == b[j])
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }else if(a[i] < b[j])
            {
                i++;
            }else {
                j++;
            }
        }
      
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        vector<int> b;
        int num1;
        while (ss1 >> num1) {
            b.push_back(num1);
        }
        Solution ob;
        vector<int> result;
        result = ob.commonElements(a, b);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends