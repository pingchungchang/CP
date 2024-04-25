#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;

ll N,A,B,C;
pll arr[mxn];
ll brr[mxn];
ll ans = 0;
ll sum = 0;

ll calc(){
	multiset<ll> ls,rs1,rs2;
	sort(arr+1,arr+N+1,greater<pll>());
	ll sum = 0;
	for(int i = 1;i<=A;i++){
		sum += arr[i].fs;
		ls.insert(arr[i].fs-arr[i].sc);
	}
	for(int i = A+1;i<=N;i++){
		rs2.insert(arr[i].sc);
	}
	while(rs1.size()<B){
		sum += *rs2.rbegin();
		rs1.insert(*rs2.rbegin());
		rs2.erase(rs2.find(*rs2.rbegin()));
	}
	ll tans = sum;
	for(int i = A+1;i<=A+B;i++){
		if(rs2.find(arr[i].sc) != rs2.end()){
			rs2.erase(rs2.find(arr[i].sc));
		}
		else{
			sum -= arr[i].sc;
			rs1.erase(rs1.find(arr[i].sc));
		}
		ls.insert(arr[i].fs-arr[i].sc);
		sum += arr[i].fs;
		while(ls.size()>A){
			sum -= *ls.begin();
			ls.erase(ls.find(*ls.begin()));
		}
		while(rs1.size()>A+B-i){
			sum -= *rs1.begin();
			rs2.insert(*rs1.begin());
			rs1.erase(rs1.find(*rs1.begin()));
		}
		tans = max(tans,sum);
	}
	return tans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>A>>B>>C;
	assert(A+B+C == N&&A>0&&B>0&&C>0);
	for(int i = 1;i<=N;i++){
		cin>>arr[i].fs>>arr[i].sc>>brr[i];
		arr[i].fs -= brr[i];
		arr[i].sc -= brr[i];
	}
	/*
	cerr<<"A:";for(int i = 1;i<=N;i++)cerr<<arr[i]<<' ';cerr<<endl;
	cerr<<"B:";for(int i = 1;i<=N;i++)cerr<<brr[i]<<' ';cerr<<endl;
	cerr<<"C:";for(int i = 1;i<=N;i++)cerr<<crr[i]<<' ';cerr<<endl;

   */
	ans = calc();
	for(int i = 1;i<=N;i++)ans += brr[i];
	cout<<ans;
	return 0;
}
