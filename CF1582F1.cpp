#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	vector<ll> v(512,INT_MAX);
	v[0] = -1;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<512;j++){
			if(k>v[j]){
				int val = k^j;
				v[val] = min(v[val],1LL*k);
			}
		}
	}
	queue<int> q;
	for(int i = 0;i<512;i++){
		if(v[i] != INT_MAX){
			q.push(i);
		}
	}
	cout<<q.size()<<'\n';
	while(!q.empty()){
		cout<<q.front()<<' ';q.pop();
	}
	return 0;
}

