// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_A

#include <vector>
template <typename T>
void insertionSort(vector<T> a)
{
    //print(a);
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        T v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        //print(a);
    }
}
