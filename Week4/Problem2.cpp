// Find any pair that sums upto given number


#include<bits/stdc++.h>

using namespace std;

void solve(void){

    int n;

    cin>>n;

    int arr[n];


    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    int sum;

    cin>>sum;


    sort(arr,arr+n);


    int i=0,j=n-1;

    bool found_pair=false;


    while(i<j){

        if(arr[i]+arr[j]==sum){

            cout<<arr[i]<<' '<<arr[j]<<", ";

            found_pair=true;

            ++i;

            --j;
        }
        else if(arr[i]+arr[j]<sum){
            ++i;
        }
        else{
            --j;
        }
    }

    if(!found_pair){
        cout<<"No pair Found";
    }

    cout<<'\n';

}

int main(){

    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    int test_cases;

    cin>>test_cases;

    while(test_cases--){
        solve();
    }
}
