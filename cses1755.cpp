#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[26] = {0};
    int n = s.size();
    for(int i =0;i<n;i++){
        arr[s[i]-'A']++;
    }
    string ans="";
    char center = '#';
    for(int i =0;i<26;i++){
        if(arr[i]&1){
            if(center == '#'){
                center = 'A'+i;
                arr[i]--;
                i--;
            }
            else{
                cout<<"NO SOLUTION";
                return 0;
            }
        }
        else for(int j =0;j<arr[i]/2;j++)ans += 'A'+i;
    }
    if(center != '#')ans += center;
    if(center == '#')n = ans.size()-1;
    else n=ans.size()-2;
    //cout<<n<<endl;
    for(int i = n;i>=0;i--)ans += ans[i];
    cout<<ans;
}
