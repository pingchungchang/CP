#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
tuple<int,int,int> arr[mxn];
int dsu[mxn],sz[mxn];
int n,m;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a] < sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		dsu[i] = i,sz[i] = 1;
	}
	int sum = 0;
	for(int i = 0;i<m;i++){
		cin>>get<1>(arr[i])>>get<2>(arr[i])>>get<0>(arr[i]);
		sum += get<0>(arr[i]);
	}
	sort(arr,arr+m);
	for(int i = 0;i<m;i++){
		int ta = get<1>(arr[i]),tb = get<2>(arr[i]),v = get<0>(arr[i]);
		if(v<=0){
			onion(ta,tb);
			sum -= v;
		}
		else if(root(ta) != root(tb))sum -= v,onion(ta,tb);
	}
	cout<<sum;
}
