#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 2e5+10;
const ll inf = 1e9+10;
ll arr[mxn];
int n;
priority_queue<int,vector<int>,less<int>> pq;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	ll sh = 0;
	pq.push(-inf);
	for(int i = 0;i<n;i++){
		if(arr[i]>=pq.top()){
			pq.push(arr[i]);
		}
		else{
			sh += pq.top()-arr[i];
			pq.push(arr[i]);
			pq.push(arr[i]);
			pq.pop();
		}
	}
	cout<<sh;
}
