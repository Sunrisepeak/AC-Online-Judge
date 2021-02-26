class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers[0] == numbers.back()) return *min_element(numbers.cbegin(), numbers.cend());
        int p1 = 0, p2 = numbers.size() - 1;
        while (p1 < p2 - 1 && numbers[p1] >= numbers[p2]) {
            int mid = (p1 + p2) / 2;
            if (numbers[mid] > numbers[p2]) {
                p1 = mid;
            } else {
                p2 = mid;
            }
        }
        return numbers[p1] < numbers[p2] ? numbers[p1] : numbers[p2];
    }
};
