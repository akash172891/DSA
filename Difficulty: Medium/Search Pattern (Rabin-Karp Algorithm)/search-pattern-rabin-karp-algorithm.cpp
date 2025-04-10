//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    const int PRIME = 101; 

        // Function to calculate the hash value of a string
        long long calculateHash(const string &str, int end) {
            long long hash = 0;
            for (int i = 0; i < end; i++) {
                hash += str[i] * pow(PRIME, i);
            }
            return hash;
        }
        
        // Function to recalculate the hash value for the sliding window
        long long recalculateHash(const string &str, int oldIndex, int newIndex, long long oldHash, int patternLength) {
            long long newHash = oldHash - str[oldIndex];
            newHash /= PRIME;
            newHash += str[newIndex] * pow(PRIME, patternLength - 1);
            return newHash;
        }
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> result;
            int textLength = text.length();
            int patternLength = pattern.length();
        
            if (patternLength > textLength) {
                return result; // Pattern longer than text, no match possible
            }
        
            long long patternHash = calculateHash(pattern, patternLength);
            long long textHash = calculateHash(text, patternLength);
        
            for (int i = 0; i <= textLength - patternLength; i++) {
                if (patternHash == textHash && text.substr(i, patternLength) == pattern) {
                    result.push_back(i+1); // Match found
                }
                if (i < textLength - patternLength) {
                    textHash = recalculateHash(text, i, i + patternLength, textHash, patternLength);
                }
            }
        
            return result;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends