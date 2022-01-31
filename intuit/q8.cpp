//   https://leetcode.com/problems/number-of-boomerangs/



class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp(n);
            for(int j=0;j<n;j++){
                if(i==j) continue;
                vector<int> a=points[i],b=points[j];
                int d=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
                mp[d]++;
            }
            for(auto it=mp.begin();it!=mp.end();it++){
                int c=it->second;
                //cout<<it->first<<" "<<c<<endl;
                res+=(c*(c-1));
            }
        }
        return res;
    }
};