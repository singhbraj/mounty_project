#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define MAX 10000
#define size(a) a.size() 

const int MX=1e9+7;

inline int red(int a,int b){
return ((a%MX)*(b%MX))%MX;
}

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

vector<int> segmented_seive(int range){
	vector<int> primes;
	int s = 0, e = MAX;
	while(e <= range){
		seive(s, e, primes);
	
		s = e;
		e += MAX;
	}
	return primes;
}

int ways(vector<int> &v){
	vector<int> primes = segmented_seive(MAX);
	int ways = 1;
	for(int i=0; i< size(primes) && primes[i] < 350; i++){
		int cnt = 0;
		for(int j=0; j<size(v); j++){
			while(v[j]%primes[i] == 0){
				cnt++;
				v[j] = v[j]/primes[i];
			}
		}
		
			ways = red(ways,(cnt +1));
		
	}
	return ways%MX;
}


void dfs(vector<int> v[],bool vis[],int x,int y,vector<int>& stack) 
{ 
	stack.push_back(x); 
	if(x==y){ 
	    
		return; 
	} 
	vis[x]=true; 

	int flag = 0; 
	if (!v[x].empty()){ 
		for (auto i:v[x]){ 
			if (!vis[i]) { 
				 dfs(v,vis,i,y,stack); 
				flag = 1; 
			} 
		} 
	} 
	if(!flag) { 
		stack.pop_back(); 
	} 
} 

signed main() 
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	 cout.tie(NULL);

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
           cin>>cost[i];
         cin>>q;
         
       
        while(q--){
            cin>>x>>y;
            bool vis[n + 1]; 
	        memset(vis, false, sizeof(vis));
            vector<int> stack,arr;
            dfs(v,vis,x,y,stack);
			for(auto i:stack)
			 arr.push_back(cost[i]);
			cout<<ways(arr)%MX<<endl;
          

        }
	
          
        
     }


return 0; 
} 
