class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        for(int len=2;len<=9;len++){
            for(int start=0;start<=s.length()-len;start++){
                int n=stoi(s.substr(start,len));
                if(n<=high && n>=low) ans.push_back(n);
            }
        }
        return ans;
    }
};