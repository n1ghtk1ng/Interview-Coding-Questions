#include<bits/stdc++.h>
using namespace std;

int n,m,o;
int *working;
bool *operations;
int target;

int operate(){

int a=dfs();
int b=dfs();

if(operations[1]){
    return a+b;
}
if(operations[2]){
    return a-b;
}
if(operations[3]){
    return a*b;
}
if(operations[4]){
    if(b!=0)
    return a/b;
}

}

int dfs(int num,int st){
if(st>o){
    return;
}
if(num==target){
    return;
}

for(int i=0;i<n;i++){
    if(num==-1){
        num=working[i];
    }
    else{
        num=num*10+working[i];
    }
    dfs(num);
}


}

int fun(){

int num1=dfs();
int num2=dfs();
//check if num1 or num2 are the required elemets
//apply operator and check value
// return the value

}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>o;
		working=new int[n];
		for(int i=0;i<n;i++){
			cin>>working[i];
		}
		operations=new bool[5];
		for(int i=0;i<m;i++){
			operations[i]=true;
		}
		cin>>target;

		cout<<dfs(-1,-1,-1);

	}
	return 0;
}
