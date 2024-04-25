#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>n;
        int chaos = 0;
        unordered_map<int,int> numtoplace;
        vector<int> v;
        for(int j = 0;j<n;j++){
            int s;
            cin>>s;
            v.push_back(s);
            numtoplace[s] = i;
            if(v[i] - i>2){
                chaos = 1;
                break;
            }
        }
        int ans = 0;
        if(chaos !=1){
            int moved = 0;
            for(int j = v.size()-1;j>=0;j++){
                if(j-nummtoplace[j]-moved <0) cout<<"wrong algorithm";
                ans += j - numtoplace[j]-moved;

            }
            cout<<ans<<"\n";
        }
        else{
            cout<<"too chaotic"<<"\n";
        }

    }
}


//fail
//fail
