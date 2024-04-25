#include <bits/stdc++.h>
using namespace std;

int a;
bool findall(vector<pair<vector<int>,vector<int>>> &limits,int now,pair<vector<int>,vector<int>> keys,int putplace){
    if(now == a-1)return true;
    if(putplace == 0){
        for(int i =0;i<limits[now].first.size();i++){
            keys.first[limits[now].first[i]] = 1;
        }
        for(int i =0;i<limits[now].second.size();i++){
            keys.first[limits[now].second[i]] = -1;
        }
    }
    else if(putplace == 1){
        for(int i =0;i<limits[now].first.size();i++){
            keys.second[limits[now].first[i]] = 1;
        }
        for(int i =0;i<limits[now].second.size();i++){
            keys.second[limits[now].second[i]] = -1;
        }
    }
    now++;
    bool ta = true,tb = true;
    for(int i =0;i<limits[now].first.size();i++){
        if(keys.first[limits[now].first[i]] ==-1){
            ta=false;
            break;
        }
    }
    for(int i =0;i<limits[now].second.size();i++){
        if(ta==false)break;
        if(keys.first[limits[now]].second[i] == 1)ta = false;
        if(i == limits[now].second.size()-1)ta = findall(limits,now,keys,1);
    }
    for(int i =0;i<limits[now].first.size();i++){
        if(keys.second[limits[now].first[i]] ==-1){
            tb=false;
            break;
        }
    }
    for(int i =0;i<limits[now].second.size();i++){
        if(ta==false)break;
        if(keys.second[limits[now]].second[i] == 1)tb = false;
        if(i == limits[now].second.size()-1)tb = findall(limits,now,keys,2);
    }
    return ta|tb;
}
int main(){
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int asd =0;asd<T;asd++){
        int b;
        cin>>a>>b;
        vector<int> ka(b/2+2,0);
        vector<int> kb(b/2+2,0);
        vector<pair<vector<int>,vector<int>>> limits(a);
        for(int i =0;i<a;i++){
            int k;
            while(cin>>k){
                if(k == 0)break;
                limits[i].first.push_back(k);
            }
            while(cin>>k){
                if(k == 0)break;
                limits[i].second.push_back(k);
            }
        }
        if(findall(limits,0,make_pair(ka,kb)) == false)cout<<"No\n";
        else cout<<"Yes\n";
    }
}
