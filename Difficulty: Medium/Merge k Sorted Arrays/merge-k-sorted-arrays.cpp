//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int>solve(vector<int>&a,vector<int>&b){
        vector<int>c(a.size()+b.size());
        
        int i=0,j=0;
        int k=0;
        while(i<a.size() && j < b.size()){
            if(a[i]<=b[j]){
                c[k]=a[i];
                k++;
                i++;
            }
            else{
                c[k]=b[j];
                k++;
                j++;
            }
        }
        if(i<a.size()){
            for(i;i<a.size();i++){
                c[k]=a[i];
                k++;
            }
        }
        if(j<b.size()){
            for(j;j<b.size();j++){
                c[k]=b[j];
                k++;
            }
        }
        return c;
        
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
         vector<int>ans=arr[0];
        for(int i=1;i<arr.size();i++){
           
            ans=solve(ans,arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends