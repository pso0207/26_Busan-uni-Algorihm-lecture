/* AI Usage : There was an error with some cases and to fix it, 
I fixed it to int -> long long through Gemini pro 3.1 version, and deleted the continue in case s was 0  */
#include <iostream>
#include <vector>
using namespace std;

pair<long long,long long> compare_cost(pair<long long,long long> a, pair<long long,long long> b)
{
    if(a.first > b.first) return b;
    if(b.first > a.first) return a;

    // if same cost
    if(a.second > b.second) return a;
    return b;
}

pair<long long,long long> make_cost(long long s, long long d, long long t, long long w, long long N)
{
    vector<int> tram(366,0);
    pair<long long, long long> cost[366]; // first : cost , second : count
    cost[0] = {0,0};
    for(int i =0; i < N; i++)
    {
        int day;
        cin >> day >> tram[day];
    }

    for(int i = 1; i <= 365; i++)
    {
        if(tram[i] == 0)
        {
            cost[i] = cost[i-1];
        }
        pair<long long, long long> opt1 = { cost[i-1].first + (tram[i] * s), cost[i-1].second + tram[i] }; // one 
        pair<long long, long long> opt2 = { cost[i-1].first + d, cost[i-1].second + 1 }; // day
        pair<long long, long long> opt3 = { cost[max(0, i-3)].first + t, cost[max(0, i-3)].second + 1 };// three days
        pair<long long, long long> opt4 = { cost[((i-1)/7)*7].first + w, cost[((i-1)/7)*7].second + 1 };// week

        cost[i] = compare_cost(opt1, opt2);
        cost[i] = compare_cost(cost[i],opt3);
        cost[i] = compare_cost(cost[i],opt4);
    }
    return cost[365];
}

int main()
{
    long long s, d, t, w;
    cin >> s >> d >> t >> w;
    int N;
    cin >> N;
    pair<long long,long long> result = make_cost(s,d,t,w,N);
    cout << result.first << " " << result.second << "\n";
    return 0;
}