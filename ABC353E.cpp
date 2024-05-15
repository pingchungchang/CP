#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
struct node{
	int ch[26];
	int dp;
	node(){
		memset(ch,0,sizeof(ch));
		dp = 0;
	}
};
node trie[mxn*10];
int N;
string arr[mxn];
ll ans = 0;
int ppp = 0;
int rt = 0;

int newnode(){
	return ++ppp;
}

ll calc(string s){
	int now = rt;
	ll re = 0;
	for(auto &i:s){
		if(!trie[now].ch[i-'a'])break;
		now = trie[now].ch[i-'a'];
		re += trie[now].dp;
	}
	return re;
}
void add(string s){
	int now = rt;
	for(auto &i:s){
		if(trie[now].ch[i-'a'])now = trie[now].ch[i-'a'];
		else now = trie[now].ch[i-'a'] = newnode();
		trie[now].dp++;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0;i<N;i++)cin>>arr[i];
	rt = newnode();
	for(int i = 0;i<N;i++){
		ans += calc(arr[i]);
		add(arr[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
