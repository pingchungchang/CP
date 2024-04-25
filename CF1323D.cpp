#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	int ans = 0;
	for(int i = 26;i>=0;i--){
		//if (1<<i)&j : 0~(1<<(i+1))-j-1,(3<<i-j)~inf
		//else (1<<i)-j~(2<<i)-j-1,(3<<i)-j~inf
		for(int j = 0;j<v.size();j++){
			int cnt = 0;
			int p1 = lower_bound(v.begin(),v.end(),(1<<i)-v[j])-v.begin();
			int p2 = lower_bound(v.begin(),v.end(),(2<<i)-v[j])-v.begin();
			int p3 = lower_bound(v.begin(),v.end(),(3<<i)-v[j])-v.begin();
			p1 = min(p1,j);
			p2 = min(p2,j);
			p3 = min(p3,j);
			if(v[j]&(1<<i))cnt = p2+(j-p3);
			else cnt = (p2-p1)+(j-p3);
			//cout<<i<<' '<<v[j]<<' '<<p1<<' '<<p2<<' '<<p3<<":"<<ans<<endl;
			if(cnt&1)ans ^= 1<<i;
		}
		for(auto &j:v)if(j&(1<<i))j^=1<<i;
		sort(v.begin(),v.end());
	}
	cout<<ans;
}
