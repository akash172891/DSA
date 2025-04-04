//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends

// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int input) {
        // Code here
         if (root == NULL) return -1;
        if(root->data==input)return input;
        int ans=-1;
        while(root!=NULL){
            if(root->data == input)return input;
            else if(root->data <input){
                ans=max(ans,root->data);
                if(root->right)root=root->right;
                else return ans;
            }
            else{
                if(root->left)root=root->left;
                else break;
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends