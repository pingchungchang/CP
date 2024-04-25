#include <bits/stdc++.h>
using namespace std;


int n,a,b;
string s;
void solve(){
    cin>>n>>a>>b;
    int k = (a)/(b+1);
    int m = a-k*(b+1);
    s = "";
    for(int i = 0;i<m;i++){
        for(int j = 0;j<k+1;j++){
            s += 'R';
        }
        s += 'B';
    }
    int total = 0;
    while(s.size() != n){
        if(total == k){
            total = 0;
            s += 'B';
        }
        else{
            total++;
            s += 'R';
        }
    }
    cout<<s<<'\n';
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
