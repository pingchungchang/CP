#include <bits/stdc++.h>
using namespace std;

int f(int a){
    string s = to_string(a);
    string ans = "";
    for(auto i:s){
        if(i == '4'||i == '7')ans += i;
    }
    if(ans.size() == 0)return 0;
    else return stoi(ans);
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i = a+1;i<=1e6;i++){
        //cout<<a<<endl;
        if(f(i) == b){
            cout<<i<<'\n';
            return 0;
        }
    }
}
