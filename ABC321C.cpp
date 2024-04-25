#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i = 1;i<10;i++)pq.push(i);
	pq.push(0);
	while(n--){
		auto now = pq.top();
		pq.pop();
		ll tmp = now;
		ll p = 1;
		while(tmp/p>=10)p*=10;
		for(int j = tmp/p+1;j<10;j++){
			ll k = now+p*10*j;
			pq.push(k);
		}
	}
	cout<<pq.top();
}
