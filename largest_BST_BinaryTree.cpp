#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
int a,b,c,d;
    Pair(int d){
        a=d;
        b=d;
        c=0;
        this->d=0;
    }
};
struct node
{
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};

Pair largestBST(node* root){
Pair p(root->data);

Pair p1(root->data);
Pair p2(root->data);

if(root->left)
    p1=largestBST(root->left);
if(root->right)
    p2=largestBST(root->right);

if(root->data>=p1.b && root->data<=p2.a){
    p.a=p1.a;
    p.b=p1.b;
    p.c=p1.c+p2.c+1;  // c variable contains including bst length of left and right
    p.d=max(p.c,max(p1.d,p2.d));
    return p;
}
else if(root->data>=p1.b){
    p.a=p1.a;
    p.b=root->data;
    p.c=p1.c+1;
    p.d=max(p.c,max(p1.d,p2.d));
    return p;
}
else if(root->data<=p2.a){
    p.a=root->data;
    p.b=p2.b;
    p.c=p2.c+1;
    p.d=max(p.c,max(p1.d,p2.d));
    return p;
}
else{
    p.a=root->data;
    p.b=root->data;
    p.c=1;
    p.d=max(p.c,max(p1.d,p2.d));
    return p;
}

}

int main(){

  node *root = new node(50);
  root->left = new node(10);
  root->right = new node(60);
  root->left->left = new node(5);
  root->left->right = new node(20);
  root->right->left = new node(55);
  root->right->left->left = new node(45);
  root->right->right = new node(70);
  root->right->right->left = new node(65);
  root->right->right->right = new node(80);

Pair p=largestBST(root);
cout<<p.a<<endl;
cout<<p.b<<endl;
cout<<p.c<<endl;
cout<<p.d<<endl;


return 0;
}
