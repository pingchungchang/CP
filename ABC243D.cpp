#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,now,k;
    cin>>n>>now;
    deque<char> dq;
    for(ll i = 0;i<n;i++){
        char c;
        cin>>c;
        if(c == 'L'||c == 'R')dq.push_back(c);
        else if(!dq.empty()&&dq.back() != 'U'){
            dq.pop_back();
        }
        else dq.push_back(c);
    }
    while(!dq.empty()){
        if(dq.front() == 'U')now /=2;
        else if(dq.front() == 'L')now = now*2;
        else now = now*2+1;
        dq.pop_front();
    }
    cout<<now;
}
