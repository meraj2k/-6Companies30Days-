
//    https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/



class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
          int h=0;
          for(int i=0;i<k;i++){
              h=max(h,KSortedArray[i][0]);
              pq.push({KSortedArray[i][0],{i,0}});
          }
          pair<int,int> res={pq.top().first,h};
          while(!pq.empty()){
              pair<int,pair<int,int>> t=pq.top();
              pq.pop();
              if(res.second-res.first > (h-t.first)){
                  res={t.first,h};
              }
              if(t.second.second <n-1){
                    h=max(h,KSortedArray[t.second.first][t.second.second+1]);
                    pq.push({KSortedArray[t.second.first][t.second.second+1],{t.second.first,t.second.second+1}});
              }
              
              if(t.second.second==n-1){
                  break;
              }
          }
          return res;
    }
};