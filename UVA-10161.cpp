#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0)return 0;
        int x = sqrt(n);
        pair<int,int> ans = make_pair(0,0);
        if(2*n>=(x*x+1)+(x+1)*(x+1)){
            x++;
            if(x%2==1){
                ans.second= x;
                ans.first = x*x-n+1;
            }
            else{
                ans.first =  x;
                ans.second = x*x-n+1;
            }
        }
        else if(x*x==n){
            if(x%2==1){
                ans.first = 1;
                ans.second = x;
            }
            else{
                ans.first = x;
                ans.second = 1;
            }
        }
        else{
            if(x%2==1){
                ans.second = x+1;
                ans.first = n-x*x;
            }
            else{
                ans.first = x+1;
                ans.second = n-x*x;
            }
        }
        cout<<ans.first<<' '<<ans.second<<endl;
    }
}