#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
priority_queue<ll> pq;
ll sum = 0;
pll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].sc>>arr[i].fs;
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		if(sum+arr[i].sc<=arr[i].fs){
			sum +=arr[i].sc;
			pq.push(arr[i].sc);
		}
		else{
			if(pq.top()<arr[i].sc)continue;
			else{
				sum -= pq.top();
				pq.pop();
				sum += arr[i].sc;
				pq.push(arr[i].sc);
			}
		}
	}
	cout<<pq.size();
}
