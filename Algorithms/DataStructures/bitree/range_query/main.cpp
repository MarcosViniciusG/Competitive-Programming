/**
 * @brief BITree que permite a atualização em intervalos e 
 * buscas pontuais para somas de intervalos.
 * Complexidade de Tempo: O(log n) para atualizar e buscar
 * Complexidade de Memória: O(n)
 */
template<typename T>
class BITree {
private:
    vector<T> ts;
    ll M;
    T p(int n) { return n & (-n); }

public:
    BITree(ll n) : ts(n+1, 0), M(n+1) {} 

    T RSQ(int i, int j) {
        return RSQv(j) - RSQv(i-1);
    }

private:
    T RSQv(int i) {
        T sm=0;
        while(i >= 1) {
            sm += ts[i];
            i -= p(i);
        }
        return sm;
    }

public:
    void update(int i, T x) {
        while(i <= M) {
            ts[i] += x;
            i += p(i); 
        }
    }
};