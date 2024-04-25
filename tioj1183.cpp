#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i =0;i<n;i++){
        int a,b;
        pair<int,int> now;
        cin>>a>>b;
        vector<string> v(a);
        for(int j =0;j<a;j++){
            for(int k =0;k<b;k++){
                char x;
                cin>>x;
                if(x == 'S') now = make_pair(j,k);
                v[j]+= x;
            }
        }
        string ans;
        while(v[now.first][now.second] != 'T'){
            v[now.first][now.second] = '#';
            if(now.first>0&&v[now.first-1][now.second] != '#'){
                cout<<'U';
                now.first-=1;
            }
            else if(now.first<a-1&&v[now.first+1][now.second] !='#'){
                cout<<'D';
                now.first+=1;
            }
            else if(now.second>0&&v[now.first][now.second-1] != '#'){
                cout<<'L';
                now.second-=1;
            }
            else{
                cout<<'R';
                now.second+=1;
            }
        }
        if(i != n-1)cout<<'\n';
    }
}
