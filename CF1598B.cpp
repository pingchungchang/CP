#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(5));
    for(int i = 0;i<n;i++)for(int j = 0;j<5;j++)cin>>v[i][j];
    for(int i = 0;i<5;i++){
        for(int j = i+1;j<5;j++){
            set<int> a,b;
            for(int asd = 0;asd<n;asd++){
                if(v[asd][i] == 1)a.insert(asd);
                if(v[asd][j] == 1)b.insert(asd);
            }
            if(a.size()<n/2||b.size()<n/2)continue;
            for(int asd = 0;asd<n;asd++){
                if(a.find(asd) == a.end()&&b.find(asd) == b.end()){
                    break;
                }
                if(asd == n-1){
                    cout<<"YES\n";
                    return;
                }
            }
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
