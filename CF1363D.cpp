#include <bits/stdc++.h>
using namespace std;


int ask(int s,int e){
    cout<<"? ";
    cout<<e-s+1<<' ';
    for(int i = s;i<=e;i++)cout<<i<<' ';
    cout<<endl;
    int out;
    cin>>out;
    return out;
}
void solve(){
    int n,m;
    cin>>n>>m;
    //cout<<"//"<<n<<' '<<m<<endl;
    vector<set<int>> v(m);
    for(int i = 0;i<m;i++){
        int x;
        cin>>x;
        for(int j= 0;j<x;j++){
            int a;
            cin>>a;
            v[i].insert(a);
        }
    }
    int l = 1,r = n;
    //cout<<"///"<<l<<' '<<r<<endl;
    int big = 0;
    big = ask(l,r);
    while(l != r){
        //cout<<"//"<<l<<' '<<r<<endl;
        int mid = (l+r)/2;
        if(ask(l,mid) == big)r = mid;
        else l = mid+1;
    }
    vector<int>ans;
    for(int i = 0;i<m;i++){
        if(v[i].find(l) == v[i].end())ans.push_back(big);
        else{
            vector<int> tmp;
            for(int j = 1;j<=n;j++){
                if(v[i].find(j) == v[i].end())tmp.push_back(j);
            }
            cout<<"? "<<tmp.size()<<' ';for(auto i:tmp)cout<<i<<' ';cout<<endl;
            int a;
            cin>>a;
            ans.push_back(a);
        }
    }
    cout<<"! ";for(auto i:ans)cout<<i<<' ';cout<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        string ver;cin>>ver;
        if(ver[0] == 'I')return 0;
    }
    return 0;
}
/*
1 5 3 7 2 6 4
2 5 1 3 4

5 5
1 5
1 3
1 1
1 2
1 4
7
7 7
1 2
1 6
1 3
1 7
1 1
1 5
1 4
*/
