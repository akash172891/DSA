//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int ans=0;
  void merge(vector<int>& arr, int s1, int e1, int s2, int e2) {
        
        if(s1>s2) {
            merge(arr, s2, e2, s1, e1);
        }
        
        vector<int> a, b;
        
        for(int i = s1;i<=e1;i++) a.push_back(arr[i]);
        for(int i=s2;i<=e2;i++) b.push_back(arr[i]);
        
        int i = 0, j = 0, k = s1;
        int m = a.size();
        int n = b.size();
        
        while(i<m && j < n) {
            if(a[i]<=b[j]) arr[k++] = a[i++];
            else{
                ans+=(m-i);
                 arr[k++]=b[j++];
            }
        }
        
        if(i==m) {
            while(j<n)arr[k++]=b[j++];
        }
        if(j==n)while(i<m)arr[k++]=a[i++];
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l==r) return;
        int mid = l + (r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, mid+1, r);
        
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends