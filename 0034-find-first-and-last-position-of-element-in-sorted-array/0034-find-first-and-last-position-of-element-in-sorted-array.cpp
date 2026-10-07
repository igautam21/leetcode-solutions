class Solution {
public:
    int first(vector<int>&nums,int target){
        int ans=-1,low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int last(vector<int>&nums,int target){
        int ans=-1,low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int f=first(nums,target);
        int l=last(nums,target);
        if(f==-1 || nums[f]!=target || f>l) return {-1,-1};
        return {f,l};
    }
};