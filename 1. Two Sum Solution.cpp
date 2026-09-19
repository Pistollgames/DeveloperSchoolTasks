// Данное в задаче число состоит из суммы двух других. Зная одно, можно найти другое.
// Первое я получаю перебором, а второе, вычитая из целевого первое. 
// Если оно существует в массиве, что я проверяю бинарным поиском, то остаётся только найти индексы обоих чисел. 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        for (int i = sortedNums.size() - 1; i > 0; i--){
            int rest = target - sortedNums[i];
            if (binary_search(sortedNums.begin(), sortedNums.end(), rest))
                {
                    vector<int> result;
                    for (int j = 0; j < nums.size(); j++){
                        if (nums[j] == rest)
                            result.push_back(j);
                        else if(nums[j] == sortedNums[i])
                            result.push_back(j);
                    }      
                    return result;
                }
        }
        return {0, 0};
    }
};