#include <iostream>
#include <vector>

using namespace std;

namespace
{
    string s;
    int n;
    vector<int> a;
    int Q = 0;
};


int query(int l, int r)
{
    Q++;
    if (r <= l)
        return -1;
    if (l < 0)
        return -1;
    if (r >= n)
        return -1;
    int sum = 0;
    for (int i = l; i <= r; i++)
        sum += a[i];
    return sum;
}
std::vector<int> revert(int n){
	std::vector<int> ans(n,0);
	for(int i = n-1;i>=1;i--){
		ans[i] = query(0,i);
	}
	int tmp = query(1,2);
	ans[0] = ans[2]-tmp;
	for(int i = n-1;i>=1;i--){
		ans[i] = ans[i]-ans[i-1];
	}
	return ans;
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto ouf = revert(n);
    if (ouf == a)
        std::cout << "Accpted: Used " << Q << " query(ies)\n";
    else
        std::cout << "Wrong Answer\n";
}

