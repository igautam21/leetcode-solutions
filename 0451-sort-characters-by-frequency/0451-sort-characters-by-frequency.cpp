class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>maxh;
        for(auto x:mpp){
            maxh.push({x.second,x.first});
        }
        string ans="";
        while(maxh.size()>0){
            int frq=maxh.top().first;
            char ele=maxh.top().second;
            for(int i=0;i<frq;i++){
                ans+=ele;
            }
            maxh.pop();
        }
        return ans;
    }
};