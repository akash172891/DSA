class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string str="";
        for(auto it:s) {
            str+=it;
            str.push_back('#');
        }
        return str;
        
    }

    vector<string> decode(string& s) {
        
        // code here
        
        vector<string>str;
        
        string tmp = "";
        
        for(int i=0;i<s.length();i++)  {
            if(s[i]=='#') {
                str.push_back(tmp);
                tmp="";
            }
            else tmp.push_back(s[i]);
        }
        
        return str;
    }
};