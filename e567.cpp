#include <bits/stdc++.h>
using namespace std;


int now;

void f(string s){
    if(s == "RIGHT")now++;
    else now--;
    return;
}
void solve(){
    int n;
    cin>>n;
    now =0;
    vector<string> v(n+1,"");
    for(int i = 1;i<=n;i++){
        string in;
        cin>>in;
        if(in == "SAME"){
            cin>>in;
            int k;
            cin>>k;
            v[i] = v[k];
            f(v[k]);
        }
        else{
            v[i] = in;
            f(in);
        }
    }
    cout<<now<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
