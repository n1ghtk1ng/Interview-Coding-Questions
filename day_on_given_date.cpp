#include<bits/stdc++.h>
using namespace std;

int main(){

int d,m,y;
cin>>d>>m>>y;
// Tomohiko Sakamoto's Algorithm work?

int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
//y -= m < 3;
if(m<3){
    y-=1;
}
cout<<(y + y/4 - y/100 + y/400 + t[m-1] + d ) % 7;
//0 sunday
//1 monday

return 0;
}
