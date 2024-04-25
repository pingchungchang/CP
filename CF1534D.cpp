#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2022;
int n;
bitset<mxn> vis;
vector<int> ask(int k){
	cout<<"? "<<k<<endl;
	vector<int> re(n);
	for(auto &i:re)cin>>i;
	return re;
}

int main(){
	cin>>n;
	set<pii> st;
	auto v = ask(1);
	int cnt[2] = {};
	for(int i = 1;i<n;i++){
		cnt[v[i]&1]++;
		if(v[i] == 1)st.insert({0,i});
	}
	int tar = 0;
	if(cnt[1]<cnt[0])tar = 1;
	for(int i = 1;i<v.size();i++){
		if((v[i]&1) == (tar&1)){
			auto tmp = ask(i+1);
			for(int j = 0;j<n;j++){
				if(tmp[j] == 1){
					st.insert({min(i,j),max(i,j)});
				}
			}
		}
	}
	cout<<"!"<<endl;
	for(auto &i:st)cout<<i.fs+1<<' '<<i.sc+1<<endl;
	return 0;
}
