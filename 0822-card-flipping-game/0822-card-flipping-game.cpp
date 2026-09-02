class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n=fronts.size();
        int good=INT_MAX;
        unordered_set<int>bad;
        for(int i=0;i<n;i++){
            if(fronts[i]==backs[i]){
                bad.insert(fronts[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(bad.find(fronts[i])==bad.end()){
                good=min(good,fronts[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(bad.find(backs[i])==bad.end()){
                good=min(good,backs[i]);
            }
        }
        if(good==INT_MAX) good = 0;
        return good;
    }
};