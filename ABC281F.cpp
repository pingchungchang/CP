#include <bits/stdc++.h>
using namespace std;

struct node{
    node *pl,*pr;
    node(){
        pl = pr = 0;
    }
};
node* trie = new node();
void addnum(int n){
    auto now = trie;
    for(int i = 30;i>=0;i--){
        if((1<<i)&n){
            if(!now->pr)now->pr = new node();
            now = now->pr;
        }
        else{
            if(!now->pl)now->pl = new node();
            now = now->pl;
        }
    }
    return;
}
int ans = 1<<30;
void dfs(node* now,int pre,int val,int dep){
    if(dep == -1){
        ans = min(ans,pre^val);
        return;
    }
    if(!now){
        cout<<pre<<' '<<dep;
        cout<<"ERROR\n";
        return;
    }
    if(!now->pl){
        dfs(now->pr,(pre|1<<dep),(val|1<<dep),dep-1);
    }
    else if(!now->pr){
        dfs(now->pl,pre,val,dep-1);
    }
    else{
        dfs(now->pl,pre,val|(1<<dep),dep-1);
        dfs(now->pr,pre|(1<<dep),val,dep-1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        addnum(k);
    }
    // cout<<"HI"<<endl;
    dfs(trie,0,0,30);
    cout<<ans;
    return 0;
}