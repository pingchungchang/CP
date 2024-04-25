#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
int segtree[mxn*4];
int arr[mxn];
vector<int> v1,v2;


int main(){
    int n,k;
    cin>>n>>k;
    int kk = k;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    if(k == 0){
        for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';return 0;
    }
    deque<pii> dq;
    for(int i = 1;i<=n;i++){
        while(!dq.empty()&&k-dq.back().sc>=0&&dq.back().fs>arr[i]){
            k -= dq.back().sc;
            dq.pop_back();
        }
        dq.push_back({arr[i],1});
    }
    while(!dq.empty()&&k-dq.back().sc>=0){
        k -= dq.back().sc;
        dq.pop_back();
    }
    while(!dq.empty()){
        v1.push_back(dq.front().fs);
        dq.pop_front();
    }

    pii small = {n,n};
    for(int i = 0;i<kk;i++){
        small = min(small,{arr[n-i],n-i});
    }
    k = kk;
    k -= (n-small.sc+1);
    // cout<<n<<','<<small.sc<<endl<<endl;
    for(int i = small.sc;i<=n;i++){
        while(!dq.empty()&&dq.back().fs>arr[i])dq.pop_back();
        dq.push_back({arr[i],0});
    }
    for(int i = 1;i<small.sc;i++){
        while(!dq.empty()&&k-dq.back().sc>=0&&dq.back().fs>arr[i]){
            k -= dq.back().sc;
            dq.pop_back();
        }
        dq.push_back({arr[i],1});
        // for(auto &i:dq)cout<<i.fs<<' '<<i.sc<<',';cout<<k;cout<<endl;
    }
    while(!dq.empty()&&k-dq.back().sc>=0){
        k -= dq.back().sc;
        dq.pop_back();
    }
    while(!dq.empty()){
        v2.push_back(dq.front().fs);
        dq.pop_front();
    }
    v1 = min(v1,v2);
    for(auto &i:v1)cout<<i<<' ';
}