class Solution {
public:
    double solve(double x,long n){
        if(n==0) return 1;
        
        if(n%2==0){
            return solve(x*x,n/2);
        }
       
         return x*solve(x*x,(n-1)/2);
        
    }
    double myPow(double x, int n) {
        long long power = n;
        if(power<0){
            return 1.0/solve(x,-power);
        }
        return solve(x,long(n));
    }
};