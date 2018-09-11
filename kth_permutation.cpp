#include<bits/stdc++.h>
using namespace std;

string fun2(int a){
string ans="";
for(int i=a;i>0;i/=10){
    ans+=char(48+i%10);
}
reverse(ans.begin(),ans.end());
return ans;
}

void fun3(bool*vis,int n){
for(int i=0;i<=n;i++){
    vis[i]=false;
}
}

string fun(int n,int k,int left,vector<int>&p,bool *vis){
    if(k==0){
        string temp="";
        for(int i=n;i>=1;i--){
            if(!vis[i]){
                temp+=fun2(i);
            }
        }
        return temp;
    }
    int sum=0;
    string ans="";
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sum+=p[left-1];
            cnt++;
            if(sum>=k){
                ans+=fun2(i);
                vis[i]=true;
                int temp=(sum!=k)?(sum-p[left-1]):cnt*p[left-1];
                ans+=fun(n,k-temp,left-1,p,vis);
                return ans;
            }
        }
    }
}

int main(){

int A=4,B=7;

vector<int>permute(A+1,1);
    bool *vis=new bool[A+1];
    for(int i=1;i<=A;i++){
        permute[i]=i*permute[i-1];
        vis[i]=false;
    }

    for(int i=1;i<=permute[A];i++){
        cout<<fun(A,i,A,permute,vis)<<endl;
        fun3(vis,A);
    }


return 0;
}
