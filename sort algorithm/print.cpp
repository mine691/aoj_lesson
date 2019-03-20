//use for debug

template <typename T>
void print(vector<T> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << (i == n - 1 ? "\n" : " ");
    }
}
