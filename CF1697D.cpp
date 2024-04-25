#include <bits/stdc++.h>
using namespace std;


vector<pair<int,char>> v;

char ask1(int p){
	cout<<"? 1 "<<p<<endl;
	char re;
	cin>>re;
	return re;
}

int ask2(int l,int r){
	cout<<"? 2 "<<l<<' '<<r<<endl;
	int re;
	cin>>re;
	return re;
}

int main(){
	int n;
	cin>>n;
	string ans = "";
	v.push_back({1,ask1(1)});
	ans += v[0].second;
	for(int i = 2;i<=n;i++){
		bool flag = false;
		int l = 0,r = max(0,(int)v.size()-1);
		while(l != r){
			int mid = (l+r)>>1;
			if(ask2(v[mid].first,i)== mid+2)l = mid+1;
			else r = mid;
		}
		if(l == v.size()-1){
			if(ask2(v[l].first,i) != v.size()+1){
				ans += v[l].second;
				v.push_back({i,ans.back()});
			}
			else{
				ans += ask1(i);
				v.push_back({i,ans.back()});
			}
		}
		else{
			ans += v[l].second;
			v.push_back({i,ans.back()});
		}
		sort(v.rbegin(),v.rend());
		auto tmp = v;
		tmp.clear();
		int done = 0;
		for(auto &i:v){
			if(done&(1<<(i.second-'a')))continue;
			done ^= 1<<(i.second-'a');
			tmp.push_back(i);
		}
		v = tmp;
	}
	cout<<"! "<<ans<<endl;
}
