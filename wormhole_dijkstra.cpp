#include<iostream>
using namespace std;

#define V 9

class Pair{
public:
    int first;
    int second;

    Pair(){}

    Pair(int a,int b){
        this->first=a;
        this->second=b;
    }
    void print(){
        cout<<first<<" "<<second<<endl;
    }

};

class pq{

private:
    Pair *arr;
    int i;
    int current_size;

    void heapify(int idx){
        int min_i=idx;
        if(2*idx<i && arr[idx].first>arr[2*idx].first){
            min_i=2*idx;
        }
        if(2*idx+1<i && arr[idx].first>arr[2*idx+1].first){
            min_i=2*idx+1;
        }
        if(min_i!=idx){
            swap(arr[idx],arr[min_i]);
            heapify(min_i);
        }
    }
public:

    pq(){
        i=1;
        arr=new Pair[100000];
        current_size=0;
    }

    void push(Pair d){
        arr[i]=d;
        i++;
        current_size++;

        int j=i-1;

        while(j>1 && arr[j].first<arr[j/2].first){
            swap(arr[j],arr[j/2]);
            j=j/2;
        }
    }
    void pop(){
        if(current_size>0){
            swap(arr[1],arr[i-1]);
            current_size--;
            i--;
            heapify(1);
        }
    }
    Pair top(){
        if(current_size!=0){
            return arr[1];
        }
    }
    bool empty(){
        if(current_size==0)
            return true;
        return false;
    }

};

void dijkstra(int arr[][V],int src){

int dist[V];
int parent[V];

for(int i=0;i<V;i++){
    dist[i]=INT_MAX;
    parent[i]=-1;
}
dist[src]=0;

pq q;
Pair p(0,src);
q.push(p);

while(!q.empty()){
    Pair t=q.top();
    q.pop();

    int node=t.second;
    int cost=t.first;

    if(dist[node]<cost){
        continue;
    }

    for(int i=0;i<V;i++){
        if(arr[node][i]!=0 && dist[i]>dist[node]+arr[node][i]){
            dist[i]=dist[node]+arr[node][i];
            parent[i]=node;
            Pair qwe(dist[i],i);
            q.push(qwe);
        }
    }
}

for(int i=0;i<V;i++){
    cout<<dist[i]<<" -- "<<parent[i]<<endl;
}

}

void prims(int arr[][V],int src){
    int dist[V+1];
    int parent[V+1];

    for(int i=0;i<=V;i++){
        dist[i]=INT_MAX;
        parent[i]=-1;
    }
    dist[src]=0;

    pq q;
    Pair p(0,src);
    q.push(p);

    while(!q.empty()){
        Pair t=q.top();
        q.pop();

        int node=t.second;
        int cost=t.first;

        if(dist[node]<cost)
            continue;

        for(int i=0;i<V;i++){
            if(arr[node][i]!=0 && dist[i]>arr[node][i]){
                dist[i]=arr[node][i];
                parent[i]=node;
                Pair qwe(dist[i],i);
                q.push(qwe);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(parent[i]!=-1){
            cout<<i<<" -- "<<parent[i]<<endl;
        }
    }

}


int main(){
/*
Pair p1(5,1);
Pair p2(4,1);
Pair p3(100,1);
Pair p4(2,1);
Pair p5(1,1);

pq a;

a.push(p1);
a.push(p2);
a.push(p3);
a.push(p4);
a.push(p5);

while(!a.empty()){
    a.top().print();
    a.pop();
}*/
/*
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

                    dijkstra(graph,0);*/
                  int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
                     prims(graph,0);

return 0;
}
