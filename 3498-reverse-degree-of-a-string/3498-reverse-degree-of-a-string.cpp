class Solution {
public:
    int reverseDegree(string s) {
        int degree=0;
        int d=26;
        unordered_map<char,int>mpp;
        for(char i='a';i<='z';i++){
            mpp[i]=d--;
        }
        for(int i=0;i<s.length();i++){
            degree+=((i+1)*mpp[s[i]]);
        }
        return degree;
    }
};