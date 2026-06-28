class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        int l=0,r=0,c=0,minlength=INT_MAX,sidx=-1;
        while(r<s.length()){
            if(mpp[s[r]]>0){
                c++;
            }
            mpp[s[r]]--;
            while(c==t.length()){
                if((r-l+1)<minlength){
                    minlength=(r-l+1);
                    sidx=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) c--;
                l++;
            }
            r++;
        }
        return sidx==-1?"":s.substr(sidx,minlength);
    }
};