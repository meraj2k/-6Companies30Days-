
//   https://leetcode.com/problems/split-array-largest-sum/



class Solution {
public:
    bool isPossible(vector<int> &nums,int m,int p){
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>p) return false;
            sum+=nums[i];
            if(sum>p){
                count++;
                sum=nums[i];
            }
        }
        count++;
        return count<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int s=1,e=0;
        for(int x:nums){
            e+=x;
        }
        int res=0;
        while(s<=e){
            int p=s+(e-s)/2;
            //cout<<p<<"  " ;
            if(isPossible(nums,m,p)){
                res=p;
                e=p-1;
            }else{
                s=p+1;
            }
        }
        return res;
    }
};