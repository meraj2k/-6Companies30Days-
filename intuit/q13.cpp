
//    https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid



class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v;
        int n=grid.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0 && grid[i][j]==0;j--){
                count++;
            }
            //cout<<count<<endl;
            v.push_back(count);
        }
        int res=0;
        int t=n-1;
        int s=0;
        for(int i=t;i>0;i--){
            int j;
            for(j=s;j<v.size();j++){
                if(v[j]>=i){
                    res+=j-s;
                    break;
                }
            }
            if(v.size()==j) return -1;
            int x=v[j];
            for(;j>s;j--){
                v[j]=v[j-1];
            }
            v[s]=x;
            s++;
        }
        return res;
    }
};