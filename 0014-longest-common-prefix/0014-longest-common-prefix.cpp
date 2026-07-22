class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st=strs[0];
        string ans="";
        for(int i=0;i<st.length();i++){
            for(int j=0;j<strs.size();j++){
                if(st[i]!=strs[j][i]) return ans;
            }
            ans+=st[i];
        }
        return ans;
    }
};