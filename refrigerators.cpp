#include<bits/stdc++.h>
using namespace std;

int dfs(int sx,int sy,int ex,int ey,int start[],int end[],bool vis[],int cnt,int i,int n){
if(cnt==n){
    return abs(sx-ex)+abs(sy-ey);
}

int dist=INT_MAX;
//vis[i]=true;
for(int j=1;j<=n;j++){
    if(!vis[j]){
        vis[j]=true;
        dist=min(dist,abs(sx-start[j])+abs(sy-end[j])+  dfs(start[j],end[j],ex,ey,start,end,vis,cnt+1,j,n));
        vis[j]=false;
    }
}
//vis[i]=false;

return dist;
}

int main(){

int t;
cin>>t;

while(t--){

int n;
cin>>n;

int start[n+1];
int end[n+1];
int sx,sy,ex,ey;

cin>>sx>>sy>>ex>>ey;

for(int i=1;i<=n;i++){
    cin>>start[i]>>end[i];
}

bool visited[n+2]={false};
cout<<dfs(sx,sy,ex,ey,start,end,visited,0,0,n)<<endl;

}


return 0;
}
