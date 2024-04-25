#include <bits/stdc++.h>
using namespace std;

#define ld long double

const ld eps = 1e-17;
int main(){
    int n;
    cin>>n;
    priority_queue<ld,vector<ld>,greater<ld>> pq;
    ld avg = 0;
    for(int i = 0;i<n;i++){
        ld k;
        cin>>k;
        avg += k;
        pq.push(k);
    }
    int cnt = 0;
    avg/=n;
    while(avg<4.5-eps){
        ld k = pq.top();
        avg += (5-k)/n;
        pq.pop();
        cnt++;
        //cout<<k<<' '<<avg<<' '<<avg-4.5<<endl;
    }
    cout<<cnt;
}
