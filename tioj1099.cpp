#include <bits/stdc++.h>
using namespace std;

int n,sx,sy,sz,tx,ty,tz;

void solve(){
    set<tuple<int,int,int>> goneto;
    queue<tuple<int,int,int>> q;
    if(sx+sy+sz != tx+ty+tz){
        cout<<"No\n";
        return;
    }
    q.push(make_tuple(sx,sy,sz));
    goneto.insert(make_tuple(sx,sy,sz));
    while(!q.empty()){
        int x = get<0>(q.front()),y = get<1>(q.front()),z = get<2>(q.front());
        q.pop();
        if(x == tx&&y == ty&&z == tz){
            cout<<"Yes\n";
            return;
        }
        if(goneto.find(make_tuple(z,y,x)) == goneto.end()){
            goneto.insert(make_tuple(z,y,x));
            q.push(make_tuple(z,y,x));
        }
        if(goneto.find(make_tuple(x,z,y)) == goneto.end()){
            goneto.insert(make_tuple(x,z,y));
            q.push(make_tuple(x,z,y));
        }
        if(goneto.find(make_tuple(y,x,z)) == goneto.end()){
            goneto.insert(make_tuple(y,x,z));
            q.push(make_tuple(y,x,z));
        }
        if(2*y-x+1>=0&&2*y-x+1<=n&&2*x-y-1>=0&&2*x-y-1<=n&&goneto.find(make_tuple(2*y-x+1,2*x-y-1,z)) == goneto.end()){
            goneto.insert(make_tuple(2*y-x+1,2*x-y-1,z));
            q.push(make_tuple(2*y-x+1,2*x-y-1,z));
        }
    }
    cout<<"No\n";
    return;
}
int main(){
    while(cin>>n>>sx>>sy>>sz>>tx>>ty>>tz){
        if(n != 0)solve();
        else return 0;
    }
}
//2y-x+1, 2x-y-1, z
