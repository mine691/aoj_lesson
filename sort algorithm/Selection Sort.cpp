//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_2_B

#include <vector>

//cnt:sawpの回数
template <typename T>
void selectionSort(vector<T> &A, int &cnt)
{
    int n = A.size();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minj])
                minj = j;
        }
        cnt += (A[i] != A[minj]);
        swap(A[i], A[minj]);
    }
}
