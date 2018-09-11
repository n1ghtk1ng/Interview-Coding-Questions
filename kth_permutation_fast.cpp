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

string getPermutation(int k, vector<int> &candidateSet) {
    int n = candidateSet.size();
    if (n == 0) {
        return "";
    }
    if (k > factorial(n)) return ""; // invalid. Should never reach here.

    int f = factorial(n - 1);
    int pos = k / f;
    k %= f;

    string ch = fun2(candidateSet[pos]);
    // now remove the character ch from candidateSet.
    candidateSet.erase(candidateSet.begin() + pos);
    return ch + getPermutation(k, candidateSet);
}

string getPermutation(int n, int k) {
    vector<int> candidateSet;
    for(int i = 1; i <= n; i++) candidateSet.push_back(i);
        return getPermutation(k - 1, candidateSet);
}

int pnumber(string s,vector<int>&v,int j){

if(v.size()==0)
    return 0;
int ans=0;
int x=factorial(v.size()-1);
for(int i=0;i<v.size();i++){
    if(v[i]==(s[j]-48)){
       // cout<<"i = "<<i<<endl;
        ans=x*i;
        v.erase(v.begin()+i);
        return ans+pnumber(s,v,j+1);
    }
}

}

vector<int>fun(string s){

vector<int>v;

for(int i=0;i<s.size();i++){
    v.push_back(i+1);
}
return v;
}

int main(){

for(int i=1;i<=24;i++){
    string x=getPermutation(4,i);
    vector<int>v=fun(x);
    int pno=pnumber(x,v,0)+1;

    cout<<pno<<" "<<x<<endl;

}


return 0;
}
