#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define X first
#define Y second
#define pb push_back
const ll MAXn=3e5+5, INF=ll(2e5);
const double EPS = 1e-11;
const int UP = 0, DOWN = 1, IN = 0, VERT = 1, OUT = 2;
struct seg{
    ii l, r;
    ll id, tp;
    seg(ii li = ii(0, 0), ii ri = ii(0, 0), ll idi = -1, ll tpi = -1):l(li), r(ri), id(idi), tp(tpi){}
    double operator () (ll x) const {
        assert(l.X <= x && r.X >= x);
        return l.Y + (r.Y - l.Y) * (x - l.X) / double(r.X - l.X);
    }
};
ii operator - (ii a, ii b){return ii(a.X - b.X, a.Y - b.Y);}
ll cros(ii a, ii b){return a.X * b.Y - a.Y * b.X;}
ll sign(ll x){return x < 0 ? -1 : x > 0;}
int inter(const seg &a, const seg &b){
    return sign(cros(b.l - a.l, a.r - a.l)) * sign(cros(b.r - a.l, a.r - a.l)) <= 0 && sign(cros(a.l - b.l, b.r - b.l)) * sign(cros(a.r - b.l, b.r - b.l)) <= 0 && a.id != b.id;
}
seg s[MAXn];
ll sit, srtx, h[MAXn], n, kz = 0;
struct stcmp {
    bool operator () (const seg &a, const seg &b) const{
        double ya = a(srtx), yb = b(srtx);
        if(fabs(ya - yb) > EPS)return ya < yb;
        else if(a.tp != b.tp)return a.tp > b.tp;
        else return make_tuple(a.l, a.r, a.id) < make_tuple(b.l, b.r, b.id);
    };
};
set<seg, stcmp> st;
vector<ii> dt;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin>>n && n != -1){
        kz ++;
        cout<<"Case "<<kz<<": ";
        sit = 0;
        st.clear(), dt.clear();
        REP1 (i,n) h[i] = -1;
        REP1 (i,n) {
            vector<ii> tmp;
            REP1(j, 3) {
                ll x, y;
                cin>>x>>y;
                tmp.pb(ii(x, y));
            }
            sort(tmp.begin(), tmp.end());
            ii a = tmp[0], b = tmp[1], c = tmp[2];
            ll ab = sit, ac = sit + 1, bc = sit + 2;
            sit += 3;
            s[ab] = seg(a, b, i), s[ac] = seg(a, c, i), s[bc] = seg(b, c, i);
            if (a.X == b.X) {
                s[ac].tp = DOWN, s[bc].tp = UP;
                dt.pb(ii(ab, VERT)), dt.pb(ii(bc, IN)), dt.pb(ii(ac, IN)), dt.pb(ii(bc, OUT)), dt.pb(ii(ac, OUT));
            } else if (b.X == c.X) {
                s[ac].tp = UP, s[ab].tp = DOWN;
                dt.pb(ii(bc, VERT)), dt.pb(ii(ab, IN)), dt.pb(ii(ac, IN)), dt.pb(ii(ab, OUT)), dt.pb(ii(ac, OUT));
            } else {
                if(seg(a, b)(b.X) > seg(a, c)(b.X))s[ab].tp = s[bc].tp = UP, s[ac].tp = DOWN;
                else s[ab].tp = s[bc].tp = DOWN, s[ac].tp = UP;
                dt.pb(ii(ab, IN)), dt.pb(ii(ac, IN)), dt.pb(ii(bc, IN)), dt.pb(ii(ab, OUT)), dt.pb(ii(ac, OUT)), dt.pb(ii(bc, OUT));
            }
        }
        sort(dt.begin(), dt.end(), [](ii &a, ii &b){
            ii pa = (a.Y == OUT ? s[a.X].r : s[a.X].l);
            ii pb = (b.Y == OUT ? s[b.X].r : s[b.X].l);
            return make_tuple(pa.X, a.Y, pa.Y) < make_tuple(pb.X, b.Y, pb.Y);
        });
        bool fg = 1;
        for(ii &p:dt) {
            srtx = (p.Y == OUT ? s[p.X].r.X : s[p.X].l.X);
            if (p.Y == OUT) {
                auto it = st.erase(st.lower_bound(s[p.X]));
                if(it != st.end() && it != st.begin() && inter(*it, *prev(it)))fg = 0;
            }
            else if (p.Y == IN) {
                auto it = st.insert(s[p.X]).X;
                if(it->tp == DOWN && h[it->id] == -1)h[it->id] = it == st.begin() ? 2 : h[prev(it)->id] + (prev(it)->tp == DOWN);
                if((it != st.begin() && inter(*it, *prev(it))) || (next(it) != st.end() && inter(*it, *next(it))))fg = 0;
            }
            else { // VERT 
                seg &d = s[p.X];
                if(st.lower_bound(seg(ii(-INF, d.l.Y + 1), ii(INF, d.l.Y + 1), -1, DOWN)) != st.lower_bound(seg(ii(-INF, d.r.Y), ii(INF, d.r.Y), -1, DOWN)))fg = 0;
            }
            if(!fg)break;
        }
        if (!fg) cout<<"ERROR\n";
        else {
            ll mx = 1;
            REP1(i,n)mx = max(mx, h[i]);
            cout<<mx<<" shades\n";
        }
    }
}