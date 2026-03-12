/*
   AI usage
   Since I couldn't get a feel for the solution, I used Gemini to reference the content on finding BP (Breaking Point)
   and creating a function that determines one or two based on the number of BPs.
   I also used Gemini to write the code for removing duplicates in the find_Bp function and for putting both num[z+1] and num[z] into bp.
   I wrote the rest myself, thinking about the operating principles.
*/
// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void flip(int i, int k, int *num)
{
    while (i <= k)
    {
        if (i == k)
        {
            num[i] = -num[i];
            break;
        }
        num[i] = -num[i];
        num[k] = -num[k];
        swap(num[i++], num[k--]);
    }
}
vector<int> find_Bp(int k, int *num) // calculate how many BP is in
{
    vector<int> bp;
    if (num[1] != 1)
        bp.push_back(1);
    for (int z = 1; z < k; z++)
    {
        if (num[z + 1] != num[z] + 1)
        {
            bp.push_back(z);
            bp.push_back(z + 1);
        }
    }
    if (num[k] != k)
        bp.push_back(k);
    // delete duplication
    sort(bp.begin(), bp.end());
    bp.erase(unique(bp.begin(), bp.end()), bp.end());
    return bp;
}

bool is_Normal(int k, int *num)
{
    for (int i = 1; i <= k; i++)
        if (num[i] != i)
            return false;
    return true;
}

bool is_One(int k, int *num, vector<int> &bp)
{
    for (int i = 0; i < bp.size(); i++)
    {
        for (int j = i; j < bp.size(); j++)
        {
            flip(bp[i], bp[j], num);
            if (is_Normal(k, num))
                return true;
            flip(bp[i], bp[j], num); // return original form
        }
    }
    return false;
}

bool is_Two(int k, int *num, vector<int> &bp)
{
    for (int i = 0; i < bp.size(); i++)
    {
        for (int j = i; j < bp.size(); j++)
        {
            flip(bp[i], bp[j], num);
            vector<int> new_bp = find_Bp(k, num);

            if (new_bp.size() <= 4 && is_One(k, num, new_bp))
                return true;
            flip(bp[i], bp[j], num);
        }
    }
    return false;
}

int main()
{
    // freopen("03.inp", "r", stdin);

    int k;
    cin >> k;
    int *num = new int[k + 1];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> num[j];
        }
        vector<int> bp = find_Bp(k, num);
        int bp_size = bp.size();

        if (bp_size > 8)
            cout << "over\n";
        else
        {
            if (is_One(k, num, bp))
                cout << "one\n";
            else if (is_Two(k, num, bp))
                cout << "two\n";
            else
                cout << "over\n";
        }
    }

    delete[] num;
}
