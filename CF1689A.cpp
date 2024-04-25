#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	multiset<char> a,b;
	for(int i = 0;i<n;i++){
		char c;
		cin>>c;
		a.insert(c);
	}
	for(int i = 0;i<m;i++){
		char c;
		cin>>c;
		b.insert(c);
	}
	string ans = "";
	pair<int,int> cnt = make_pair(0,0);
	while(!a.empty()&&!b.empty()){
//		cout<<cnt.fs<<' '<<cnt.sc<<',';
		if(*a.begin()<*b.begin()){
			if(cnt.fs == 0&&cnt.sc==k){
				cnt.fs = 1;
				ans += *b.begin();
				b.erase(b.begin());
				cnt = make_pair(1,1);
			}
			else{
				if(cnt.fs == 1)cnt = make_pair(0,0);
				cnt.sc++;
				ans += *a.begin();
				a.erase(a.begin());
			}
		}
		else{
			if(cnt.fs == 1&&cnt.sc == k){
				ans += *a.begin();
				a.erase(a.begin());
				cnt = make_pair(0,1);
			}
			else{
				if(cnt.fs == 0)cnt = make_pair(1,0);
				cnt.sc++;
				ans += *b.begin();
				b.erase(b.begin());
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

