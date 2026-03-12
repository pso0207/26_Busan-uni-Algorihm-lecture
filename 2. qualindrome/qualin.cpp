/* AI Usage
Compared to the difference, only one letter of the eyes,
and skip one of the first half of the first half of the snow,
and missed a half of the next door.Using Gemini,
it was fixed to completely judge the remaining
string of the remaining string of the remaining string of the remaining string of the left.
*/
#include <iostream>
#include <string>

using namespace std;

int is_qualindrome(string s)
{
    int len = s.length();
    int right = len - 1;
    int mid = right / 2;
    bool check = false;

    for (int left = 0; left < right; left++)
    {
        if (s[left] != s[right])
        {
            if (check == false)
            {
                check = true;

                bool left_check = true;
                for (int l = left + 1, r = right; l < r; l++, r--)
                {
                    if (s[l] != s[r])
                    {
                        left_check = false;
                        break;
                    }
                }

                bool right_check = true;
                for (int l = left, r = right - 1; l < r; l++, r--)
                {
                    if (s[l] != s[r])
                    {
                        right_check = false;
                        break;
                    }
                }

                if (left_check || right_check)
                {
                    break;
                }
                else
                {
                    return 3;
                }
            }
            else
            {
                return 3;
            }
        }
        else
            right--;
    }

    if (check == false)
        return 1;
    else
        return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        int result = is_qualindrome(s);
        switch (result)
        {
        case 1:
            cout << "1\n";
            break;
        case 2:
            cout << "2\n";
            break;
        case 3:
            cout << "3\n";
            break;
        }
    }
}