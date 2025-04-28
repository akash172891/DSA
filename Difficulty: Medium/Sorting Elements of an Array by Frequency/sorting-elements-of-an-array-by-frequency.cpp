#include<bits/stdc++.h>
using namespace std;

#define llu long long int
#define ll long long
#define ull unsigned long long int

#define f(i,a,b) for(int i=a;i=a;j--)
#define fr2(j,a,b) for(ll j=b-1;j>=a-1;j--)
#define vll vector
#define vi vector

#define pi pair 
#define pll pair 

#define si set 
#define sll set 

#define mii map
#define mvi map

#define wl while
#define e "\n"
#define spc " "
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define sz(a) a.size()

#define vsort(a) sort(a.begin(),a.end())
#define vdsort(a) sort(a.begin(),a.end(),greater< llu >())
#define vrsort(a) sort(a.rbegin(),a.rend())

#define as() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define tc() int t;cin>>t;wl(t--)
#define get(a,n) vll a(n); f(i,0,n) cin>>a[i]



 
int main() {
    int t;
    cin>>t;
    while(t--){
    int n ;
    cin>>n;
    int nums[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    for(int i =0;i<n;i++){
        mp[nums[i]]++;
    }
    
    priority_queue<pair<int,int>> pq;
    
    for(auto x : mp){
        pq.push({x.second,-1*x.first});
    }
    
    while(pq.size()){
        for(int i=0;i<pq.top().first;i++){
        cout<<pq.top().second*-1<<" ";
        }
        pq.pop();
    }
    cout<<endl;
        
    }
    
return 0;
}

