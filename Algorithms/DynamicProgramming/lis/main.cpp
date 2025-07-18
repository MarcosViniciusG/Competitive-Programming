vector<int> LIS(int N, const vector<int>& xs)
{
    vector<int> lis(N, 1), ps(N, -1);

    for(int i = 1; i < N; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(xs[i] > xs[j] and lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                ps[i] = j;
            }
        }
    }

    int best = 0, k = -1;

    for(int i = 0; i < N; i++)
    {
        if(lis[i] > best)
        {
            best = lis[i];
            k = i;
        }
    }

    vector<int> ans;

    do
    {
        ans.emplace_back(xs[k]);
        k = ps[k];
    } while(k != -1);

    reverse(ans.begin(), ans.end());

    return ans;
}