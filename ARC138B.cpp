#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> dq;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        dq.push_back(k);
    }
    int now = 0;
    while(!dq.empty()){
        if(dq.back() == now){
            dq.pop_back();
            continue;
        }
        else if(dq.front() == now){
            dq.pop_front();
            now^=1;
            continue;
        }
        else break;
    }
    if(dq.empty())cout<<"Yes";
    else cout<<"No";
}
