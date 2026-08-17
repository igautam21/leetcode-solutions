class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=-1;
        int mindist=INT_MAX;
        int x1=target[0],y1=target[1];
        for(int i=0;i<drones.size();i++){
            int dist=abs(drones[i][0]-x1)+abs(drones[i][1]-y1);
            if(dist<=drones[i][2] && dist<mindist){
                mindist=dist;
                ans=i;
            }
        }
        return ans;
    }
};