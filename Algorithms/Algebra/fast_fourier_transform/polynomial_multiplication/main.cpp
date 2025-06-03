/**
 *  @param a first polynomial coefficients
 *  @param b second polynomial coefficients
 *  @return product of two polynomials
 *  @brief Multiplies two polynomials
 *  Time Complexity: O(n log n)
*/
vll multiply(vll const& a, vll const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vll result(n, 0);
    for (ll i = 0; i < n; i++) {
        result[i] += round(fa[i].real());
        if(result[i] >= 10) {
            result[i+1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    return result;
}