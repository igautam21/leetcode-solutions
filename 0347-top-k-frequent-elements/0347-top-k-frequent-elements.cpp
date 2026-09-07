class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto x:mpp){
            minh.push({x.second,x.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int>ans;
        while(k--){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};