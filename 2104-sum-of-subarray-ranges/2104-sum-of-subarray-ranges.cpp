class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>PSE(n),NSE(n),NGE(n),PGE(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            NSE[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            PSE[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            PGE[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            NGE[i]=st.empty()?n:st.top();
            st.push(i);
        }
        long long minSum=0;
        for(int i=0;i<n;i++){
            long long left=i-PSE[i];
            long long right=NSE[i]-i;
            minSum+=left*right*nums[i];
        }
        long long maxSum=0;
        for(int i=0;i<n;i++){
            long long left=i-PGE[i];
            long long right=NGE[i]-i;
            maxSum+=left*right*nums[i];
        }
        long long ans=maxSum-minSum;
        return ans;
    }
};