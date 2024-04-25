#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	int sum = 0;
	priority_queue<pii,vector<pii>,less<pii>> pq;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		sum += k;
		pq.push(make_pair(k,i));
	}
	if(pq.top().fs>=(sum+1)/2){
//		cout<<"l\n";
		int pos = pq.top().sc;
		cout<<sum-pq.top().fs<<'\n';
		pq.pop();
		while(!pq.empty()){
			for(int i = 0;i<pq.top().fs;i++){
				cout<<pos<<' '<<pq.top().sc<<'\n';
			}
			pq.pop();
		}
	}
	else{
//		cout<<"r\n";
		vector<int> all;
		while(!pq.empty()){
			for(int i = 0;i<pq.top().fs;i++){
				all.push_back(pq.top().sc);
			}
			pq.pop();
		}
		cout<<sum/2<<'\n';
		for(int i = 0;i<sum/2;i++){
			cout<<all[i]<<' '<<all[i+sum/2]<<'\n';
		}
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

