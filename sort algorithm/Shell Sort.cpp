//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_2_D
//n^1.25

template <typename T>
void insertionSort(vector<T> &A, int g, int &cnt)
{
    int n = A.size();
    for (int i = g; i < n; i++)
    {
        int v = A[i], j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j], j = j - g, cnt++;
        }
        A[j + g] = v;
    }
}

template <typename T>
void shellSort(vector<T> &A, int &cnt)
{
    cnt = 0;
    int n = A.size();
    vector<int> G;
    G.push_back(1);
    while (3 * G.back() + 1 < n)
    {
        G.push_back(3 * G.back() + 1);
    }
    int m = G.size();
    for (int i = m - 1; i >= 0; i--)
    {
        insertionSort(A, G[i], cnt);
    }
}
