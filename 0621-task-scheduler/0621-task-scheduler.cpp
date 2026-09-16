class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(auto x:tasks){
            mpp[x]++;
        }
        priority_queue<int>maxh;
        for(auto x:mpp){
            maxh.push(x.second);
        }
        int ans=0;
        vector<int>frq;
        while(!maxh.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(!maxh.empty()){
                    int frq=maxh.top();
                    maxh.pop();
                    frq--;
                    temp.push_back(frq);
                }
            }
            for(auto f:temp){
                if(f>0) maxh.push(f);
            }
            if(maxh.empty()) ans+=temp.size();
            else ans+=n+1;
        }
        return ans;
    }
};