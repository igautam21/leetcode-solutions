class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(3,-1);  //hash=last seen
        int c=0;
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                c+=min({hash[0],hash[1],hash[2]})+1;
            }
        }
        return c;
    }
};