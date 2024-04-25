#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> v1,v2,v3;
	for(int i = 0;i<n;i++){
		int t,x;
		cin>>t>>x;
		if(t ==  0)v1.push_back(x);
		else if(t == 1)v2.push_back(x);
		else if(t == 2)v3.push_back(x);
	}
	sort(v1.rbegin(),v1.rend());
	sort(v2.rbegin(),v2.rend());
	sort(v3.rbegin(),v3.rend());
	ll ans = 0;
	for(int i = 0;i<min(m,(int)v1.size());i++)ans += v1[i];
	ll sum = 0;
	multiset<ll> st;
	for(auto &i:v1){
		st.insert(i);
		sum += i;
	}
	while(st.size()>m){
		sum -= *st.begin();
		st.erase(st.find(*st.begin()));
	}
	int pt = 0;
	for(int i = 1;i<=v3.size();i++){
		if(i>=m)break;
		while(pt<v2.size()&&v3[i-1]--){
			st.insert(v2[pt]);
			sum += v2[pt];
			pt++;
		}
		//cout<<i<<":"<<st.size()<<' '<<sum<<endl;
		while(st.size()>m-i){
			sum -= *st.begin();
			st.erase(st.find(*st.begin()));
		}
		ans = max(ans,sum);
		//cout<<i<<":"<<sum<<'\n';
	}
	cout<<ans;
}
