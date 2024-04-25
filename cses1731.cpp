#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9+7;
struct node{
	node* childs[26];
	bool isend;
	char val;
	node(){
		val = '#';
		memset(childs,0,sizeof(childs));
		isend = 0;
	}
	node(char c){
		val = c;
		memset(childs,0,sizeof(childs));
		isend = 0;
	}
};
string tmp;
node* trie = new node(' ');
void build(){
	node* now = trie;
	for(auto i:tmp){
		if(now->childs[i-'a'] == 0){
			now->childs[i-'a'] = new node(i-'a');
		}
		now = now->childs[i-'a'];
	}
	now->isend = true;
	return;
}
int main(){
	string s;
	cin>>s;
	int n = s.size();
	int k;
	cin>>k;
	ll dp[n+1];
	memset(dp,0LL,sizeof(dp));
	for(int i = 0;i<k;i++){
		cin>>tmp;
		reverse(tmp.begin(),tmp.end());
		build();
	}
	dp[0] = 1;
	for(int i = 0;i<n;i++){
		node* now = trie;
		for(int j = i;j>=0;j--){
			if(now->childs[s[j]-'a'] != 0){
				now = now->childs[s[j]-'a'];
			}
			else break;
			if(now->isend == true){
				dp[i+1] = (dp[i+1]+dp[j])%mod;
			}
		}
	}
	cout<<dp[n];
}

