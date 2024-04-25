#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ld long double
#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct edge{
    bool del;
    int s,e;
    edge(){}
    edge(int ss,int ee){
        s = ss,e = ee;
        del = false;
    }
};
const int mxn = 2e4+10;
map<int,int> mp;
int ttt = 0;
int n,m;
edge paths[mxn*6];
int dsu[mxn];
bool flag = false;
int vals[mxn];
ordered_set arr[mxn];
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    int ra = root(a);
    int rb = root(b);
    if(ra == rb)return;
    if(arr[ra].size()<arr[rb].size())swap(ra,rb);
    dsu[rb] = ra;
    for(auto &i:arr[rb])arr[ra].insert(i);
    arr[rb].clear();
    return;
}
void solve(){
    ttt++;
    mp.clear();
    for(int i = 0;i<n;i++){
        arr[i].clear();
        int k;
        cin>>k;
        vals[i] = k;
        dsu[i] = i;
    }
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[i] = edge(a,b);
    }
    vector<tuple<char,int,int>> mv;
    char c;
    while(cin>>c){
        if(c == 'E')break;
        if(c == 'D'){
            int a;
            cin>>a;
            mv.push_back(make_tuple(c,a,-1));
            paths[a].del = true;
        }
        else if(c == 'Q'){
            int a,b;
            cin>>a>>b;
            mv.push_back(make_tuple(c,a,b));
        }
        else if(c == 'C'){
            int a,b;
            cin>>a>>b;
            mv.push_back(make_tuple(c,a,vals[a]));
            vals[a] = b;
        }
    }
    for(int i = 0;i<n;i++)arr[i].insert({vals[i],mp[vals[i]]++});
    for(int i = 0;i<m;i++){
        if(!paths[i].del)onion(paths[i].s,paths[i].e);
    }
    ll total = 0,cnt = 0;
    for(int i = mv.size()-1;i>=0;i--){
        // cout<<get<0>(mv[i])<<',';
        if(get<0>(mv[i]) == 'D'){
            onion(paths[get<1>(mv[i])].s,paths[get<1>(mv[i])].e);
        }
        else if(get<0>(mv[i]) == 'C'){
            int r = root(get<1>(mv[i]));
            int pre = vals[get<1>(mv[i])];
            int nxt = get<2>(mv[i]);
            arr[r].erase(arr[r].lower_bound({pre,-1}));
            arr[r].insert({nxt,mp[nxt]++});
            vals[get<1>(mv[i])] = nxt;
        }
        else{
            int r = root(get<1>(mv[i]));
            int k = get<2>(mv[i]);
            cnt++;
            if(k<=arr[r].size()){
                total += arr[r].find_by_order(arr[r].size()-k)->fs;
            }
        }
    }
    if(flag)cout<<'\n';
    cout<<"Sekai "<<ttt<<": "<<fixed<<setprecision(6)<<(ld)total/cnt;
    flag= true;
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        if(!n&&!m)return 0;
        solve();
    }
}