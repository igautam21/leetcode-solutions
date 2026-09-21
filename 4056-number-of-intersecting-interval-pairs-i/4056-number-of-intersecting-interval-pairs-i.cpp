class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        for(int i=0;i<intervals.size();i++){
            int j=i+1;
            while(j<intervals.size()){
                if (intervals[i][0] <= intervals[j][1] &&
                    intervals[j][0] <= intervals[i][1]) {
                    ans++;
                }
                j++;
            }
        }
        return ans;
    }
};