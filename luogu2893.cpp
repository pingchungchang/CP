#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 2022;
priority_queue<ll,vector<ll>,less<ll>> pq;
ll sum;
ll ans;
ll arr[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ans = 4e18;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sum = 0;
	pq.push(arr[0]);
	for(int i = 1;i<n;i++){
		pq.push(arr[i]);
		sum += pq.top()-arr[i];
		pq.pop();
		pq.push(arr[i]);
	}
	ans = min(ans,sum);
	while(!pq.empty())pq.pop();
	sum = 0;
	for(int i = 0;i<n;i++)arr[i] = -arr[i];
	pq.push(arr[0]);
	for(int i = 1;i<n;i++){
		pq.push(arr[i]);
		sum += pq.top()-arr[i];
		pq.pop();
		pq.push(arr[i]);
	}
	ans = min(ans,sum);
	cout<<ans;
}
