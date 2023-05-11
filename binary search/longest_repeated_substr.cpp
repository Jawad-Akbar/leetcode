class Solution {
public:
    bool exist(int len,string &s){
        set<string>strings;

        for (int i=0;i<=s.size()-len;i++)
        {
            string temp=s.substr(i,len);
            if (strings.find(temp)!=strings.end())
                return true;
            strings.insert(temp);
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        int l=0;
        int h=s.size();
        while (l+1<h){
            int m=(l+h)/2;
            if (exist(m,s))
                l=m;
            else
                h=m;
        }
        return l;
    }
};