
//   https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int i=0,j=0,res=INT_MAX,n=nums.size();
        while(j<n){
            sum+=nums[j++];
            while(sum>=target){
                res=min(res,j-i);
                sum=sum-nums[i++];
            }
        }
        return res==INT_MAX?0:res;
    }
};