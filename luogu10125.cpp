#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(auto &i:s)if(i>='A'&&i<='Z')i = 'a'+(i-'A');
	cout<<(s == "svpoll"?"Genshin":s == "acoipp"?"Luogu":"Boring");
}
