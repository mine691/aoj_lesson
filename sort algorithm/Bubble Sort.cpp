//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_2_A
//

#include <vector>

//cnt:sawpの回数
template <typename T>
void bubbleSort(vector<T> &A, int &cnt)
{
    int n = A.size();
    bool flag = true;
    cnt = 0;
    while (flag)
    {
        flag = false;
        for (int i = 0; i + 1 < n; i++)
        {
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                flag = true, cnt++;
            }
        }
    }
}

template <typename T>
void BubbleSort(vector<T> &C, int &cnt)
{
    int n = C.size();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= i; j--)
        {
            if (C[j] > C[j + 1])
            {
                swap(C[j], C[j + 1]);
                cnt++;
            }
        }
    }
}
