#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	map<int,int> primes;
	vector<int> facs;
	for(int i = 1;i*i<=n;i++){
		if(n%i == 0){
			facs.push_back(i);
			if(i*i != n)facs.push_back(n/i);
		}
	}
	sort(facs.rbegin(),facs.rend());
	facs.erase(unique(facs.begin(),facs.end()),facs.end());
	facs.pop_back();
	bool flag = true;
	int c = 0;
	while(flag){
		flag = false;
		for(int i = 2;i*i<=n;i++){
			if(n%i == 0){
				primes[i]++;
				n/=i;
				flag = true;
				break;
			}
		}
	}
	if(n != 1)primes[n]++;
	vector<int> v;
	for(auto &i:primes)v.push_back(i.fs);
	if(v.size() == 1){
		for(auto &i:facs){
			cout<<i<<' ';
		}
		cout<<"\n0\n";
		return;
	}
	else if(v.size() == 2&&facs.size() == 3){
		for(auto &i:facs)cout<<i<<' ';cout<<'\n';
		cout<<"1\n";
		return;
	}
	else{
		vector<int> ans[v.size()];
		for(auto &i:facs){
			bool no = false;
			for(int j = 1;j<v.size();j++){
				if(v[j-1]*v[j] == i)no = true;
			}
			if(v[0]*v.back() == i)no = true;
			if(no)continue;
			for(int j = 0;j<v.size();j++){
				if(i%v[j] == 0){
					ans[j].push_back(i);
					break;
				}
				assert(j != v.size()-1);
			}
		}
		for(int i = 0;i<v.size();i++){
			for(auto &j:ans[i])cout<<j<<' ';
			if(i != v.size()-1)cout<<v[i]*v[i+1]<<' ';
		}
		if(v.size()>2)cout<<v.back()*v[0];
		cout<<"\n0\n";
		return;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
