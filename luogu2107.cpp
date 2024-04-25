#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
ll n,m;
pll arr[mxn];
priority_queue<ll> pq;
ll sum = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	sort(arr,arr+n);
	ll ans = 0;
	for(int i = 0;i<n;i++){
		pq.push(arr[i].sc);
		sum += arr[i].sc;
		ll rest = m-arr[i].fs;
		if(rest<0)break;
		while(!pq.empty()&&sum>rest){
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans,(ll)pq.size());
	}
	cout<<ans;
}
