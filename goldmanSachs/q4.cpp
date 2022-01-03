
//  https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

string encode(string src)
{     
  //Your code here 
  int count=1,n=src.size();
  int i=1;
  string res;
  while(i<n){
      if(src[i]!=src[i-1]){
          res+=src[i-1];
          res=res+to_string(count);
          count=1;
      }
      else{
          count++;
      }
      i++;
  }
  res+=src[i-1];
  res=res+to_string(count);
  return res;
}     