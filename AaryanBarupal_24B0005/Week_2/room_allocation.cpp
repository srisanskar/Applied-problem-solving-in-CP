#include<bits/stdc++.h>
using namespace std;
struct Customer{
    int arrival,departure,index;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<Customer>customers(n);
    for(int i=0;i<n;i++){
        cin>>customers[i].arrival>>customers[i].departure;
        customers[i].index=i;
    }
    sort(customers.begin(),customers.end(),[](const Customer&a, const Customer&b){
        return a.arrival<b.arrival;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int room_count=0;
    vector<int>room_assignment(n);
    for(const auto& individual:customers){
        if(!pq.empty() && pq.top().first<individual.arrival){
            int free_time=pq.top().first;
            int room_no=pq.top().second;
            pq.pop();
            pq.push(make_pair(individual.departure,room_no));
            room_assignment[individual.index]=room_no;
        }
        else{
            ++room_count;
            pq.push(make_pair(individual.departure,room_count));
            room_assignment[individual.index]=room_count;
        }
    }
    cout<<room_count<<'\n';
    for(int r: room_assignment){
        cout<<r<<" ";
    }
    cout<<'\n';
}