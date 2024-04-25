#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

string diff(string a,string b){
	string re;
	int p = a.size()-1;
	for(int i = a.size()-1;i>=0;i--){
		if(a[i]>=b[i])re += '0'+(a[i]-b[i]);
		else{
			if(p>i)p = i-1;
			while(p>=0&&a[p]=='0')p--;
			a[p]--;
			assert(p>=0);
			for(int j = p+1;j<i;j++)a[j] ++;
			a[i] += 2;
			re += '0'+(a[i]-b[i]);
		}
	}
	while(re.size()>1&&re.back() == '0')re.pop_back();
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b,k;
	cin>>b>>a>>k;
	string big,small;
	big = string(a,'1')+string(b,'0'),small = "1"+string(b,'0')+string(a-1,'1');
	string val = diff(big,small);
	reverse(val.begin(),val.end());
	pair<int,int> range = {big.size()-a+1,big.size()-1};
	ll cnt = 0;
	for(auto &i:val)if(i == '1')cnt++;
	cout<<cnt<<endl;
	if(cnt<k){
		cout<<"No\n";
		return 0;
	}
	//cout<<big<<' '<<small<<' '<<val<<' '<<cnt<<endl;
	while(cnt>k){
		cnt--;
		swap(small[range.sc],small[range.fs-1]);
		range.fs--;
		range.sc--;
	}
	cout<<"Yes\n"<<big<<'\n'<<small;
}
