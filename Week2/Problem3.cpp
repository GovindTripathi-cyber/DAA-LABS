//: Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.

// Time Complexity : O(N*N)




#include <bits/stdc++.h>

using namespace std;


void solve(void){

	int n;

	cin>>n;


	vector<int>arr(n);


	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	int k;

	cin>>k;


	cout<<n<<' '<<k<<'\n';



	for(int i=0;i<n;++i)
		cout<<arr[i]<<' ';

    cout<<'\n';


	long long count=0;


	for(int i=0;i<n;++i){

		for(int j=0;j<n;++j){

			if((arr[i]-arr[j])==k){
				cout<<i<<' '<<j<<'\n';
				++count;
			}
		}
	}

	cout<<count<<'\n';



}

int main(){



	freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);

	int test_cases;

	cin>>test_cases;


	while(test_cases--){
		solve();
	}
}
