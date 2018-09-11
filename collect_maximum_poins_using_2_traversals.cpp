#include<bits/stdc++.h>
using namespace std;

#define R 5
#define C 4

bool isSafe(int y){
    if(y>=0 && y<C)
        return true;
    return false;
}
int dfs(int arr[][C],int row,int y1,int y2){


if(row==R-1 && y1==0 && y2==C-1)
    return (y1 == y2)? arr[row][y1]: arr[row][y1] + arr[row][y2];;
if(row==R-1)
    return INT_MIN;

int coins=(y1!=y2)?(arr[row][y1]+arr[row][y2]):(arr[row][y1]);
int a=INT_MIN,b=INT_MIN,c=INT_MIN,d=INT_MIN,e=INT_MIN,f=INT_MIN,g=INT_MIN,h=INT_MIN,i=INT_MIN;
if(isSafe(y1-1) && isSafe(y2-1)){
    a=dfs(arr,row+1,y1-1,y2-1);
}
if(isSafe(y1-1) && isSafe(y2)){
    b=dfs(arr,row+1,y1-1,y2);
}
if(isSafe(y1-1) && isSafe(y2+1)){
    c=dfs(arr,row+1,y1-1,y2+1);
}

if(isSafe(y1) && isSafe(y2-1)){
    d=dfs(arr,row+1,y1,y2-1);
}
if(isSafe(y1) && isSafe(y2)){
    e=dfs(arr,row+1,y1,y2);
}
if(isSafe(y1) && isSafe(y2+1)){
    f=dfs(arr,row+1,y1,y2+1);
}

if(isSafe(y1+1) && isSafe(y2-1)){
    g=dfs(arr,row+1,y1+1,y2-1);
}
if(isSafe(y1+1) && isSafe(y2)){
    h=dfs(arr,row+1,y1+1,y2);
}
if(isSafe(y1+1) && isSafe(y2+1)){
    i=dfs(arr,row+1,y1+1,y2+1);
}

int temp= max(i,max(h,max(g,max(f,max(e,max(d,max(c,max(a,b))))))));
//cout<<"row = "<<row<<" coins = "<<temp<<endl;
if(temp==INT_MIN)
return INT_MIN;


return temp+coins;
}

int main(){

int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };

cout<<dfs(arr,0,0,3);

return 0;
}
