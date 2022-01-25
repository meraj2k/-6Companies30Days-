
//    https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/



int missingNumber(const string& str)
{
    // Code here
    int n=str.length();
    for(int l=1;l<=min(6,n);l++){
        int s=0;
        for(int i=0;i<l;i++){
            s=s*10+str[i]-'0';
        }
        //cout<<s<<" ";
        int i=l;
        int num=0;
        bool flag=0;
        int miss;
        while(i<n){
            num=num*10+str[i]-'0';
            if(num<=s){
                i++;
                continue;
            }
            //cout<<num<<"  ";
            if(num>s && s+1==num){
                s=num;
                num=0;
            }else if(flag==0 && s+2==num){
                flag=1;
                miss=s+1;
                s=num;
                num=0;
            }else{
                break;
            }
            i++;
        }
         //cout<<endl;
        if(i==n && flag) return miss;
       
    }
    return -1;
}