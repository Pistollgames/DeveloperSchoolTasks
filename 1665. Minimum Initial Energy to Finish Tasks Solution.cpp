//Пояснение слишком большое, чтобы я мог оставить его здесь. Оно находится в документе со всеми остальными. 

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& first, vector<int>& second) {
            return first[1] - first[0] < second[1] - second[0];
        });
        int energy = 0;
        for (int i = 0; i < tasks.size(); i++){
            energy = max(energy + tasks[i][0], tasks[i][1]);
        }
        return energy;
    }
};