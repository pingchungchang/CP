#include <bits/stdc++.h>
using namespace std;

string s;
int v[10];
int n;
bool flag;
void f(){
    string ss = to_string(stoi(s)*n);
    vector<char> all;
    for(auto i:s)all.push_back(i);
    for(auto i:ss)all.push_back(i);
    sort(all.begin(),all.end());
    if(all.size() != 10)return;
    for(int i = 0;i<10;i++){
        if(all[i]-'0'!= i)return;
    }
    flag = true;
    cout<<ss<<" / "<<s<<" = "<<n<<'\n';
    return;
}
void dfs(){
    if(s.size() == 5){
        f();
        return;
    }
    for(int i = 0;i<10;i++){
        if(v[i] == 0){
            v[i] = 1;
            s += (char)('0'+i);
            dfs();
            s.pop_back();
            v[i] = 0;
        }
    }
    return;
}
void solve(){
    flag = false;
    s = "";
    memset(v,0,sizeof(v));
    dfs();
    if(flag == false)cout<<"There are no solutions for "<<n<<'\n';
    cout<<'\n';
    return;
}

int main(){
    while(cin>>n)solve();
}
