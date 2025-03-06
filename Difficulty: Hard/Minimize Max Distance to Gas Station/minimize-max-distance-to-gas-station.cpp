//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool bs(vector<int>&stations,int k, long double mid, int n)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            long double gap=stations[i+1]-stations[i];
            cnt+=floor(gap/mid);
        }
        return (cnt<=k);
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        long double mx=0.0;
        
        for(int i=0;i<n-1;i++)
        {
            mx=max(mx,(long double)stations[i+1]-stations[i]);
        }
        long double l=0.0,h=mx,mid,ans=mx;
        
        while(h-l>1e-7)
        {
            mid=l+(h-l)/2.0;
            
            if(bs(stations,k,mid,n))
            {
                ans=mid;
                h=mid;
            }
            else
            {
                l=mid;
            }
           
        }
         return round(ans*100)/100;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends