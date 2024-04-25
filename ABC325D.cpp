#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
const int inf = 4e18;
int n;
pii arr[mxn];
priority_queue<int,vector<int>,greater<int>> pq;

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc,arr[i].sc += arr[i].fs;
	sort(arr,arr+n);
	int ans = 0;
	int pt = 0;
	int now = 0;
	while(pt<n||!pq.empty()){
		while(pt<n&&arr[pt].fs == now){
			pq.push(arr[pt++].sc);
		}
		if(pq.empty()){
			now = arr[pt].fs;
			continue;
		}
		pq.pop();
		ans++;
		while(!pq.empty()&&pq.top()<=now)pq.pop();
		now++;
	}
	cout<<ans;
}
