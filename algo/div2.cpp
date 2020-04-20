#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define MAX 1000005
#define size(a) a.size() 

const int MX=1e9+7;
const int N=1e5+5;

inline int red(int a,int b){
return ((a%MX)*(b%MX))%MX;
}
int prime[10*N];

void seive(int start, int end, vector<int> &primes){
	vector<int> v(MAX, 1);
	for(int i = 0; i < size(primes); i++)
		for(int j = start/primes[i]; j <= end/primes[i]; j++)
			if( primes[i]*j >= start)
				v[ (primes[i]*j) - start ] = 0;
	for(int i = start; i < end; i++){
		if(v[ i - start ] && i > 1){
			primes.push_back(i);
			for(int p = i; p <= end/i; p++){
				v[ (i*p)- start ] = 0;
			}
		}
	}
}

void segmented_seive(){
	      prime[0]=prime[1]=1;
    for(int i=2;i<10*N;i++){
        if(prime[i]==0){
            prime[i]=i;
            for(int j=2*i;j<10*N;j+=i)
                prime[j]=i;
        }
    }
}

// void printfact(int n){
//     while(n!=1)
//         cout<<prime[n]<<" ",n/=prime[n];
//     cout<<endl;
// }

class node{
   public:
   map<int,int> mp;

   node(int n=1){
	    while(n!=1){
            mp[prime[n]]++;
            n /= prime[n];
        }
   }
   void merge_(node &a,node &b);
   void print_a_();
   void add_(int);
   void sub_(node &a,node &b);
   int value_();
};

void node:: merge_(node &a,node &b){
	                    for(auto x : b.mp)
                        a.mp[x.first]+=x.second;
	                
          }
void node:: add_(int n){
        while(n!=1){
            mp[prime[n]]++;
            n /= prime[n];
        }
    }
void node:: sub_(node &a,node &b){
        for(auto x : b.mp)
            a.mp[x.first]-=2*(x.second);
    }
void node:: print_a_(){
        for(auto x:mp)
            cout<<x.first<<" : "<<x.second<<endl;
        cout<<endl;
    }
int node:: value_(){
        int ct=1;
        for(auto x:mp){
            ct=(ct*(x.second+1))%MX;
        }
        return ct;
    }

node tree[N];
int parent[N],level[N],arr[N];
int dp[N][20];
void build(vector<int>adj[],int n){
	memset(dp,-1,sizeof(dp));
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(1);
    vis[1]=true;
    level[1]=0;
    parent[1]=-1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto x :adj[v]){
            if(!vis[x]){
                vis[x]=true;
                q.push(x);
                parent[x]=v;
                level[x]=1+level[v];
                tree[x].merge_(tree[x],tree[v]);
            }
        }
    }
    for(int j=0;j<20;j++){
        for(int i=1;i<=n;i++){
            if(j==0)
                dp[i][j]=parent[i];
            else{
                int p=dp[i][j-1];
                if(p!=-1)
                    dp[i][j]=dp[p][j-1];
            }
        }
    }
}
int lca(int a,int b){
    if(level[a] > level[b])
        swap(a,b);
    int d=level[b]-level[a];
    for(int j=0;j<20;j++){
        if(d&(1<<j))
            b=dp[b][j];
    }
    if(a==b)
        return a;
    for(int j=19;j>=0;j--){
        if(dp[a][j]!=dp[b][j])
            a=dp[a][j],b=dp[b][j];
    }
    return parent[a];
}

signed main() 
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	 cout.tie(NULL);
	 segmented_seive();
     int t;
     cin>>t;
     while(t--){
         int n,x,y,q;
         cin>>n;
         vector<int> v[n+1];
         vector<int> cost(n+1);
         for(int i=0;i<n-1;i++){
             cin>>x>>y;
             v[x].push_back(y);
             v[y].push_back(x);
         }
         for(int i=1;i<=n;i++)
           cin>>cost[i],tree[i]=node(arr[i]);;
		build(v,n);
         cin>>q;   
        while(q--){
            cin>>x>>y;
            node temp;
            temp.merge_(temp,tree[x]);
            temp.merge_(temp,tree[y]);
            int p=lca(x,y);
            temp.sub_(temp,tree[p]);
            temp.add_(arr[p]);
            cout<<temp.value_()<<endl;
        }
     }


return 0; 
} 
