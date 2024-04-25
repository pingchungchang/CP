#include <bits/stdc++.h>
using namespace std;


string maze[2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n;
        cin>>n;
        cin>>maze[0]>>maze[1];
        bool done = true;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        maze[0][0]= '0';
        while(!q.empty()){
            pair<int,int> now = q.front();
            q.pop();
            //cout<<now.first<<' '<<now.second<<endl;
            if(now.second == n-1||now.second == n-2){
                done=false;
                break;
            }
            if(maze[1-now.first][now.second] == '0'){
                maze[1-now.first][now.second] = '1';
                q.push(make_pair(1-now.first,now.second));
            }
            if(maze[1-now.first][now.second+1] == '0'){
                maze[1-now.first][now.second+1] = '1';
                q.push(make_pair(1-now.first,now.second+1));
            }
            if(maze[now.first][now.second+1] == '0'){
                maze[now.first][now.second+1] = '1';
                q.push(make_pair(now.first,now.second+1));
            }
        }
        if(done == true){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}
