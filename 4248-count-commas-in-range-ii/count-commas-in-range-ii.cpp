class Solution {
public:
    long long countCommas(long long n) {
        long curr =1000;
        long res=0;
        while(curr <= n){
            res = res +(n-curr+1);
            curr = curr*1000;
        }
        return res;
    }
};