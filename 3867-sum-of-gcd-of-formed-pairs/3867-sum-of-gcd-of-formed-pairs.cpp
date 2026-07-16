class Solution {
public:
    long long gcdd(int a,int b){
        if(b==0) return a;
        return gcdd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int>mx(nums.size());
        mx[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        vector<int>pregcd;
        for(int i=0;i<nums.size();i++){
            pregcd.push_back(gcdd(mx[i],nums[i]));
        }
        sort(pregcd.begin(),pregcd.end());
        long long sum=0;
        int l=0,r=nums.size()-1;
        while(l<r){
            sum+=gcdd(pregcd[l],pregcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};