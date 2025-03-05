//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool bs(int lmt,int m,vector<int>& arr,int n){
        
        int st=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]>lmt)return false;
            
            if(cnt+arr[i]>lmt){
                st++;
                cnt=arr[i];
                if(cnt>lmt)return false;
            }
            else cnt+=arr[i];
        }
        if(st<=m)return true;
        return false;
        
    }
    int findPages(vector<int> &arr, int m) 
    {
        int n = arr.size();
        //code here
        if(n<m)return -1;
        int total=0;
        int high=0,low=arr[0];
        for(int i=0;i<n;i++){
            total+=arr[i];
            low=min(low,arr[i]);
        }
        high=total;
        
        
        
        
        
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            
            if(bs(mid,m,arr,n)){
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return low;
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends