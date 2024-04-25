#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    int o = 1;
    while(cin>>a>>b){
        if(a == 0&&b==0) return 0;
        if(a == 0||b== 0){
            cout<<"0";
            continue;
        }
        cout<<"Twin Towers #"<<o<<"\n";
        vector<int> t1(a,0);
        vector<int> t2(b,0);
        for(int i =0;i<a;i++){
            int k;
            cin>>k;
            t1[a-i-1]=k;
        }
        for(int i =0;i<b;i++){
            int k;
            cin>>k;
            t2[b-i-1] = k;
        }
        vector<vector<int>> dp(a,vector<int>(b,0));
        for(int i =0;i<b;i++){
            if(t1[0] == t2[i]) dp[0][i] = 1;
            if(i!=0&&dp[0][i-1] == 1)dp[0][i] = 1;
        }
        for(int i = 0;i<a;i++){
            if(t1[i] == t2[0]) dp[i][0] = 1;
            if(i !=0&&dp[i-1][0] == 1)dp[i][0] = 1;
        }
        for(int i = 1;i<a;i++){
            for(int j =1;j<b;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(t1[i] == t2[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            }
        }
        o++;
        cout<<"Number of Tiles : "<<dp[dp.size()-1][dp[0].size()-1]<<"\n\n";
    }
}
