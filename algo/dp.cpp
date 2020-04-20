#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout);
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

char a[9][9];
char fun(char a,multiset<char>&s1,multiset<char>&s2){
    for(char ch='1';ch<='9';ch++){
        if( ch!=a && (s1.find(ch)!=s1.end()) && (s2.find(ch)!=s2.end()) )
            return ch;
    }
    return '0';
}
multiset<char> giver(int r,int c){
    multiset<char>st;
    for(int j=0;j<9;j++){
        if(j==c)
            continue;
        st.insert(a[r][j]);
    }
    return st;
}
multiset<char> givec(int r,int c){
    multiset<char>st;
    for(int i=0;i<9;i++){
        if(i==r)
            continue;
        st.insert(a[i][c]);
    }
    return st;
}
int32_t main()
{
    fast();
    #ifndef ONLINE_JUDGE
    io();
    #endif
    int t;
    cin>>t;
    vector<pii>ans;
    ans.pb({0,0});
    ans.pb({1,4});
    ans.pb({2,7});
    ans.pb({3,5});
    ans.pb({4,2});
    ans.pb({5,6});
    ans.pb({6,1});
    ans.pb({7,3});
    ans.pb({8,8});
    while(t--){
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>a[i][j];
        for(auto x:ans){
            int r = x.ff;
            int c = x.ss;
            multiset<char> s1=giver(r,c);
            multiset<char> s2=givec(r,c);
            char res = fun(a[r][c],s1,s2);
            a[r][c]=res;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<a[i][j];
            cout<<endl;
        }
    }
}
