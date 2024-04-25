#include <bits/stdc++.h>
using namespace std;
pair<int,int> d[8];

void dfse(vector<string> &graph,int x,int y){
    if(graph[x][y] == '-'){
        graph[x][y] = 'O';
        for(int i=0;i<8;i++){
            if(x+d[i].first>=0&&x+d[i].first<graph.size()&&y+d[i].second>=0&&y+d[i].second<graph[0].size()&&graph[x+d[i].first][y+d[i].second]=='-')dfse(graph,x+d[i].first,y+d[i].second);
        }
    }
    else return;
}

void dfsg(vector<string> &graph,int x,int y){
    if(graph[x][y] == 'G'){
        graph[x][y] = 'O';
        for(int i=0;i<8;i++){
            if(x+d[i].first>=0&&x+d[i].first<graph.size()&&y+d[i].second>=0&&y+d[i].second<graph[0].size()&&graph[x+d[i].first][y+d[i].second]=='G')dfsg(graph,x+d[i].first,y+d[i].second);
        }
    }
    else return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> graph(m);
    int x =0;
    for(int i =-1;i<2;i++){
        for(int j =-1;j<2;j++){
            if(i==0&&j==0)continue;
            d[x] =make_pair(i,j);
            x++;
        }
    }
    for(int i =0;i<m;i++){
        string k;
        cin>>k;
        graph[i] = k;
    }
    int emp = 0,green=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] == '-'){
                emp++;
                dfse(graph,i,j);
            }
            else if(graph[i][j] == 'G'){
                green++;
                dfsg(graph,i,j);
            }
        }
    }
    cout<<green<<' '<<emp;
}

