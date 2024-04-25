#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>m>>n;
    vector<vector<pair<int,vector<int>>>> dist(m,vector<pair<int,vector<int>>>(m,make_pair(999,vector<int>(0))));
    for(int i =0;i<m;i++){
        for(int j =0;j<m;j++){
            dist[i][j].second.push_back(i);
        }
    }
    for(int i =0;i<n;i++){
        int x,y,d;
        cin>>x>>y>>d;
        dist[x][y].first = d;
        dist[y][x].first = d;
        dist[x][y].second.push_back(y);
        dist[y][x].second.push_back(x);
    }
    int s,p;
    cin>>p;
    int start;
    vector<int> arr(p);
    for(int i =0;i<p;i++){
        cin>>s;
        if(i == 0)start = s;
        arr[i] = s;
    }
    for(int i =0;i<m;i++){
        for(int j =0;j<m;j++){
            for(int k = 0;k<m;k++){
                if(dist[j][i].first!= 999&&dist[i][k].first!= 999){
                    if(dist[j][i].first+dist[i][k].first<dist[j][k].first){
                        dist[j][k].first = dist[j][i].first+dist[i][k].first;
                        dist[j][k].second = dist[j][i].second;
                        for(int l =1;l<dist[i][k].second.size();l++){
                            dist[j][k].second.push_back(dist[i][k].second[i]);
                        }
                    }
                }
            }
        }
    }
    for(int i =0;i<m;i++){
        for(int j =0;j<m;j++){
            cout<<dist[i][j].second[1]<<' ';
        }
        cout<<'\n';
    }
    int ans = INT_MAX;
    vector<vector<int>> r;
    sort(arr.begin(),arr.end());
    while(next_permutation(arr.begin(),arr.end())){
        if(arr[0]!= start)continue;
        int now = 0;
        vector<vector<int>> temp;
        for(int i =1;i<p;i++){
            now += dist[arr[i-1]][arr[i]].first;
            temp.push_back(dist[arr[i-1]][arr[i]].second);
        }
        if(now<ans){
            ans = now;
            r = temp;
        }
    }
    cout<<"Minimum travel distance: "<<ans<<'\n';
    cout<<"Travel route: ";
    for(int i =0;i<r.size();i++){
        for(int j  =0;j<r[i].size();j++){
            cout<<r[i][j];
            if(i != r.size()-1&&j != r[r.size()-1].size()-1)cout<<' ';
        }
    }
}

//somehow failed