#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;

#define p1(a) cout << a << "\n"
#define p2(a, b) cout << a << " " << b << "\n"

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FR(i, a) for (int i = 0; i < a; i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define FRd(i, a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int cache[200000];
//(length,endingIndex)
pair<int, int> longestSubarray(vector<int> a, int s, int ind, int bLen)
{
    // cout<<"s "<<s<<" ind "<<ind<<endl;

    if (s == 0)
    {
        // cout<<"returning"<<endl;
        int count = 0;
        for (int i = ind; i < a.size(); i++)
        {
            if (a[i] != 0)
            {
                break;
            }
            count++;
        }
        return make_pair(bLen + count, ind + count);
    }
    else if (ind >= a.size())
    {
        // cout<<"returning2"<<endl;
        return make_pair(-1, 0);
    }
    else if (s < 0)
    {
        // cout<<"returning3"<<endl;
        return make_pair(-1, 0);
    }

    // if (cache[ind * 2] != -2)   //Cacbhing is not correct
    // {
    //     cout << "returning cache" << endl;
    //     return make_pair(cache[(ind * 2)], cache[(ind * 2) + 1]);
    // }
    // cout<<"s "<<s<<" ind "<<ind<<endl;

    pair<int, int> val1 = make_pair(0, 0);
    pair<int, int> val2 = make_pair(0, 0);
    val1 = longestSubarray(a, s - a[ind], ind + 1, bLen + 1); //including it
    val2 = longestSubarray(a, s, ind + 1, 0);

    pair<int, int> ans;
    if ((val1.first >= val2.first))
    {
        ans = val1;
    }
    else
    {
        ans = val2;
    }
    if (cache[ind * 2] == -2)
    {
        cache[ind * 2] = ans.first;
        cache[(ind * 2) + 1] = ans.second;
    }
    // else if(cache[ind*2]<ans.first){
    // cache[ind*2] = ans.first;
    // cache[(ind*2) +1] = ans.second;
    // }

    return ans;
}

vector<int> findLongestSubarrayBySum(int s, vector<int> arr)
{

    for (int i = 0; i < 200000; i++)
    {
        cache[i] = -2;
    }
    pair<int, int> ans = longestSubarray(arr, s, 0, 0);
    if (ans.first == -1)
    {
        return {-1};
    }
    else
    {
        return {ans.second - ans.first + 1, ans.second};
    }

    // vector<int> ans = {-1};

    // return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        // solveCase();
    }
    return 0;
}

vector<int> findLongestSubarrayBySumOn(int s, vector<int> arr)
{

    // for(int i =0;i<200000;i++){
    //     cache[i]=-2;
    // }

    vector<int> prefixSum;
    prefixSum.push_back(0);

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum.push_back(prefixSum[i - 1] + arr[i]);
    }

    int left = prefixSum[0], right = prefixSum[1];

    vector<vector<int>> maxSum;

    while (right < prefixSum.size())
    {

        int rangeSum = (prefixSum[right] - prefixSum[left]);

        if ((rangeSum) == s)
        {
            maxSum.push_back({right - left, left, right});
        }

        if (rangeSum <= s)
        {
            right++;
        }
        else
        {
            left++;
        }
    }

    int maxLength = 0;
    int maxInd = 0;
    for (int i = 0; i < maxSum.size(); i++)
    {
        if (maxSum[i][0] > maxLength)
        {
            maxLength = maxSum[i][0];
            maxInd = i;
        }
    }

    if (maxLength == 0)
    {
        return {-1};
    }
    else
    {
        return {maxSum[maxInd][1], maxSum[maxInd][2]};
    }
}

vector<int> findLongestSubarrayBySumOptimized(int s, vector<int> arr)
{

    // for(int i =0;i<200000;i++){
    //     cache[i]=-2;
    // }

    vector<int> prefixSum;
    prefixSum.push_back(0);

    for (int i = 1; i <= arr.size(); i++)
    {
        prefixSum.push_back(prefixSum[i - 1] + arr[i - 1]);
    }

    for (int i = 0; i < prefixSum.size(); i++)
    {
        // cout<<prefixSum[i]<<" ";
    }

    int left = 0, right = 1;

    vector<vector<int>> maxSum;

    while (right < prefixSum.size())
    {

        int rangeSum = (prefixSum[right] - prefixSum[left]);

        // cout<<"rangeSum: "<<rangeSum<<endl;
        if ((rangeSum) == s)
        {
            maxSum.push_back({right - left, left, right});
        }

        if (rangeSum <= s)
        {
            right++;
        }
        else
        {
            left++;
        }
    }

    int maxLength = 0;
    int maxInd = 0;
    for (int i = 0; i < maxSum.size(); i++)
    {
        if (maxSum[i][0] > maxLength)
        {
            maxLength = maxSum[i][0];
            maxInd = i;
        }
    }

    if (maxLength == 0)
    {
        return {-1};
    }
    else
    {
        return {maxSum[maxInd][1] + 1, maxSum[maxInd][2]};
    }
}
