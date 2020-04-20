#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
struct node
{
    ll x,y,z;
    char c;
};

bool cmp(node s1,node s2) 
{ 
    return (s1.y < s2.y); 
}
bool cmp2(node s1,node s2) 
{ 
    return (s1.z < s2.z); 
}
bool check(vector<ll> v,ll x,ll y){
    for(ll i=x;i<=y;i++)
     if(v[i]!=0)
       return false;
     return true;
}

int main(){
    ll tc;
    cin>>tc;
    for(ll t=1;t<=tc;t++){
        ll n;
        cin>>n;
        ll x,y;
        //vector<pair<ll,ll>> v;
        node v[n];
        for(ll i=0;i<n;i++){
            cin>>x>>y;
            v[i].x=x;
            v[i].y=y;
            v[i].z=i;
            v[i].c='N';

            
        }
         sort(v,v+n,cmp);

        // i = 0; 
         bool mark[n];
         memset(mark,false,sizeof(mark));
         mark[0]=true;
 
    ll i=0;
    v[0].c='C';
    for (ll j = 1; j < n; j++) 
    { 
      if (v[j].x >= v[i].y) 
      { 
          mark[j]=true;
          v[j].c='C';
        
          i = j; 
      } 
    }
    ll sz=0;
      for(ll i=0;i<n;i++)
          if(!mark[i])sz++;
      node extr[sz];
    x=0;
    for(i=0;i<n;i++){
        if(v[i].c=='N'){
            extr[x].x=v[i].x;
            extr[x].y=v[i].y;
            extr[x].z=v[i].z;
            extr[x].c=v[i].c;
            x++;
        }
    }
    i=0;
    extr[0].c='J';
    for (ll j = 1; j < sz; j++) 
    { 
      if (extr[j].x >= extr[i].y) 
      { 

         extr[j].c='J';
        
          i = j; 
      } 
    }
      bool safe=true;
      for(i=0;i<sz;i++){
          if(extr[i].c=='N'){
              safe=false;
              break;
          }
      } 
    // for(i=0;i<sz;i++){
    //     cout<<extr[i].x<<" "<<extr[i].y<<" "<<extr[i].z<<" "<<extr[i].c<<endl;
    // }
        if(!safe){
    cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";        
        }
        else{  string str="";
            for(i=0;i<n;i++)
            str=str+'C';           
             for(i=0;i<n;i++){
                 str[v[i].z]=v[i].c;
             }
             for(i=0;i<sz;i++){
                 str[extr[i].z]=extr[i].c;
             }
            cout<<"Case #"<<t<<": "<<str<<"\n";
        }
    }
}