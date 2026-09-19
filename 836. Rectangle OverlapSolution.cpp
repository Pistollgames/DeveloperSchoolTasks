//Я решил смотреть на проекции точек каждого прямоугольника по осям.
//После наблюдений за ними, я заметил, что если отрезки через точки одного прямоугольника и другого не пересекаются,
// то и сами прямоугольники тоже. Это и проверяет код.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (isOneRectangleOverlap(rec1, rec2) || isOneRectangleOverlap(rec2, rec1))
            return false;
        return true;
    }
private:
    bool isOneRectangleOverlap(vector<int>& rec1, vector<int>& rec2){
        return rec1[2] <= rec2[0] || rec1[3] <= rec2[1];
    }
};