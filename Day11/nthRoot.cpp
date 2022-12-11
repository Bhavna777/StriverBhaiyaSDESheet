// Problem Link :- https://www.codingninjas.com/codestudio/problems/1062679 




double power(double m, int n) {
    double ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans *= m;
            n--;
        }
        m *= m;
        n /= 2;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
    double start = 0;
    double end = m;
    double eps = 1e-7;
    
    while ((end - start) > eps) {

        double mid = (start + end) / 2;
        double exp = power(mid, n);
        if (exp < m) {
            start = mid;
        }else {
            end = mid;
        }
    }

    return start;
}
