#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	vector<int> st;
	int one = 0;
	for(auto &i:s){
		if(i == '+'){
			st.push_back(2);
		}
		else if(i == '-'){
			if(st.back() == 1)one--;
			st.pop_back();
		}
		else if(i == '0'){
			if(st.size()<=1){
				cout<<"NO\n";
				return;
			}
			if(!one){
				if(st.back() == 0){
					cout<<"NO\n";
					return;
				}
				st.back() = 1;
				one++;
			}
		}
		else if(i == '1'){
			if(one){
				cout<<"NO\n";
				return;
			}
			for(int i = (int)st.size()-1;i>=0&&st[i] == 2;i--){
				st[i] = 0;
			}
		}
	}
	cout<<"YES\n";
	return;
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
