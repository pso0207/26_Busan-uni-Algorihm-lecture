#include <iostream>
#include "oil.h"

using namespace std;

int find_start(int low, int high)
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        int result = observe(low, mid);

        if (result == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int find_end(int low, int high)
{
    while (high > low)
    {
        int mid = (low + high) / 2;
        if (observe(mid + 1, high) == 0)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initial();

    int cellN = oil_size();

    int start = 0;
    int end = cellN - 1;
    start = find_start(start, end);
    end = find_end(start, end);
    oil_report(start, end);
    return 0;
}
