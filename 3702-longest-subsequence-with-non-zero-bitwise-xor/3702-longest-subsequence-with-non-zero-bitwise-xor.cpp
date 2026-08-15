class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        bool allZero=true;
        for(auto x:nums){
            res=(res^x);
            if(x!=0) allZero=false;
        }
        if(allZero) return 0;
        if(res==0){
            return n-1;
        }
        else{
            return n;
        }
    }
};