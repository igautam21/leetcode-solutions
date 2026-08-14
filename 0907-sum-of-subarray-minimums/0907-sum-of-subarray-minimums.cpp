class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSE(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) NSE[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int>PSE(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) PSE[i]=st.top();
            st.push(i);
        }

        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            long long subarrays=1LL*left*right;
            int contri=(1LL*subarrays*arr[i])%mod;
            sum=(sum+contri)%mod;
        }
        return sum;
    }
};