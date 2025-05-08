//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        // Max-heap to store the smaller half of the numbers
        priority_queue<int> maxHeap;
        // Min-heap to store the larger half of the numbers
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        
        // Vector to store the medians
        vector<double> ans;
        // Counter to track the number of elements processed
        int cntEle = 1;
        
        // Insert the first element into the max-heap
        maxHeap.push(arr[0]);
        // The median of the first element is the element itself
        ans.push_back((double)(arr[0]));
        
        // Process the remaining elements
        for(int i = 1; i < n; ++i) {
            int top = maxHeap.top();
            if(top < arr[i]) {
                // If the current element is greater than the top of the max-heap,
                // it belongs to the larger half (min-heap)
                minHeap.push(arr[i]);
                // Balance the heaps if necessary
                if(minHeap.size() > maxHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            } else {
                // Otherwise, it belongs to the smaller half (max-heap)
                maxHeap.push(arr[i]);
                // Balance the heaps if necessary
                if(maxHeap.size() > minHeap.size() + 1) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            // Increment the element count
            ++cntEle;
            // Calculate the median
            if(cntEle & 1) {
                // If the count is odd, the median is the top of the max-heap
                ans.push_back((double)(maxHeap.top()));
            } else {
                // If the count is even, the median is the average of the tops of both heaps
                double temp = (minHeap.top() + maxHeap.top()) / 2.0;
                ans.push_back(temp);
            }
        }
        
        // Return the vector of medians
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends