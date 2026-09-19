//Пояснение слишком большое, чтобы я мог оставить его здесь. Оно находится в документе со всеми остальными.  

class Solution {
public:
    int numberOfSets(int n, int k) {
        long long result = (countFactorial(n + k - 1) * 
            modPow(countFactorial(2*k), mod - 2) % mod) * 
            modPow(countFactorial(n - k - 1), mod - 2) % mod;
        return result;
    }
private:
    const long long mod = 1000000000 + 7;
    vector<long long> factorials = { 1 };
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }
    long long countFactorial(int number){
        if (number == 0) return 1;
        for (int i = factorials.size(); i < number; i++){
            factorials.push_back(factorials[i - 1] * (i + 1) % mod);
        }
        return factorials[number - 1];
    }
};