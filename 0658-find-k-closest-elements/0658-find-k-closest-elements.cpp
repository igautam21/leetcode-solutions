class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxh;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxh.push({abs(x-arr[i]),arr[i]});
            if(maxh.size()>k) maxh.pop();
        }
        vector<int>ans;
        while(k>0){
            ans.push_back(maxh.top().second);
            maxh.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};