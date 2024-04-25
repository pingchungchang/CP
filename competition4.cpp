#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int,vector<int>> timetoslime;
vector<int> changes;
vector<int> changeslimes(vector<int> slimes,int t){
    int j =0;
    int pasttime = 0;
    for(int i =0;i<changes.size();i++){
        if(changes[i]<=t){
            pasttime  = changes[i];
        }
    }
    slimes = timetoslime[pasttime];
    for(int i =0;i<slimes.size();i++){
        for(int j =1;j<=t-pasttime;j++){
            if(i+j>=slimes.size()) break;
            else{
                slimes[i+j] = max(slimes[i],slimes[i+j]);
            }
        }
        for(int j =1;j<=t-pasttime;j++){
            if(i-j<0) break;
            else{
                slimes[i-j] = max(slimes[i],slimes[i-j]);
            }
        }
    }
    return slimes;
}
int main(){
    int N,T;
    cin>>N>>T;
    vector<int> slimes;
    for(int i =0;i<N;i++){
        int k;
        cin>>k;
        slimes.push_back(k);
    }
    changes.push_back(0);
    timetoslime[0] = slimes;
    int Q;
    cin>>Q;
    for(int i =0;i<Q;i++){
        int type,t,p;
        cin>>type>>t>>p;
        vector<int> nowslimes = changeslimes(slimes,t);
        if(type == 1){
            int x;
            cin>>x;
            nowslimes[p-1] = max(nowslimes[p-1],x);
            if(timetoslime.count(t) == 0) {
                changes.push_back(t);
                sort(changes.begin(),changes.end());
            }
            timetoslime[t] = nowslimes;
        }
        else{
            cout<<nowslimes[p-1];
            if(i != Q-1) cout<<"\n";
        }
    }
}
