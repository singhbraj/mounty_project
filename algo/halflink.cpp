#include<bits/stdc++.h>
using namespace std;
//int a[3][3];
void solve(int **grid,int i,int j,int n,int m,bool &f){
	if(i==n || j==m)
	  return ;
	if(grid[i][j]==9){f=true;
	  return ;}
	else if(grid[i][j]==0)
	 return ;
	solve(grid,i+1,j,n,m,f);
	solve(grid,i,j+1,n,m,f);
return;

}
int isPath(int **grid,int m,int n){

 bool f=false;
 if(grid[0][0]==0) 
   return 0;
   
 solve(grid,0,0,m,n,f);
  if(f)
  return 1;
  else
  {
	  return 0;
  }
  
}
int main(){
	int n,m;
	cin>>n>>m;
	int **a=new int*[3];
	for(int i=0;i<3;i++)
	 a[i]=new int[3];
//	int arr[n][m];
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	  cin>>a[i][j];
	//  int x=print_(n,m);
	  cout<<isPath(a,n,m)<<endl;
}
/*
3 3
1 1 1
1 9 1
0 1 0*/