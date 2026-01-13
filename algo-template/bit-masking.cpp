#include <iostream>

using namespace std;

const int n = 4;
int main()
{
    string arr[n] = {"1", "2", "3", "4"};

    for (int i = 0; i < (1 << n); i++)
    {
        string ret = "";

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                ret += arr[j] + " ";
        }
        cout << ret << "\n";
    }
}

/*
    -> 공집합 포함
1
2
1 2
3
1 3
2 3
1 2 3
4
1 4
2 4
1 2 4
3 4
1 3 4
2 3 4
1 2 3 4
*/