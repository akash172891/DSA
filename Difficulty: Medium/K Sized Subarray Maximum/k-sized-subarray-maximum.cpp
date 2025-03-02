//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
            
       vector<int> v(n);
	    deque<int> dq;
	    for(int i=0;i<n;i++){
	        v[i]=arr[i];
	    }
	    for(int i=0;i<k;i++){
	        while(!dq.empty() && v[i]>= v[dq.back()]){
	            dq.pop_back();
	        }
	        dq.push_back(i);
	    }
	    int mx = dq.front();
	    vector<int>ans;
	    int start = 0;
	    for(int i=k;i<n;i++){
	        if(!dq.empty())
	            ans.push_back(v[dq.front()]);
	        if(!dq.empty() && (i-dq.front()>=k)){
	            dq.pop_front();
	        }
	        while(!dq.empty() && v[i]>= v[dq.back()]){
	            dq.pop_back();
	        }
	        dq.push_back(i);
	    }
	    if(!dq.empty())
	        ans.push_back(v[dq.front()]);
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends