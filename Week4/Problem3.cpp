// Find intersection of two sorted arrays


#include<bits/stdc++.h>

using namespace std;

void solve(void){

    int n;

    cin>>n;

    int a[n];

    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    int m;

    cin>>m;

    int b[m];


    for(int i=0;i<m;++i){
        cin>>b[i];
    }

    vector<int>ans;


    int i=0,j=0;

    while(i<n && j<m){

        if(a[i]<b[j]){

            ++i;
        }

        else if(a[i]>b[j]){

            ++j;
        }
        else if(a[i]==b[j]){
            ans.push_back(a[i]);
            ++i;
            ++j;
        }
    }


    for(auto it:ans){
        cout<<it<<' ';
    }

    cout<<'\n';

}

int main(){

    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }
}
