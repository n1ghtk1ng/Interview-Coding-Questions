#include<bits/stdc++.h>
using namespace std;

int cost=INT_MAX;

struct wormhole{
int sx;
int sy;
int ex;
int ey;
int cost;
    wormhole(){}
    wormhole(int a,b,c,d,e){
        sx=a;
        sy=b;
        ex=c;
        ey=d;
        cost=e;
    }
};

int sx,sy,dx,dy;

int calcdist(int i,wormhole w[],int a,int b){
    if(i==-1){
        int x=sx-dx;
        int y=sy-dy;
        return abs(x)+abs(y);
    }

    int x=abs(a-w[i].sx);
    int y=abs(b-w[i].sy);

    return x+y+w[i].cost;

}

void dfs(wormhole w[],int n,int i,int dist,bool vis[],int cnt,int a,int b){

dist+=calcdist(i,w,a,b);

if(i!=-1)
    vis[i]=true;

if(cnt==n){
    return;
}

for(int j=0;j<n;j++){
    if(!vis[j]){
        dfs(w,n,j,dist,vis,cnt+1,);
    }
}
vis[i]=false;

}


int main(){

int n;
cin>>n;

wormhole w[n];
bool vis[n]={false};

cin>>sx>>sy>>dx>>dy;

for(int i=0;i<n;i++){
    cin>>w[i].sx>>w[i].sy>>w[i].ex>>w[i].ey>>w[i].cost;
}

dfs(w,n,0);

cout<<cost;

return 0;
}
