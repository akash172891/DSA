//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        // code here
         int m = nums1.size(), n= nums2.size();
        if(m > n)
        {
            return kthElement(nums2, nums1,k);
        }

        int total = (m+n);

        int l=max(k-n,0), r=min(m,k);

        while(l<=r) {
            int mid1 = l + (r-l)/2;
            
            int mid2 = k-mid1;

            int low1 = INT_MIN, low2 = INT_MIN;
            int high1 = INT_MAX, high2 = INT_MAX;
            if(mid1 > 0) low1 = nums1[mid1-1];
            if(mid2 > 0) low2 = nums2[mid2-1];
            if(mid1>=0 && mid1 < m) high1=nums1[mid1];
            if(mid2>=0 && mid2<n) high2 = nums2[mid2];
            
            if(low1<=high2 && low2<=high1) {
                    return max(low1,low2);
            }
            else if(low1>high2) r = mid1-1;
            else l = mid1+1;





        }
        return -1;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends