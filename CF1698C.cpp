#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	set<int> st;
	vector<int> pos,neg;
	int z = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
		if(k>0)pos.push_back(k);
		else if(k<0)neg.push_back(k);
		else z++;
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	if(pos.size()>2||neg.size()>2){
		cout<<"NO\n";
		return;
	}
	if(z>0){
		pos.push_back(0);
		z--;
	}
	for(auto i:neg)pos.push_back(i);
	for(int i = 0;i<pos.size();i++){
		for(int j = i+1;j<pos.size();j++){
			for(int k = j+1;k<pos.size();k++){
				if(st.find(pos[i]+pos[j]+pos[k]) == st.end()){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

