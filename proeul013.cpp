#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while(a.size()<b.size())a += '0';
	while(b.size()<a.size())b += '0';
	a+='0';
	b += '0';
	string re(a.size(),'0');
	int car = 0;
	for(int i = 0;i<a.size();i++){
		int tmp = a[i]-'0'+b[i]-'0'+car;
		re[i] = '0'+tmp%10;
		car = tmp/10;
	}
	while(re.back() == '0')re.pop_back();
	reverse(re.begin(),re.end());
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	string in;
	vector<string> nums;
	while(cin>>in){
		nums.push_back(in);
	}
	string sum = "0";
	for(int i = 0;i<nums.size();i++){
		sum = add(sum,nums[i]);
	}
	cout<<sum<<endl;
	cout<<sum.substr(0,10)<<endl;
}
