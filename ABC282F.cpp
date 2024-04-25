#include <bits/stdc++.h>
using namespace std;

struct node{
    int id,l,r;
    node(int ii,int lll,int rr){
        id = ii;
        l = lll,r = rr;
    }
    node(){
        id = 0;
    }
    bool operator<(node &b)const{
        return id<b.id;
    }
};
const int mxn = 4040;
node stable[4040][20];

int high(int k){
    int cnt = 0;
    k>>=1;
    while(k){
        cnt++;
        k>>=1;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<node> v;
    for(auto &i:stable){
        for(auto &j:i)j = node();
    }
    int idx = 0;
    int tt = 0;
    for(int i = 1;i<=n;i<<=1){
        for(int j = 1;j+i-1<=n;j++){
            stable[j][tt] = node(++idx,j,j+i-1);
            v.push_back(stable[j][tt]);
        }
        tt++;
    }
    cout<<v.size()<<endl;
    for(auto &i:v){
        cout<<i.l<<' '<<i.r<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int len = b-a+1;
        int k = high(len);
        cout<<stable[a][k].id<<' '<<stable[b-(1<<k)+1][k].id<<endl;
    }
    return 0;
}