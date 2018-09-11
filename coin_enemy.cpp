#include<bits/stdc++.h>
using namespace std;

bool bomb_used=false;
int n;
char** usebomb(int idx,char**w,char**newW){

newW=new char*[n+1];

for(int i=0;i<=n;i++){
    newW[i]=new char[5];
}
for(int i=0;i<n;i++){
    for(int j=0;j<5;j++){
        newW[i][j]=w[i][j];
    }
}

for(int i=idx;i>=0 && i>=idx-4;i--){
    for(int j=0;j<5;j++){
        if(w[i][j]=='2')
            w[i][j]='0';
    }
}
return newW;
}

int dfs(int i,int spaceship_index,char**w){
int coins=0;

/// 6 cases

if(i-1>=0){


    // case 1,2,3 don`t use bomb
    if(w[i-1][spaceship_index]!='2'){
        coins= max(coins,(w[i-1][spaceship_index]-48)+dfs(i-1,spaceship_index,w));
    }
    if(spaceship_index+1<5 && w[i-1][spaceship_index+1]!='2'){
        coins= max(coins,(w[i-1][spaceship_index+1]-48)+dfs(i-1,spaceship_index+1,w));
    }
    if(spaceship_index-1>=0 && w[i-1][spaceship_index-1]!='2'){
        coins= max(coins,(w[i-1][spaceship_index-1]-48)+dfs(i-1,spaceship_index-1,w));
    }
    //case 4,5,6 use bomb
    char **newW=NULL;
    if(!bomb_used){
        newW=usebomb(i-1,w,newW);
        bomb_used=true;
    }
    if(w[i-1][spaceship_index]!='2'){
        coins= max(coins,(w[i-1][spaceship_index]-48)+dfs(i-1,spaceship_index,w));
    }
    if(spaceship_index+1<5 && w[i-1][spaceship_index+1]!='2'){
        coins= max(coins,(w[i-1][spaceship_index+1]-48)+dfs(i-1,spaceship_index+1,w));
    }
    if(spaceship_index-1>=0 && w[i-1][spaceship_index-1]!='2'){
        coins= max(coins,(w[i-1][spaceship_index-1]-48)+dfs(i-1,spaceship_index-1,w));
    }
    if(newW!=NULL){
        bomb_used=false;
        w=newW;
    }

}
return coins;
}

int main(){


cin>>n; // excluding last row of spaceship

char **w=new char*[n+1];

for(int i=0;i<n;i++){
    w[i]=new char[5];
}
for(int i=0;i<n;i++){
    for(int j=0;j<5;j++){
        cin>>w[i][j];
    }
}

cout<<dfs(n,2,w);

/*
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
*/

/*
0 0 2 2 1
0 0 2 1 0
0 0 2 2 2
0 0 2 2 2
0 0 1 0 0
*/
return 0;
}
