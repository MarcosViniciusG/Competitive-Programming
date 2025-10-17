/**
 * @brief BITree que permite atualizações pontuais e 
 * buscas para soma de intervalos.
 * Complexidade de Tempo: O(log n) para atualizar e buscar
 * Complexidade de Memória: O(n)
 */
template<typename T>
class BITree {
private:
    vector<T> ts;
    ll m;
    T p(T n) {return n & (-n);}

public:
    BITree(ll m) : ts(m+1, 0), m(m) {}

    T RSQ(ll i) {
        T sm = 0;
        while(i >= 1) {
            sm += ts[i];
            i -= p(i);
        }

        return sm;
    }

    void update(ll i, T delta) {
        while(i <= m) {
            ts[i] += delta;
            i += p(i);
        }
    }

    void range_update(ll a, ll b, T delta) {
        update(a, delta);
        update(b+1, -delta);
    }
};
