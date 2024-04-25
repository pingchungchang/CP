#include <bits/stdc++.h>
using namespace std;

struct node{
    node* l;
    node* r;
    int val;
    node(){
        l = nullptr;
        r = nullptr;
        val = 0;
    }
    node(int k){
        val = k;
        l = nullptr;
        r = nullptr;
    }
};
void solve(int n,int k){
    node* rt = new node(1);
    node* tmp = rt;
    for(int i = 2;i<=n;i++){
        node* now = new node(i);
        now->l = tmp;
        tmp->r = now;
        tmp = now;
    }
    tmp->r = rt;
    rt->l = tmp;
    rt = rt->l;
    int np = n;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<(k-1)%np;j++){
            rt = rt->r;
        }
        node* tmp = rt;
        for(int j = 0;j<(k)%(np-1);j++){
            tmp = tmp ->r;
        }
        tmp->l->r = tmp->r;
        tmp->r->l = tmp->l;
        rt->val = tmp->val;
        rt = rt->r;
        np--;
    }
    //cout<<rt->val;
    cout<<n-(rt->val-1)<<'\n';
}
int main(){
    int n,k;
    while(cin>>n>>k){
        solve(n,k);
    }
}
