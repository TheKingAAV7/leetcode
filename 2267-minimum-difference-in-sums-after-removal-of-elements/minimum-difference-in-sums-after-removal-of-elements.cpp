class Solution {
public:
long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    priority_queue<int> pq_l(begin(nums), begin(nums) + n);
    priority_queue<int, vector<int>, greater<int>> pq_r(begin(nums) + 2 * n, end(nums));
    long long sum_first = accumulate(begin(nums), begin(nums) + n, 0LL);
    long long sum_second = accumulate(begin(nums) + 2 * n, end(nums), 0LL); 
    vector<long long> diffs(n + 1);
    for (int i = n; i <= 2 * n; ++i) {
        diffs[i - n] = sum_first;
        if (pq_l.top() > nums[i]) {
            sum_first += nums[i] - pq_l.top();
            pq_l.pop();
            pq_l.push(nums[i]);
        }
    }
    for (int i = 2 * n - 1; i >= n - 1; --i) {
        diffs[i - n + 1] -= sum_second;
        if (pq_r.top() < nums[i]) {
            sum_second += nums[i] - pq_r.top();
            pq_r.pop();
            pq_r.push(nums[i]);
        }
    }
    return *min_element(begin(diffs), end(diffs));
}
};
