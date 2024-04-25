#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n,q;
	cin>>n>>q;
	queue<int> qe;
	for(int i = 1;i<=n;i++)qe.push(i);
	vector<int> v(n+1,0);
	for(int i = 1;i<=n;i++){
		v[i] = qe.front();
		qe.pop();
		qe.push(qe.front());
		qe.pop();
	}
	while(q--){
		int k;
		cin>>k;
		cout<<v[k]<<'\n';
	}
	
}

