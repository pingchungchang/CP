#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	ll sum = 0;
	for(auto &i:arr)cin>>i,sum+=i;
	if(sum%n != 0){
		cout<<"NO\n";
		return;
	}
	sum /= n;
	for(auto &i:arr)i = sum-i;//cout<<i<<' ';
	//cout<<endl;
	pii one[32];
	for(auto &i:one)i = {0,0};
	int cnt[32] = {};
	for(auto &i:arr){
		if(!i)continue;
		if(__builtin_popcount(abs(i)) == 1){
			int b = 0;
			for(;b<32&&!((1LL<<b)&i);b++);
			if(i>0){
				one[b].fs++;
			}
			else one[b].sc++;
			continue;
		}
		bool flag = false;
		for(int j = 0;j<30;j++){
			for(int k = 0;k<30;k++){
				if((1LL<<j)-(1LL<<k)+i == 0){
					cnt[j]--;
					cnt[k]++;
					flag = true;
					break;
				}
			}
		}
		if(!flag){
			cout<<"NO\n";
			return;
		}
	}
	/*
	for(int i = 0;i<10;i++)cout<<cnt[i]<<' ';cout<<endl;
	for(int i = 0;i<10;i++)cout<<one[i].fs<<','<<one[i].sc<<' ';cout<<endl;

   */
	for(int i = 0;i<30;i++){
		//fs:1,0 or -1,1;sc:-1,0 or 1,-1,a+b-,a-(fs-a)-b+(sc-b) = sc-fs+2a-2b,shift = fs-a-(sc-b) = fs-sc-(a-b)
		//cnt[i]+sc-fs+2a-2b = 0->2(a-b) = fs-sc-cnt[i]
		ll ab = (one[i].fs-one[i].sc-cnt[i]);
		if(abs(ab)%2 == 1){
			cout<<"NO\n";
			return;
		}
		if(ab>one[i].fs||ab<-one[i].sc){
			cout<<"NO\n";
			return;
		}
		ab/=2;
		ll sh = one[i].fs-one[i].sc-ab;
		//cout<<i<<":"<<cnt[i]<<','<<ab<<' '<<sh<<endl;
		cnt[i+1] += sh;
		cnt[i] = 0;
	}
	for(auto &i:cnt){
		if(i){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
