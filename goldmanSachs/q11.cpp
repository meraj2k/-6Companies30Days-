
//   https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int a=0;
        for(int i=0;i<n;i++){
            a^=arr[i];
            a^=(i+1);
        }
        int mark=a&(~(a-1));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(mark&arr[i]){
                x^=arr[i];
            }else{
                y^=arr[i];
            }
            if(mark&(i+1)){
                x^=(i+1);
            }else{
                y^=(i+1);
            }
        }
        int *res= new int[2];
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                res[0]=x;
                res[1]=y;
                return res;
            }
        }
        res[0]=y;
        res[1]=x;
        return res;
    }
};
