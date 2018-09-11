#include<bits/stdc++.h>
using namespace std;

struct Pair{
int first;
int second;
};

Pair c[10000];
void merge(int f,int mid,int l,Pair arr[]){

int i=f,j=mid,k=f;

while(i<mid && j<=l){
    if(arr[i].first<arr[j].first){
        c[k++]=arr[i++];
    }
    else if(arr[i].first==arr[j].first){
        if(arr[i].second<arr[j].second){
            c[k++]=arr[i++];
        }
        else if(arr[i].second>=arr[j].second){
            c[k++]=arr[j++];
        }
    }
    else{
        c[k++]=arr[j++];
    }
}
while(i<mid){
    c[k++]=arr[i++];
}
while(j<=l){
    c[k++]=arr[j++];
}

for(int q=f;q<=l;q++){
    arr[q]=c[q];
}

}

void mergesort(int f,int l,Pair arr[],int n){

if(f>=l){
    return;
}
int mid=(f+l)/2;
mergesort(f,mid,arr,n);
mergesort(mid+1,l,arr,n);
merge(f,mid+1,l,arr);

}

int main(){

int n;
cin>>n;

Pair arr[n+1];

for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
}
cout<<endl;
mergesort(0,n-1,arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i].first<<" "<<arr[i].second<<endl;
}

return 0;
}
