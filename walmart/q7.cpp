
//    https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/


class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        int temp[N];
        int mn=arr[N-1];
        temp[N-1]=mn;
        for(int i=N-2;i>=0;i--){
            temp[i]=temp[i+1];
            if(arr[i]>mn){
                
                mn=arr[i];
                temp[i]=mn;
            }
        }
        int mx=arr[0];
        for(int i=1;i<N-1;i++){
            if(mx<arr[i] && arr[i]<temp[i]){
                //cout<<"h";
                return {mx,arr[i],temp[i]};
            }
            if(mx>arr[i]){
                mx=arr[i];
            }
        }
        return {};
    }
};