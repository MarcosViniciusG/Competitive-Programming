/**
 *  @param a first multiplier
 *  @param b second multiplier
 *  @param mod
 *  @return a * b mod n (without overflow) 
 *  @brief Multiplies two numbers >= 10^18
 *  Time Complexity: O(log b)
*/
ll mult(ll a, ll b, ll mod) {
    ll result = 0;
    while (b) {
        if (b & 1)
            result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

/**
 *  @param x first multiplier
 *  @param c second multiplier
 *  @param mod 
 *  @return f(x) = x^2 + c mod (mod)
 *  @brief Polynomial function chosen for pollard's rho
 *  Time Complexity: O(1)
*/
ll f(ll x, ll c, ll mod) {
    return (mult(x, x, mod) + c) % mod;
}

/**
 *  @param n number that we want to find a factor p
 *  @param x0 number where we will start
 *  @param c constant in polynomial function
 *  @return fac
 *  @brief Pollard's Rho algorithm (works only for composite numbers)
 *  if(g==n) try other starting values
 *  Time Complexity: O(n^(1/4) log n)
*/
ll rho(ll n, ll x0=2, ll c=1) {
    ll x = x0;
    ll y = x0;
    ll g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}