

//  https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int> mp;
        for(int x: nums){
            x=x%k;
            int t=(k-x)%k;
            if(mp.find(t)!=mp.end()){
                mp[t]--;
                if(mp[t]==0){
                    mp.erase(t);
                }
            }else{
                mp[x]++;
            }
        }
        return mp.size()==0?1:0;
    }
};