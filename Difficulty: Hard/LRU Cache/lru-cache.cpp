//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class LRUCache {
  private:
  class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity, size;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Helper function to move node to front
    void moveToFront(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-2, -2);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* temp = mp[key];
        moveToFront(temp);
        return temp->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update existing node
            Node* temp = mp[key];
            temp->value = value;
            moveToFront(temp);
        } else {
            if (size == capacity) {
                // Remove LRU node
                Node* lru = tail->prev;
                mp.erase(lru->key);
                tail->prev = lru->prev;
                lru->prev->next = tail;
                delete lru;
                size--;
            }

            // Insert new node at front
            Node* newNode = new Node(key, value);
            newNode->next = head->next;
            newNode->prev = head;
            head->next->prev = newNode;
            head->next = newNode;
            mp[key] = newNode;
            size++;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends