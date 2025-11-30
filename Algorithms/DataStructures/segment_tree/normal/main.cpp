// Indexada em 0, [a, b]
class Segtree{
  private: 
    ll N; 
    vector<ll> ts;  
  public: 
    // o 0 eh elemento neutro da soma
    Segtree(size_t n) : N(n), ts(4*n, 0) {} 
    ll query(ll ql, ll qr){
      return query_range(ql, qr, 0, N-1, 1); 
    }
    void update(ll i, ll v){
      return update_range(i, v, 0, N-1, 1); 
    }
  private: 
    ll query_range(ll ql, ll qr, ll l,ll r, ll no){
      if(l >= ql && r <= qr) return ts[no]; 
      if(l > qr || r < ql) return 0;     
      ll mid = (l+r)/2; 
      ll esq = query_range(ql, qr, l, mid, 2*no); 
      ll dir = query_range(ql, qr, mid+1, r, 2*no+1);
      return merge(esq, dir);  
    } 
    void update_range(ll i, ll v, ll l, ll r, ll no){
      if(l==r){
        ts[no] = v; 
        return; 
      } 
      ll mid = (l+r)/2; 
      if(i<=mid) update_range(i, v, l, mid, 2*no); 
      else update_range(i, v, mid+1, r, 2*no+1);
      ts[no] = merge(ts[2*no], ts[2*no+1]);  
    } 
    ll merge(ll a, ll b){
      return a+b; 
    }
}; 