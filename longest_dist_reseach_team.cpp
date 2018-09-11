#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int dist[],int **arr,int n,int cost,bool vis[]){

dist[node]=cost;
vis[node]=true;
for(int i=1;i<=n;i++){
    if(i!=node && arr[node][i]!=0 && dist[i]<dist[node]+arr[i][node] && !vis[i]){
        dist[i]=dist[node]+arr[i][node];
        dfs(i,dist,arr,n,dist[i],vis);
    }
}


}

int main(){

int n;
cin>>n;

int **arr=new int*[n+1];
for(int i=0;i<=n;i++){
    arr[i]=new int[n+1];
}

for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        arr[i][j]=0;
    }
}

int edges;
cin>>edges;

for(int i=0;i<edges;i++){
    int a,b,c;
    cin>>a>>b>>c;

    arr[a][b]=c;
    arr[b][a]=c;
}
int src;
cin>>src;

int dist[n+1]={0};
bool vis[n+1]={false};
for(int i=1;i<=n;i++){
    dist[i]=INT_MIN;
}
dist[src]=0;

dfs(src,dist,arr,n,0,vis);

int ans=INT_MAX;
for(int i=1;i<=n;i++){
    cout<<dist[i]<<" ";
    if(i!=src)
    ans=min(ans,dist[i]);
}
cout<<endl;
cout<<ans;

/*
6
5
1 2 3
2 3 4
2 6 2
4 6 6
5 6 5
*/
return 0;
}
