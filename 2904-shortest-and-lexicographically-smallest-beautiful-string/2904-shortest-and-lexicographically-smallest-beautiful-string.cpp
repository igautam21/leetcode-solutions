class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0,r=0;
        int n=s.length();
        int c=0;
        string ans="";
        while(l<n && s[l]!='1') l++;
        if(l==n) return "";
        r=l,c=1;
        while(r<n){
            while(r<n && c<k){
                r++;
                if(r<n && s[r]=='1') c++;
            }
            if(c<k) break;
            while(l<r && s[l]!='1') {
                l++;
            }
            string sub=s.substr(l,r-l+1);
            if(ans=="" || sub.length()<ans.length() || (sub.length()==ans.length() && sub<ans)){
                ans=sub;
            }
            l++;
            c--;
            while(l<n && s[l]!='1'){
                l++;
            }
            if(l>=n) break;
            if(r<l){
                r=l;
                c=1;
            }
        }
        return ans;
    }
};