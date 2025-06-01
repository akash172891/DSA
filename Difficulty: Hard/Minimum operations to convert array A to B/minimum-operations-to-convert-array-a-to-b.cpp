// User function Template for C++

class Solution {
  public:
    int lis(vector<int> &v) {
        int n=v.size();
        vector<int> len;
        for(int i=0; i<n; i++) {
            auto it=lower_bound(len.begin(),len.end(),v[i]);
            if(it!=len.end()) *it=min(*it,v[i]);
            else len.push_back(v[i]);
        }
        return len.size();
    }
    int minInsAndDel(int a[], int b[], int n, int m) {
        unordered_set<int> s(b,b+m);
        vector<int> aNew;
        int count=0;
        for(int i=0; i<n; i++) {
            if(s.find(a[i])!=s.end()) {
                aNew.push_back(a[i]);
            }
        }
        // count+=n-aNew.size();
        // count+=aNew.size()-size+m-size;
        int size=lis(aNew);
        count+=m+n-2*size;
        return count;
    }
};