#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> v){
    for(int i = 0;i<v.size()-4;i++){
        for(int j = 0;j<v[0].size()-4;j++){
            int c1 = 0,c2 = 0,c3 = 0,c4 = 0;
            for(int k = 0;k<2;k++){
                for(int kk = 0;kk<2;kk++){
                    c1 ^= v[i+k][j+kk];
                    c2 ^= v[i+k][j+3-kk];
                    c3 ^= v[i+3-k][j+kk];
                    c4 ^= v[i+3-k][j+3-kk];
                }
            }
            if(c1 != c4||c2 != c3){
                cout<<"ERROR at"<<i<<' '<<j<<'\n';
                cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<'\n';
                return false;
            }
        }
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    int p = 1<<(__lg(m)+2);
    int cc = p;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            v[i][j] += cc;
        }
        cc += p;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            v[i][j] += j;
        }
    }
    if(!check(v))cout<<"ERROR:"<<n<<' '<<m<<'\n';
    cout<<n*m<<'\n';
    for(auto &i:v){
        for(auto &j:i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}