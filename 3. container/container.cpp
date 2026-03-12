#include <iostream>
#include "container.h"
#include <vector>

using namespace std;

vector<int> history[10005];

vector<int> Tournament(int N, vector<int> participant)
{
    vector<int> winner;
    for (int i = 0; i < N - 1; i += 2)
    {
        if (box_comp(participant[i], participant[i + 1]) > 0)
        {
            winner.push_back(participant[i]);
            history[participant[i]].push_back(participant[i + 1]);
        }
        else
        {
            winner.push_back(participant[i + 1]);
            history[participant[i + 1]].push_back(participant[i]);
        }
    }
    if (N % 2 == 1)
    {
        winner.push_back(participant.back());
    }
    return winner;
}

int main()
{
    int N, result, answer;

    box_ready();
    N = box_num();

    vector<int> participant;
    for (int i = 1; i <= N; i++)
    {
        participant.push_back(i);
    }

    while (participant.size() > 1)
    {
        participant = Tournament(participant.size(), participant);
    }

    int first_place = participant[0];
    vector<int> candidates = history[first_place];

    answer = candidates[0];
    for (int i = 1; i < candidates.size(); i++)
    {
        if (box_comp(candidates[i], answer) > 0)
        {
            answer = candidates[i];
        }
    }

    box_report(answer);

    return 0;
}