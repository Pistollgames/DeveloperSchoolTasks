//Пояснение слишком большое, чтобы я мог оставить его здесь. Оно находится в документе со всеми остальными. 

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int distance = 0;
        rep.resize(source.size());
        members.assign(source.size(), {});
        for (int i = 0; i < source.size(); i++) {
            rep[i] = i;
            members[i] = {i};
        }
        for (auto swap : allowedSwaps){
            int first = rep[swap[0]], second = rep[swap[1]];
            if (first == second) continue;  
            if (members[first].size() < members[second].size()) 
                std::swap(first, second);
            for (int value : members[second]) {
                rep[value] = first;
                members[first].push_back(value);
            }
            members[second].clear();
        }
        vector<unordered_map<int,int>> stock(source.size());
        for (int i = 0; i < source.size(); i++){
            int root = rep[i];
            if (stock[root].empty()) {
                for (auto value : members[root])
                    stock[root][source[value]]++;
            }
            auto it = stock[root].find(target[i]);
            if (it != stock[root].end() && it->second > 0) { 
                it->second--;
                distance--;
            }
            distance++;
        }
        return distance;
    }
private:
    vector<int> rep;
    vector<vector<int>> members;
};