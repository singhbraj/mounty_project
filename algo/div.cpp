#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int M=1e9+7;
const int MAX=1e5+7;

int dp[MAX];
int dp2[MAX];
vector<int> v;
void power(int n) 
{ 
    dp2[1]=1;
    
    for(int i=2;i*i<=MAX;i++) { 
        int j=i*i; 
         
        dp2[j]=1;;
        while (j * i <=MAX) { 
            dp2[j*i]=1;
            j=j*i; 
        } 
    } 
    
} 

int fun(int n){
    int x=0;
    for(auto i:v){
        if(i>n)
          break;
        else if(n%i==0){
            x=(x+i)%M;
        }
    }
    return x;
}
signed main(){
     memset(dp,0,sizeof(dp));
     memset(dp2,0,sizeof(dp2));
     power(MAX);
     for(int i=1;i<MAX;i++){
         if(dp2[i])
         v.push_back(i);
     }
     //dp[1]=1;
     for(int i=1;i<v.size();i++){
           for(int j=v[i-1];j<MAX;j=j+v[i-1])
             dp[j]=(dp[j]+v[i-1])%M;
     }
     memset(dp2,0,sizeof(dp2));
     dp2[1]=dp[1];
     for(int i=2;i<MAX;i++){
         dp2[i]=(dp2[i-1]+dp[i])%M;
     }
     for(int i=0;i<=50;i++)
       cout<<v[i]<<" ";
       cout<<endl;
    int t;
       scanf("%lld",&t);
       while(t--){
          int n;
         scanf("%lld",&n);
         printf("%lld\n",dp2[n]);
       }
}