#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0;i<24*60;i++){
        string a = to_string(i/60);
        string b = to_string(i%60);
        while(a.size()<2)a = "0"+a;
        while(b.size()<2)b = "0"+b;
        swap(b[0],a[1]);
        if(stoi(a)*60+stoi(b)>=24*60||b[0]>='6')continue;
        v.push_back(i);
    }
    // for(auto &i:v)cout<<i/60<<' '<<i%60<<endl;return 0;
    int h,m;
    cin>>h>>m;
    int t = h*60+m;
    auto it = lower_bound(v.begin(),v.end(),t);
    if(it == v.end())it = v.begin();
    cout<<*it/60<<' '<<*it%60;
}