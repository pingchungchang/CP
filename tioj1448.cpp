#include <bits/stdc++.h>
using namespace std;

const int mxn = 5e5+10;
int dsu[mxn];
int
bool flag = false;
int ans = 0;
int root(int d[],int k){
    return k == d[k]?k:d[k] = root(d[k]);
}
void onion(int a,int b){
    int ra = root(a),rb = root(b);
    dsu[ra] = rb;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)dsu[i] = i;
    while(m--){
        int t,a,b;
        cin>>t>>a>>b;
        if(a>n||b>n||a<=0||b<=0){
            ans++;
            continue;
        }
    }

}
