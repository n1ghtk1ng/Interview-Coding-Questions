#include<bits/stdc++.h>
using namespace std;

template<class T>

class node{
public:
    T data;
    node<T>*next;

    node(T d){
        data=d;
        next=NULL;
    }

};
template<typename T>
class Queue{

private:
    node<T>*head;
    node<T>*tail;

public:
    Queue(){
        head=tail=NULL;
    }
    void push(T d){
        if(head==NULL){
            head=tail=new node<T>(d);
        }
        else{
            node<T>*temp=new node<T>(d);
            tail->next=temp;
            tail=temp;
        }
    }
    void pop(){
        if(head!=NULL){
            node<T>*temp=head;
            head=head->next;
            delete temp;
            temp=NULL;
        }
    }
    T front(){
        return head->data;
    }
    bool empty(){
        if(head==NULL)
            return true;
        return false;
    }


};

bool isBipartite(int arr[4][4],int node){

int color[4]={0};
color[node]=1;
Queue<int>q;

q.push(node);

while(!q.empty()){
    int n=q.front();
//    cout<<"n = "<<n<<endl;
    q.pop();

    for(int i=0;i<4;i++){
        if(i!=n && arr[n][i]==1){
            if(color[i]==0){
                color[i]=-color[n];
                q.push(i);
            }
            else if(color[i]==color[n]){
//                    cout<<"i = "<<i<<" n = "<<n<<endl;
                    return false;
            }
        }
    }
}
return true;

}

int main()
{
//    int **G=int**(malloc(4*sizeof(int*)));
//
//    for(int i=0;i<4;i++){
//        G[i]=int*(malloc(4*sizeof(int)));
//    }
//    for(int i=0;i<4;i++){
//        for(int j=0;j<4;j++){
//            cin>>G[i][j];
//        }
//    }
    int arr[4][4]={{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(arr,0)?cout<<"Yes":cout<<"No";
    return 0;
}
