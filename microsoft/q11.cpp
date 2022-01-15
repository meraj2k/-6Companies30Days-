
//     https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/



vector<string> generate(int N)
{
	// Your code here
	vector<string> res;
	for(int i=1;i<=N;i++){
	    int n=i;
	    string s;
	    while(n){
	        s+=('0'+n%2);
	        n=n/2;
	    }
	    reverse(s.begin(),s.end());
	    res.push_back(s);
	}
	return res;
}
