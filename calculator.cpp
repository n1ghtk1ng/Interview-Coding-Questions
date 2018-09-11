#include<bits/stdc++.h>
/*
You are given an old touch smartphone numbers having dial pad and calculator app. The goal is to type a number on dialpad.
Calculator have 1-9 and +, -, * , /, = as operations. But phone is old, some of the numbers and some operations can't be touched.
But you can always make a number using other numbers and operations. There could be multiple ways of making a number.
You have to find minimum operation for making a number.
For ex: lets say 1,4,6,7,8,9 works and +,-,* works. 2,3,5 and / doesn't work.
If you have to type 18-> 2 operations. (Each touch is considered an operation).
If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
The goal is to find minimum operations.*/
using namespace std;
int n,m,o;
int * working,*operations;
int answer=INT_MAX;

int getValue(int prev,int curr,int op){
	if(prev==-10000000){
		return curr;
	}//mtlb prev kuch nhi hai toh curr hi hai jo h

	if(op==1){
		return prev+curr;
	}
	if(op==2){
		return prev-curr;
	}
	if(op==3){
		return prev*curr;
	}
	if(op==4){
		if(curr==0){
			return -1;
		}else{
			return prev/curr;
		}
	}
}
bool isDone(int prev,int curr,int Operation,int target){
	if(Operation==4 && curr==0){
		return false;
	}

	if(getValue(prev,curr,Operation)==target)
		return 1;
	return false;
}

void findMinTouch(int prev,int curr,int Operation,int touchesDone,int target){//operation ka mtlb jo operation ab hona hai prev and current p
	if(Operation!=-1 && curr!=-10000000){
		bool ans=isDone(prev,curr,Operation,target);//-1 ka mtlb nhi hua
		if(ans && touchesDone<o){
//			cout<<prev<<" "<<curr<<" "<<touchesDone+1<<endl;
			answer=min(answer,touchesDone+1);//1 equal k liye
		}
	}
	if(Operation!=-1 && curr==-10000000 && prev==target && touchesDone<o){
//		cout<<prev<<" "<<curr<<" "<<touchesDone<<endl;
		answer=min(answer,touchesDone);//1 add nhi hoga isme kyuki curr -10000000 hai mtlb koi operand dbaya hai to soch le = dbaya hai
	}
	if(Operation==-1 && curr==target && touchesDone<o){
//		cout<<prev<<" "<<curr<<" "<<touchesDone<<endl;
		answer=min(answer,touchesDone);
	}

	if(touchesDone>=o){
		return;
	}

	for(int i=0;i<m;i++){
		if(curr==-10000000)
			break;//isse phle hi koi operation wala button dba hai ab nhi dbaunga
		if(operations[i]==4 && curr==0){
			continue;
		}
		int value=getValue(prev,curr,Operation);
		findMinTouch(value,-10000000,operations[i],touchesDone+1,target);//mtlb current p abhi kuch nhi hai
	}//yha to hai ki mai operation perform krne k mn me hu

	for(int i=0;i<n;i++){
		if(curr==-10000000){
			findMinTouch(prev,working[i],Operation,touchesDone+1,target);
		}
		else{
			int val=abs(curr);
			val=val*10+working[i];
			if(curr<0){
				val*=-1;
			}
			findMinTouch(prev,val,Operation,touchesDone+1,target);
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		answer=INT_MAX;
		cin>>n>>m>>o;
		working=new int[n];
		for(int i=0;i<n;i++){
			cin>>working[i];
		}
		operations=new int[m+1];
		for(int i=0;i<m;i++){
			cin>>operations[i];
		}

		int target;
		cin>>target;

		findMinTouch(-10000000,-10000000,-1,0,target);//curr me abhi kuch na h mtlb -10000000
		cout<<answer<<endl;
	}
	return 0;
}
