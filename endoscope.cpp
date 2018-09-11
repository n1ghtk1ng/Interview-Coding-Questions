#include<bits/stdc++.h>
using namespace std;

// dp? and what if arr[x][y]==0 ? can we go there or not

bool isSafe(int x,int y,int m,int n,bool **vis,int **arr){
if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && arr[x][y]!=0){
    return true;
}
return false;

}
int dfs(int x,int y,int m,int n,int **arr,int len,bool **vis);

int calldown(int x,int y,int m,int n,int **arr,int len,bool**vis){
    if(isSafe(x+1,y,m,n,vis,arr)){
        return 1+dfs(x+1,y,m,n,arr,len-1,vis);
    }
    return 1;

}
int callup(int x,int y,int m,int n,int **arr,int len,bool**vis){
    if(isSafe(x-1,y,m,n,vis,arr)){
        return 1+dfs(x-1,y,m,n,arr,len-1,vis);
    }
    return 1;

}
int callleft(int x,int y,int m,int n,int **arr,int len,bool**vis){
    if(isSafe(x,y-1,m,n,vis,arr)){
        return 1+dfs(x,y-1,m,n,arr,len-1,vis);
    }
    return 1;

}
int callright(int x,int y,int m,int n,int **arr,int len,bool**vis){
    if(isSafe(x,y+1,m,n,vis,arr)){
        return 1+dfs(x,y+1,m,n,arr,len-1,vis);
    }
    return 1;

}

int dfs(int x,int y,int m,int n,int **arr,int len,bool **vis){

if(len==0)
    return 0;

vis[x][y]=true;
int cnt=INT_MIN;

if(arr[x][y]==1){
    cnt=max(cnt,callup(x,y,m,n,arr,len,vis));
    cnt=max(cnt,calldown(x,y,m,n,arr,len,vis));
    cnt=max(cnt,callleft(x,y,m,n,arr,len,vis));
    cnt=max(cnt,callright(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==2){
    cnt=max(cnt,callup(x,y,m,n,arr,len,vis));
    cnt=max(cnt,calldown(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==3){
    cnt=max(cnt,callleft(x,y,m,n,arr,len,vis));
    cnt=max(cnt,callright(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==4){
    cnt=max(cnt,callup(x,y,m,n,arr,len,vis));
    cnt=max(cnt,callright(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==5){
    cnt=max(cnt,callright(x,y,m,n,arr,len,vis));
    cnt=max(cnt,calldown(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==6){
    cnt=max(cnt,callleft(x,y,m,n,arr,len,vis));
    cnt=max(cnt,calldown(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}
if(arr[x][y]==7){
    cnt=max(cnt,callleft(x,y,m,n,arr,len,vis));
    cnt=max(cnt,callup(x,y,m,n,arr,len,vis));
    vis[x][y]=false;
    return cnt;
}


}

int main(){

int t;
cin>>t;

while(t--){
    int n,m;

    cin>>n>>m;

    int x,y,len;
    cin>>x>>y>>len;


    int **arr=new int*[n+1];
    bool **vis=new bool*[n+1];

    for(int i=0;i<=n;i++){
        arr[i]=new int[m+1];
        vis[i]=new bool[m+1];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            vis[i][j]=false;
        }
    }
    cout<<dfs(x,y,m,n,arr,len,vis);



}

/*
1
3 3
1 1 10
1 2 1
1 2 6
1 2 7
*/

return 0;
}
