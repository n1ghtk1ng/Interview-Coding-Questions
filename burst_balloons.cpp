#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
        vector<vector<int> >dp(1+nums.size(),vector<int>(1+nums.size(),0));

        int n=nums.size();

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                /*if(i==j){
                    int temp1=((i+1)>=n?1:nums[i+1]);
                    int temp2=((i-1)<0?1:nums[i-1]);
                    dp[i][j]=max(dp[i][j],temp1*temp2*nums[i]);
                    continue;
                }*/

                for(int k=i;k<=j;k++){
                    int num1,num2;
                        num1=((i-1)<0?1:nums[i-1]);
                        num2=((j+1)>=n?1:nums[j+1]);
                    if(k==i){
                        dp[i][j]=max(dp[i][j],dp[i+1][j]+num1*num2);
                    }
                    else if(k==j){
                        dp[i][j]=max(dp[i][j],dp[i][j-1]+num1*num2);
                    }
                    else{
                        dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+num1*num2);
                    }

                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][n-1];
    }


int main(){

vector<int>x={1,2,3,4};
cout<<maxCoins(x);

return 0;
}
