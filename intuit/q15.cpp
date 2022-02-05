//   https://leetcode.com/problems/koko-eating-bananas/


class Solution {
public:
    bool check(vector<int> &piles,int h,int k){
        int count=0;
        for(int x:piles){
            if(x%k!=0){
                count++;
            }
            count+=x/k;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=0;
        //cout<<l<<" "<<r<<endl;
        for(int x:piles){
            //l=min(l,x);
            r=max(r,x);
        }
        
        int res=-1;
        while(l<=r){
            int k=l+(r-l)/2;
            //cout<<k<<endl;
            if(check(piles,h,k)){
                res=k;
                r=k-1;
            }else{
                l=k+1;
            }
        }
        return res;
    }
};