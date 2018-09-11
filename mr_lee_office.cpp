#include<bits/stdc++.h>
using namespace std;

int dfs(int **arr,bool *vis,int cnt,int n,int i){
if(cnt==n-1){
    if(arr[i][0]!=0){
        return arr[i][0];
    }
    return INT_MAX;
}
vis[i]=true;
int dist=INT_MAX;
for(int j=1;j<n;j++){
    if(!vis[j] && arr[i][j]!=0){
        int qw=dfs(arr,vis,cnt+1,n,j);
        if(qw!=INT_MAX){
            dist=min(dist,qw+arr[i][j]);
        }
    }
}
vis[i]=false;
return dist;
}

int main(){

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;

    int **arr=new int*[n+1];
    bool *vis=new bool[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=new int[n+1];
        vis[i]=false;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    if(n==1){
        cout<<0<<endl;
        continue;
    }
    int t=dfs(arr,vis,0,n,0);
    if(t==INT_MAX){
        cout<<"not possible"<<endl;
    }
    else{
        cout<<t<<endl;
    }
}

return 0;
}
