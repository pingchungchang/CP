#include <bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first!= b.first)return a.first<b.first;
        else return a.second>b.second;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n;
        cin>>n;
        vector<pair<int,int>> dolls(n);
        for(int i =0;i<n;i++){
            int a,b;
            cin>>a>>b;
            dolls[i].first = a;
            dolls[i].second=b;
        }
        sort(dolls.begin(),dolls.end(),Compare());
        vector<int> lis;
        int nowfirst = 0;
        for(int i =0;i<n;i++){
            if(dolls[i].first == nowfirst)continue;
            else nowfirst = dolls[i].first;
            auto p = upper_bound(lis.begin(),lis.end(),dolls[i].second);
            if(p == lis.end())lis.push_back(dolls[i].second);
            else *p = dolls[i].second;
        }
        cout<<lis.size()<<'\n';
    }
}
//fail
