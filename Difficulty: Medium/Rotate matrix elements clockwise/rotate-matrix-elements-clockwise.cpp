//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
        vector<vector<int>>ans;
       int temp;
       int prev;
       int rowbegin=0;
       int colbegin=0;
       int rowend=M;
       int colend=N;
        
     while(rowbegin<rowend&&colbegin<colend){
         if(rowbegin+1==rowend||colbegin+1==colend)
         break;
       prev=Mat[rowbegin+1][colbegin];
       for(int i=colbegin;i<colend;i++)
       {
            temp=Mat[rowbegin][i];
           Mat[rowbegin][i]=prev;
           prev=temp;
       }
       rowbegin++;
       for(int i=rowbegin;i<rowend;i++)
       {
           temp=Mat[i][colend-1];
           Mat[i][colend-1]=prev;
           prev=temp;
       }
       colend--;
       if(rowbegin<rowend){
       for(int i=colend-1;i>=colbegin;i--)
       {
           temp=Mat[rowend-1][i];
           Mat[rowend-1][i]=prev;
           prev=temp;
       }}rowend--;
       if(colbegin<colend){
       for(int i=rowend-1;i>=rowbegin;i--)
       {
           temp=Mat[i][colbegin];
           Mat[i][colbegin]=prev;
           prev=temp;
       }}
       colbegin++;
       
     }
       return Mat;


    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    
cout << "~" << "\n";
}
}
// } Driver Code Ends