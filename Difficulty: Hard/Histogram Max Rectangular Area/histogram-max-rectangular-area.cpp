//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
    int n = arr.size();
    
    // Create a stack to hold indices and two vectors to store the indices of 
    // the previous smaller and next smaller elements for each bar
    stack<int> st;
    vector<int> left(n, -1), right(n, n);
    
    // Step 1: Find the previous smaller element for each element
    for(int i = n - 1; i >= 0; i--) {
        // While stack is not empty and the current element is smaller than
        // the element at the top of the stack, update the 'left' array
        while(!st.empty() && arr[st.top()] > arr[i]) {
            left[st.top()] = i;  // The previous smaller element for arr[st.top()] is arr[i]
            st.pop();  // Pop the top element from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }
    
    // Clear the stack to reuse it for finding the next smaller element
    st = stack<int>();
    
    // Step 2: Find the next smaller element for each element
    for(int i = 0; i < n; i++) {
        // While stack is not empty and the current element is smaller than
        // the element at the top of the stack, update the 'right' array
        while(!st.empty() && arr[st.top()] > arr[i]) {
            right[st.top()] = i;  // The next smaller element for arr[st.top()] is arr[i]
            st.pop();  // Pop the top element from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }
    
    // Variable to keep track of the maximum area
    int maxx = 0;
    
    // Step 3: Calculate the area for each element using the 'left' and 'right' arrays
    for(int i = 0; i < n; i++) {
        // The width of the rectangle is the difference between the next smaller
        // and previous smaller elements. The height is the value of the current element.
        int area = (((right[i] - 1) - (left[i] + 1)) + 1) * arr[i];
        
        // Update the maximum area found so far
        maxx = std::max(maxx, area);
    }
    
    // Return the maximum area
    return maxx;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends