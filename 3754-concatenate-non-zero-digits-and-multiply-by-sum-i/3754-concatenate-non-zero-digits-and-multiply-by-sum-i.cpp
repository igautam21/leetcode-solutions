class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') continue;
            ans+=s[i];
        }
        int t=ans.empty()?0:stoi(ans);
        return 1LL*t*sum;
    }
};