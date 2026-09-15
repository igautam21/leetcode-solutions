class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int g=0;
        for(int i=0;i<lights.size();i++){
            g=max(g,lights[i]);
        }
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r=arrivalTime[i]%period;
            int wt=0;
            if(r<g){
                wt=0;
            }
            else wt=period-r;
            ans=max(ans,wt);
        }
        return ans;
    }
};