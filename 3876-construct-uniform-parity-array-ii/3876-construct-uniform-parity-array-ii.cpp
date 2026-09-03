class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=INT_MAX,even=INT_MAX;
        int n=nums1.size();
        for(auto x:nums1){
            if(x%2==0){
                even=min(even,x);
            }
            else{
                odd=min(odd,x);
            }
        }
        if(odd==INT_MAX || even==INT_MAX) return true;
        if(odd>even){
            return false;
        }
        return true;
    }
};