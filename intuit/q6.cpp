
//     https://leetcode.com/problems/find-in-mountain-array




/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &mountainArr){
        int s=0,n=mountainArr.length();
        int e=n-1;;
        while(s<=e){
            int m=(s+e)/2;
            if((m==0 ||mountainArr.get(m)>mountainArr.get(m-1))&& (m==n-1 || mountainArr.get(m)>mountainArr.get(m+1) )){
                return m;
            }else if(mountainArr.get(m)<mountainArr.get(m+1)){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return -1;
    }
    
    int find1(int s,int e,MountainArray &mountainArr,int target){
        while(s<=e){
            int m=(s+e)/2;
            int val=mountainArr.get(m);
            if(val==target) return m;
            if(val>target){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return -1;
    }
    
    int find2(int s,int e,MountainArray &mountainArr,int target){
        while(s<=e){
            int m=(s+e)/2;
            int val=mountainArr.get(m);
            if(val==target) return m;
            if(val<target){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p=peak(mountainArr);
        //cout<<p<<endl;
        int l=find1(0,p,mountainArr,target);
        if(l!=-1) return l;
        return find2(p+1,mountainArr.length()-1,mountainArr,target);
    }
};