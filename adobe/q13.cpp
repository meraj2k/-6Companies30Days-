
//    https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/




class Solution {
  public:
    bool find(int B[],int m,int val){
        int s=0,e=m-1;
        while(s<=e){
            int m=(s+e)/2;
            if(B[m]==val){
                return true;
            }
            if(B[m]>val){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return false;
    }
    int upper(int arr[],int n,int val){
        int s=0,e=n;
        int res=-1;
        while(s<=e){
            int m=(s+e)/2;
            if(arr[m]>=val){
                res=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return res;
    }
    int findlis(vector<int> &arr){
        int n=arr.size();
        //cout<<n<<" ";
        if(n<=1) return n;
        int temp[n]={0};
        temp[0]=arr[0];
        int len=0;
        for(int i=1;i<n;i++){
            if(arr[i]>temp[len]){
                len++;
                temp[len]=arr[i];
            }else{
                int index=upper(temp,len,arr[i]);
                temp[index]=arr[i];
            }
        }
        return len+1;
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> temp;
        int i=0;
        while(i<N){
            if(find(B,M,A[i])){
                temp.push_back(A[i]);
            }
            i++;
        }
        int lis=findlis(temp);
        return N-lis+M-lis;
    }
};