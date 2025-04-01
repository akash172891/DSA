//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
     int distanceK(Node* root, int target) {

        map<int, set<int>> adj;
        // vector<int> ans;
        if(!root) return 0;

        queue<Node*> q;

        q.push(root);

        //construct a adjacency list from the given tree while traversing using BFS
        while(!q.empty()){
            int n = q.size();

            for(int i=0;i<n;i++) {
                Node* node = q.front();

                if(node->left) {
                    q.push(node->left);
                    adj[node->data].insert(node->left->data);
                    adj[node->left->data].insert(node->data);
                }
                if(node->right) {
                    q.push(node->right);
                    adj[node->data].insert(node->right->data);
                    adj[node->right->data].insert(node->data);
                }
                q.pop();
            }
        }

        queue<int> q1;
        //bfs target node till k depth
        q1.push(target);
        int level = 0;
        set<int> vis;

        while(!q1.empty()) {
            int n = q1.size();
            for(int i=0;i<n;i++) {
                
                int node = q1.front();
                // if(level==k) ans.push_back(node->val);
                q1.pop();
                vis.insert(node);

                for(auto it : adj[node]) {
                    if(vis.find(it)==vis.end()) q1.push(it);
                }
                

            }
            level++;
        }

        return level-1;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        
        return distanceK(root, target);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends