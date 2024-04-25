#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int ask(int k){
	cout<<"?"<<' '<<k<<endl;
	int re;
	cin>>re;
	return re;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v;
	int sum = 0;
	if(n%k == 0){
		for(int i = 1;i<n;i+=k){
			sum^=ask(i);
		}
		cout<<"! "<<sum<<endl;
		return;
	}
	int s;
	for(s = 1;s+k<n;s+=k){
		int re = ask(s);
		v.push_back(re);
		sum ^= re;
	}
	int t1 = (n-(n%k)+1+n)/2-k+1;
	int t2 = t1+(n%k)/2;
	sum ^= ask(t1)^ask(t2);
	cout<<"! "<<sum<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
