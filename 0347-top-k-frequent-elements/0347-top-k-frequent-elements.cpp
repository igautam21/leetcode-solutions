class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>hash(20001,0);
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]+10000]++;
            mx=max(mx,nums[i]);
        }
        vector<pair<int,int>>v;
        for(int i=0;i<20001;i++){
            if(hash[i]>0) v.push_back({hash[i],i-10000});
        }
        sort(v.rbegin(),v.rend());
        vector<int>ans;
        int t=0;
        for(auto x:v){
            if(t==k) break;
            ans.push_back(x.second);
            t++;
        }
        return ans;
    }
};