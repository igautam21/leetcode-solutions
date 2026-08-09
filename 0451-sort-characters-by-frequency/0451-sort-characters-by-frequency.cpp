class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        vector<int>frq(256,0);
        for(int i=0;i<s.length();i++){
            frq[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(int i=0;i<256;i++){
            if(frq[i]>0){
                v.push_back({frq[i],(char)i});
            }
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto x:v){
            int frequency=x.first;
            char charector=x.second;
            while(frequency--){
                ans+=charector;
            }
        }
        return ans;     
    }
};