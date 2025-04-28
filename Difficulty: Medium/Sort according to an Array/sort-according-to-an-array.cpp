//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends

// User function template in C++

class Solution {
  public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> arr1, int n, vector<int> arr2, int m) {
        // Your code here
        map<int,int>mp;
        vector<int>ans;
        
        for(int i=0;i<n;i++){ //1 =2   2=2  3=1  5=1  6=1  7=1 8=2 9=1
            mp[arr1[i]]++;
        }
        
        for(int i=0;i<m;i++){
            if(mp.find(arr2[i])!=mp.end()){
                int x=mp[arr2[i]];
                while(x--){
                    ans.push_back(arr2[i]);
                }
                
                mp.erase(arr2[i]);
            }
        }
        
        for(auto it:mp){
            int x=it.second;
            while(x--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends