// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_A

#include <vector>

template <typename T>
void insertionSort(vector<T> &A)
{
    print(A);
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        T v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A);
    }
}
