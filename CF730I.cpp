#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3030;
int n,p,s;
multiset<pll> rs1,rs2,ls1,ls2;
tlll arr[mxn];
ll rsum,lsum;
ll ans;
vector<ll> v[2];

inline void balance(multiset<pll>&tar,multiset<pll>&from,int sz,ll &sum){
	while(tar.size()<sz){
		auto tmp = *from.rbegin();
		tar.insert(tmp);
		sum += from.rbegin()->fs;
		from.erase(from.find(*from.rbegin()));
	}
	while(tar.size()>sz){
		auto tmp = *tar.begin();
		sum -= tar.begin()->fs;
		from.insert(tmp);
		tar.erase(tar.find(*tar.begin()));
	}
	assert(tar.size() == sz);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>p>>s;
	for(int i = 0;i<n;i++)cin>>get<0>(arr[i]);
	for(int i = 0;i<n;i++)cin>>get<1>(arr[i]);
	for(int i = 0;i<n;i++)get<2>(arr[i]) = i;
	sort(arr,arr+n,greater<tlll>());
	for(int i = 0;i<p;i++){
		ls1.insert({get<0>(arr[i])-get<1>(arr[i]),get<2>(arr[i])});
		lsum += get<0>(arr[i]);
	}
	for(int i = p;i<n;i++){
		rs1.insert({get<1>(arr[i]),get<2>(arr[i])});
		rsum += get<1>(arr[i]);
	}
	balance(ls1,ls2,p,lsum);
	balance(rs1,rs2,s,rsum);
	ans = lsum+rsum;
	for(auto &i:ls1)v[0].push_back(i.sc);
	for(auto &i:rs1)v[1].push_back(i.sc);

	for(int i = p;i<s+p;i++){
		pll tmp = make_pair(get<1>(arr[i]),get<2>(arr[i]));
		if(rs2.find(tmp) != rs2.end()){
			rs2.erase(tmp);
		}
		else{
			rs1.erase(tmp);
			rsum -= tmp.fs;
		}
		tmp.fs = get<0>(arr[i])-get<1>(arr[i]);
		lsum += get<0>(arr[i]);
		ls1.insert(tmp);
		balance(rs1,rs2,p+s-i-1,rsum);
		balance(ls1,ls2,p,lsum);
		if(ans<lsum+rsum){
			ans = lsum+rsum;
			v[0].clear();v[1].clear();
			for(auto &j:ls1)v[0].push_back(j.sc);
			for(auto &j:ls2)v[1].push_back(j.sc);
			for(auto &j:rs1)v[1].push_back(j.sc);
		}
		//cout<<i<<":"<<lsum+rsum<<endl;
	}
	cout<<ans<<'\n';
	for(auto &i:v[0])cout<<i+1<<' ';cout<<'\n';
	for(auto &i:v[1])cout<<i+1<<' ';cout<<'\n';
}
