class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int l=0,r=n-1,lmax=height[0],rmax=height[n-1];
        int total=0;
        while(l<=r){
            if(lmax<=rmax){
                if(lmax>height[l]){
                    total+=(lmax-height[l]);
                }
                else{
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(rmax>height[r]){
                    total+=(rmax-height[r]);
                }
                else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};