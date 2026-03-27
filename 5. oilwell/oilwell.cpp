#include <iostream>
#include "oil.h" 

using namespace std;

int findStart(int low, int high)
{

}

int findEnd(int low, int high)
{
    
}

int main() {

    initial();

    int cellN = oil_size();
    
    int start = 0;
    int end = cellN-1;
    int mid = (start + end) /2;
    // 유정의 시작점 먼저 잡고 끝점 잡기
    oil_report(start, end);
    return 0;
}
