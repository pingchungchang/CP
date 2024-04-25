#include <bits/stdc++.h>
using namespace std;


struct team{
    vector<int>bett;
    vector<int>wors;
    vector<int> norm;
    int id;
    team(){}
    team(int x){
        bett = vector<int>(x);
        wors = vector<int>(x);
        norm = vector<int>(x);
    }
};
bool cmp(team a,team b){
    return a.id>b.id;
}
int main(){
    int k,n;
    cin>>n>>k;
    int win = n+1;
    n = 2*n+1;
    vector<team> v(k,team(n));
    for(int i = 0;i<k;i++){
        int s;
        cin>>v[i].id;
        for(int j = 0;j<n;j++)cin>>v[i].norm[j];
        for(int j = 0;j<n;j++)cin>>v[i].bett[j];
        for(int j = 0;j<n;j++)cin>>v[i].wors[j];
    }
    sort(v.begin(),v.end(),cmp);
    int nwin = 0;
    int uwin = 0;
    for(int i = 0;i<k;i++){
        bool b= true;
        for(int j = 0;j<k;j++){
            if(i == j)continue;
            int p = 0;
            for(int l = 0;l<n;l++){
                if(v[i].norm[p]>v[j].norm[l])p++;
            }
            if(p<win)b = false;
        }
        if(b)nwin = max(nwin,v[i].id);
    }
    for(int i = 0;i<k;i++){
        bool b= true;
        for(int j = 0;j<k;j++){
            if(i == j)continue;
            int p = 0;
            for(int l = 0;l<n;l++){
                if(v[i].bett[p]>v[j].wors[l])p++;
            }
            if(p<win)b = false;
        }
        if(b)uwin = max(uwin,v[i].id);
    }
    cout<<nwin<<' '<<uwin;
}
