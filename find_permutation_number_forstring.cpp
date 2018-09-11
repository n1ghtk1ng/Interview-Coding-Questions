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

int factorial(int n){
    int temp=1;

    for(int i=1;i<=n;i++){
        temp*=i;
    }
    return temp;
}

int pnumber(string s,vector<int>&v,int j){

if(v.size()==0)
    return 0;
int ans=0;
int x=factorial(v.size()-1);
for(int i=0;i<v.size();i++){
    if(v[i]==(s[j]-48)){
//        cout<<"i = "<<i<<endl;
        ans=x*i;
        v.erase(v.begin()+i);
        return ans+pnumber(s,v,j+1);
    }
}

}

int main(){

string s="4321";
vector<int>v;

for(int i=0;i<s.size();i++){
    v.push_back(i+1);
}
cout<<pnumber(s,v,0)+1;

return 0;
}
