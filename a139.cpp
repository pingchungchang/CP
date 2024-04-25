#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int asd;
    while(cin>>asd)v.push_back(asd);
    int m = *v.rbegin();
    int ans = 0;
    v.pop_back();
    set<int> now;
    set<int> cp;
    for(int i = 1;i<=n;i++)cp.insert(i);
    for(int i = 0;i<v.size();i++){
        if(now.size()<m){
            now.insert(v[i]);
        }
        else if(now.find(v[i]) == now.end()){
            set<int> all = now;
            for(int j = i+1;j<v.size();j++){
                if(all.size() == 1)break;
                if(all.find(v[j]) != all.end())all.erase(v[j]);
            }
            ans++;
            now.erase(*all.begin());
            now.insert(v[i]);
        }
        else{
            now.insert(v[i]);
        }
    }
    cout<<ans;
}
