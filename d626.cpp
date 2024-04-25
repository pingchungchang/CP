#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> m(n);
    for(int i = 0;i<n;i++){
        string st;
        cin>>st;
        m[i] = st;
    }
    pair<int,int> s;
    int a,b;
    cin>>a>>b;
    s.first =a;
    s.second = b;
    queue<pair<int,int>> q;
    q.push(s);
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        if(now.first>=0&&now.first<n&&now.second<n&&now.second>=0&&m[now.first][now.second] == '-'){
            m[now.first][now.second] = '+';
            q.push(make_pair(now.first,now.second+1));
            q.push(make_pair(now.first,now.second-1));
            q.push(make_pair(now.first+1,now.second));
            q.push(make_pair(now.first-1,now.second));
        }
    }
    for(int i = 0;i<n;i++){
        cout<<m[i];
        if(i != n-1)cout<<"\n";
    }
}