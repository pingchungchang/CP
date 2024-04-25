#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
int main(){
    string s[9];
    int ans = 0;
    for(auto &i:s)cin>>i;
    for(int i = 0;i<81;i++){
        for(int j = 0;j<81;j++){
            if(i == j)continue;
            pii a = {i/9,i%9},b = {j/9,j%9};
            pii dir = {a.sc-b.sc,-a.fs+b.fs};
            pii c = {a.fs+dir.fs,a.sc+dir.sc},d = {b.fs+dir.fs,b.sc+dir.sc};
            //cout<<c.fs<<' '<<c.sc<<' '<<d.fs<<' '<<d.sc<<endl;
            if(c.fs<9&&c.sc<9&&d.fs<9&&d.sc<9&&c.fs>=0&&c.sc>=0&&d.fs>=0&&d.sc>=0&&s[a.fs][a.sc] == '#'&&s[b.fs][b.sc]=='#'&&s[c.fs][c.sc]=='#'&&s[d.fs][d.sc]=='#')ans++;
            dir = {-dir.fs,-dir.sc};
            c = {a.fs+dir.fs,a.sc+dir.sc},d = {b.fs+dir.fs,b.sc+dir.sc};
            if(c.fs<9&&c.sc<9&&d.fs<9&&d.sc<9&&c.fs>=0&&c.sc>=0&&d.fs>=0&&d.sc>=0&&s[a.fs][a.sc] == '#'&&s[b.fs][b.sc]=='#'&&s[c.fs][c.sc]=='#'&&s[d.fs][d.sc]=='#')ans++;
        }
    }
    cout<<ans/8;
}
