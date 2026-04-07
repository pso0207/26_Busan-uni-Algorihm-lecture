/* AI Usage: Initially, I wrote the code with the 'count == k' condition. 
However, I realized that there are counterexamples 
where this fails to produce the correct result, so I changed it to 'count <= k'. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

vector<int> create_ch(int N, int k)
{
    vector<int> chapter(N);
    for(int i = 0; i < N; i++)
    {
        cin >> chapter[i];
    }
    return chapter;
}

int divide_ch(int N, int k , const vector<int>& ch)
{

    int Max_size = accumulate(ch.begin(), ch.end(), 0); 
    vector<int> max_list;
    
    for(int i = Max_size; i > 0; i--)
    {

        bool impossible = false;
        for(int p : ch) {
            if(p > i) impossible = true;
        }
        if(impossible) continue;

        vector<int> page;
        int sum = 0;
        int count = 0;
        
        for(auto& j : ch)
        {
            if(sum + j > i)
            {
                if(sum > 0) page.push_back(sum); 
                sum = j;
                count++;
            }
            else sum += j;
        }

        if(sum > 0)
        {
            page.push_back(sum);
            count++;
        }


        if(count <= k)
        {
            auto it = max_element(page.begin(), page.end());
            max_list.push_back(*it);
        }
    }

    if(max_list.empty()) return 0;

    auto max_page = min_element(max_list.begin(), max_list.end());
    return *max_page;
}

int main()
{
    int N, k;

    while(cin >> N >> k) 
    {
        vector<int> ch = create_ch(N,k);
        int result = divide_ch(N,k,ch);
        cout << result << "\n";
    }
}