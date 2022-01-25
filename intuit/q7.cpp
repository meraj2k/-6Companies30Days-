
//    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days




class Solution {
public:
    bool check(vector<int> &weights,int d,int cap){
        int sum=0,c=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>cap) return false;
            sum+=weights[i];
            if(sum>cap){
                c++;
                sum=weights[i];
            }
        }
        c++;
        return c<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=1,e=0;
        for(int x:weights){
            e+=x;
        }
        int res;
        while(s<=e){
            int m=(s+e)/2;
            if(check(weights,days,m)){
                res=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return res;
    }
};