#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pii pair<int,int>
const int mxn = 1505;
vector<int> row[mxn],col[mxn];
vector<int> prer[mxn],prec[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w;
    cin>>h>>w;
    for(int i = 1;i<=w;i++)row[i].push_back(h+1),row[i].push_back(0);
    for(int i = 1;i<=h;i++)col[i].push_back(w+1),col[i].push_back(0);
    int n,m;
    cin>>n>>m;
    set<pii> st;
    pii bulbs[n];
    for(auto &i:bulbs)cin>>i.fs>>i.sc;
    for(int i = 0;i<m;i++){
        pii tmp;
        cin>>tmp.fs>>tmp.sc;
        st.insert(tmp);
        col[tmp.fs].push_back(tmp.sc);
        row[tmp.sc].push_back(tmp.fs);
    }
    for(int i = 1;i<=w;i++)sort(row[i].begin(),row[i].end()),prer[i] = vector<int>(row[i].size(),0);
    for(int i = 1;i<=h;i++)sort(col[i].begin(),col[i].end()),prec[i] = vector<int>(col[i].size(),0);
    for(auto &i:bulbs){
        auto it = lower_bound(row[i.sc].begin(),row[i.sc].end(),i.fs)-row[i.sc].begin();
        prer[i.sc][it]--;
        prer[i.sc][it-1]++;
        it = lower_bound(col[i.fs].begin(),col[i.fs].end(),i.sc)-col[i.fs].begin();
        prec[i.fs][it]--;
        prec[i.fs][it-1]++;
    }
    for(int i = 1;i<=w;i++)for(int j = 1;j<row[i].size();j++)prer[i][j] += prer[i][j-1];
    for(int i = 1;i<=h;i++)for(int j = 1;j<col[i].size();j++)prec[i][j] += prec[i][j-1];
    int ans = 0;
    // cout<<endl;
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++){
            if(st.find({i,j}) != st.end())continue;
            bool flag = false;
            auto it = --lower_bound(row[j].begin(),row[j].end(),i)-row[j].begin();
            if(prer[j][it])flag = true;
            it = --lower_bound(col[i].begin(),col[i].end(),j)-col[i].begin();
            if(prec[i][it])flag = true;
            if(flag)ans++;
            // if(flag)cout<<i<<' '<<j<<endl;
        }
    }
    cout<<ans;
}