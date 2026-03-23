/* AI Usage(Gemini 3)
Looking at P(t) = (1-t) * A + t * B inside the problem PDF,
I understood the problem-solving method theoretically in my head,
but I felt lost when trying to translate it into code.
So, I obtained skeleton code for all functions via Gemini and wrote the code.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
    double x, y, z;
};

double cal_distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

Point get_point(Point A, Point B, double t)
{ // P(t) = (1-t) * A +t * B
    return {(1 - t) * A.x + t * B.x, (1 - t) * A.y + t * B.y, (1 - t) * A.z + t * B.z};
}
double find_shortest(Point A, Point B, Point C, Point D, double t)
{
    Point p = get_point(A, B, t);
    double low = 0.0, high = 1.0;

    for (int i = 0; i < 100; i++)
    {
        double m1 = low + (high - low) / 3.0;  // 1/3지점
        double m2 = high - (high - low) / 3.0; // 2/3지점

        if (cal_distance(p, get_point(C, D, m1)) < cal_distance(p, get_point(C, D, m2)))
            high = m2; // m1 지점에서의 거리가 더 가까우면 오른쪽 1/3을 버림
        else
            low = m1;
    }
    return cal_distance(p, get_point(C, D, low));
}
double solve()
{
    Point A, B, C, D;
    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;
    cin >> C.x >> C.y >> C.z;
    cin >> D.x >> D.y >> D.z;

    double low = 0, high = 1.0;
    for (int i = 0; i < 100; i++)
    {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;

        if (find_shortest(A, B, C, D, m1) < find_shortest(A, B, C, D, m2))
            high = m2;
        else
            low = m1;
    }
    return find_shortest(A, B, C, D, low);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double result = solve();
    cout << static_cast<int>(ceil(result)) << "\n";
    return 0;
}