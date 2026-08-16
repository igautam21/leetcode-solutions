class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0 && st.empty()){
                ans.push_back(asteroids[i]);
                continue;
            }
            while(!st.empty() && asteroids[i]<0 && abs(asteroids[i])>st.top()){
                st.pop();
                if(st.empty()) ans.push_back(asteroids[i]);
            }
            if(!st.empty() && asteroids[i]<0 && abs(asteroids[i])==st.top()) st.pop();
            if(asteroids[i]>=0) st.push(asteroids[i]);
        }
        int c=0;
        int n=ans.size();
        while(!st.empty()){
            c++;
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin()+n,ans.begin()+n+c);
        return ans;
    }
};