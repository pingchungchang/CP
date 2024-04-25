#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int ask(int a,int b){
	cout<<"? "<<a<<' '<<b<<endl;
	int re;
	cin>>re;
	return re;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 1;i<=n;i++)v.push_back(i);
	while(v.size()>1){
		vector<int> vv;
		for(int i = 1;i<v.size();i+=2){
			int ta = ask(v[i-1],v[i]);
			if(v[i-1]+1==v[i]){
				if(ta)vv.push_back(v[i-1]);
				else vv.push_back(v[i]);
			}
			else{
				int tb = ask(v[i-1],v[i]-1);
				if(ta == tb)vv.push_back(v[i]);
				else vv.push_back(v[i-1]);
			}
		}
		if(v.size()&1)vv.push_back(v.back());
		swap(v,vv);
	}
	cout<<"! "<<v[0]<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
