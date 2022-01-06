#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
public:
    SegmentTree(const vector<long long>& num):size(num.size()){
        d = new long long[size*4];
        build(1, size-1, num, 1);
        b = new long long[size*4];
        memset(b, 0, sizeof(b));
    }
    
    void update(int s, int t, int l, int r, int p, const int c){
        //[l,r]为更新区间，[s,t]为当前区间
        if(l <= s && t <= r){
            d[p] += c*(t-s+1);
            b[p] += c;
            return;
        }
        
        int m = s + ((t-s)>>1);
        if(b[p] && s != t){
            d[p*2] += b[p]*(m-s+1), d[p*2+1] += b[p]*(t-m);
            b[p*2] = b[p], b[p*2+1] = b[p];
            b[p] = 0;
        }
        
        if(l <= m) update(s, m, l, r, p*2, c);
        if(r > m) update(m+1, t, l, r, p*2+1, c);
        d[p] = d[p*2] + d[p*2+1];
    }
    
    long long query(int s, int t, int l, int r, int p){
        if(l <= s && t <= r){
            return d[p];
        }
        
        int m = s + ((t-s)>>1);
        if(b[p] && s != t){
            d[p*2] += b[p]*(m-s+1), d[p*2+1] += b[p]*(t-m);
            b[p*2] = b[p], b[p*2+1] = b[p];
            b[p] = 0;
        }
        
        long long sum = 0;
        if(l <= m) sum += query(s, m, l, r, p*2);
        if(r > m) sum += query(m+1, t, l, r, p*2+1);
        return sum;
    }
    
    void build(int s, int t, const vector<long long>& num,int p){
        if(s == t){
            d[p] = num[s];
            return;
        }
        int m = s + ((t-s)>>1);
        build(s, m, num, p*2);
        build(m+1, t, num, p*2+1);
        d[p] = d[p*2] + d[p*2+1];
    }
    
    ~SegmentTree(){
        delete[] d;
        delete[] b;
    }
private:
    long long *d;
    long long *b;
    int size;
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<long long> nums(m + 1);
    for(int i = 1; i <= m; ++i){
        cin >> nums[i];
    }
    
    SegmentTree st(nums);
    
    for(int i = 0;i < n;++i){
        int op;
        cin >> op;
        int x, y, c;
        if(op == 1){
            cin >> x >> y >> c;
            st.update(1, m, x, y, 1, c);
        }else if(op == 2){
            cin >> x >> y;
            cout << st.query(1, m, x, y, 1) << endl;
        }
    }
    
    return 0;
}
