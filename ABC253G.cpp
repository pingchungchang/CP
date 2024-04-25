#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
struct node{
    int pl,pr,val,pri;
    int sz;
    node(){}
};
const int mxn = 2e5+10;
node treap[mxn];
void pull(int now){
    if(!now)return;
    treap[now].sz = 1+treap[treap[now].pl].sz+treap[treap[now].pr].sz;
}
int merge(int a,int b){
    if(!a)return b;
    if(!b)return a;
    if(treap[a].pri<treap[b].pri){
        treap[b].pl = merge(a,treap[b].pl);
        pull(b);
        return b;
    }
    else{
        treap[a].pr = merge(treap[a].pr,b);
        pull(a);
        return a;
    }
}
void split(int now,int &a,int &b,int tar){
    if(!now){
        a = b = 0;
        return;
    }
    if(treap[treap[now].pl].sz+1<=tar){
        a = now;
        split(treap[now].pr,treap[a].pr,b,tar-treap[treap[now].pl].sz-1);
    }
    else{
        b = now;
        split(treap[now].pl,a,treap[b].pl,tar);
    }
    pull(a);
    pull(b);
    return;
}

int arr[mxn];
int pt = 1;

void dfs(int now){
    if(!now)return;
    dfs(treap[now].pl);
    arr[pt++] = treap[now].val;
    dfs(treap[now].pr);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)arr[i] = i;
    ll l,r;
    cin>>l>>r;
    ll total = 0,now = 1;
    for(int i = n-1;i>=1;i--){
        if(total+i<l){
            total += i;
            now++;
        }
        else break;
    }
    pll lb = {now,l-total+now};
    total = 0,now = 1;
    for(int i = n-1;i>=1;i--){
        if(total+i<r){
            total += i;
            now++;
        }
        else break;
    }
    pll rb = {now,r-total+now};
    // cout<<lb.fs<<' '<<lb.sc<<endl<<rb.fs<<' '<<rb.sc<<endl;
    if(rb.fs==lb.fs){
        for(int i = lb.sc;i<=rb.sc;i++){
            swap(arr[lb.fs],arr[i]);
        }
    }
    else if(rb.fs == lb.fs+1){
        for(int i = lb.sc;i<=n;i++){
            swap(arr[lb.fs],arr[i]);
        }
        for(int i = rb.fs+1;i<=rb.sc;i++){
            swap(arr[rb.fs],arr[i]);
        }
    }
    else{
        for(int i = lb.sc;i<=n;i++){
            swap(arr[lb.fs],arr[i]);
        }
        // for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;return 0;
        int root = 1;
        for(int i = 1;i<=n;i++){
            treap[i].pl = treap[i].pr = 0;
            treap[i].sz = 1;
            treap[i].pri = rand();
            treap[i].val = arr[i];
            if(i != 1)root = merge(root,i);
        }
        for(int i = lb.fs+1;i<rb.fs;i++){
            int ta,tb,tc,td;
            split(root,ta,tb,n-1);
            split(ta,tc,td,i-1);
            root = merge(tb,td);
            root = merge(tc,root);
        }
        pt = 1;
        dfs(root);
        for(int i = rb.fs+1;i<=rb.sc;i++){
            swap(arr[i],arr[rb.fs]);
        }
    }
    for(int i =1;i<=n;i++)cout<<arr[i]<<' ';
}