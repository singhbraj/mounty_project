#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout); 
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
#define c(x); cout<<#x<<" : "<<x<<endl;
#define print(v); for(auto x:v) cout<<x<<" "; cout<<"\n";
#define mset(v,val); for(int i=0;i<v.size();i++) v[i]=val;
const int N=1e9+7;
const int M=1e9+7;

 int red(int a,int b){
return ((a%N)*(b%N))%N;
}

inline int power(int a,int b){
if(b==1)
    return a;
int x=power(a,b/2);
if(b&1)
return red(red(a,x),x);
return red(x,x);
}
int32_t main()
{
	fast();
    #ifndef ONLINE_JUDGE
    //io();
    #endif
   int t;
   cin>>t;
   while(t--){
    string s,r;
	cin>>s>>r;
	int a=0,k=0;
	vector<int> v;
	int x=0;
	for(int i=0;i<s.size();i++){
           if(s[i]!=r[i]){
			   a++;
			   v.push_back(i+1);
			   if(x==0){
				   
				   k++;
				   x++;
			   }
		   }
		   else{x=0;}
	}

	int ans=k*a,y,p;
	int n=v.size();
	if(ans>s.size())cout<<s.size()<<endl;
	else{
	//cout<<v[0]<<" ";
	for(int i=1;i<v.size();i++){
		//cout<<v[i]<<" ";
      x=v[i-1];
	  y=v[i];
	  if(y-x==1)continue;
      p=abs(x-y)-1;
	  x=a+p;
	  y=k-1;
	  if(ans>=(x*y)){
		  a=x;
		  k=y;
		  ans=x*y;
	  }
	}
	n=s.size();
   
	cout<<min(n,ans)<<endl;}
	
	      
    }
}