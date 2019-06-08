#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> II;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back

const int MAXn = 1e5+5;
const int INF = 2000000100;
const int R=0,U=1,L=2,D=3;

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

int ti[MAXn];

struct tg {ll id;int tp;ii d;};
vector<tg> vp;

namespace p1 {
struct val {ii mxr, mnl, bst;int dis;};
val operator+(val &a, val &b) {
  val ret = {max(a.mxr, b.mxr), min(a.mnl, b.mnl),
             (a.dis < b.dis ? a.bst : b.bst), min(a.dis, b.dis)};
  if (b.mnl.Y != -1 && a.mxr.Y != -1 && b.mnl.X - a.mxr.X < ret.dis)
    ret.dis = b.mnl.X - a.mxr.X, ret.bst = {a.mxr.Y, b.mnl.Y};
  return ret;
}

struct seg {
  int N, *mp, c;
  val *d, cache;
  seg(int n, vector<tg> &v) : N(n), mp(new int[n]), c(0), d(new val[2 * n]) {
    REP(i, n) mp[i] = v[i].d.Y;
    REP(i, n)
    if (v[i].tp == L)
      d[i + n] = {{-INF, -1}, {v[i].d.X, i}, {-1, -1}, INF};
    else
      d[i + n] = {{v[i].d.X, i}, {INF, -1}, {-1, -1}, INF};
    for (int i = n - 1; i > 0; i--) d[i] = d[i << 1] + d[i << 1 | 1];
  }
  val qr() {
    if (c) return cache;
    else c = 1;
    val retl, retr;
    retl = retr = {{-INF, -1}, {INF, -1}, {-1, -1}, INF};
    for (int l = N, r = N + N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) retl = retl + d[l++];
      if (r & 1) retr = d[--r] + retr;
    }
    return cache = retl + retr;
  }
  void rm(int x) {
    if(mp[x] == -1)return;
    c = 0;mp[x] = -1;
    d[x += N] = {{-INF, -1}, {INF, -1}, {-1, -1}, INF};
    for (; x > 1; x >>= 1)d[x >> 1] = ((x & 1) ? d[x ^ 1] + d[x] : d[x] + d[x ^ 1]);
  }
} * sg[6 * MAXn];
int sit = 0;

vector<ii> pmp[MAXn];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void solve() {
  sort(ALL(vp), [](auto &a, auto &b) { return a.id < b.id; });
  int vit = 0;
  while (vit < SZ(vp)) {
    int tit = vit;
    vector<tg> v;
    while (tit < SZ(vp) && vp[tit].id == vp[vit].id) v.pb(vp[tit]), tit++;
    vit = tit;
    bool fg = 0;
    REP(i, SZ(v) - 1)if(v[i].tp != v[i+1].tp)fg = 1;
    if (SZ(v) == 1 || !fg) continue;
    sort(ALL(v), [](auto &a, auto &b) { return a.d.X < b.d.X; });
    auto it = sg[++sit] = new seg(SZ(v), v);
    REP(i, SZ(v))pmp[v[i].d.Y].pb({sit, i});
    pq.push({it->qr().dis, sit});
  }
  while (1) {
    while (SZ(pq) && pq.top().X != sg[pq.top().Y]->qr().dis) pq.pop();
    if (!SZ(pq) || pq.top().X >= INF) return;
    ll td = pq.top().X;
    vector<ll> tmp;
    while (pq.top().X == td) {
      int it = pq.top().Y, tmpd = pq.top().X;
      pq.pop();
      if (sg[it]->qr().dis != tmpd) continue;
      int a = sg[it]->qr().bst.X, b = sg[it]->qr().bst.Y;
      tmp.pb(sg[it]->mp[a]), tmp.pb(sg[it]->mp[b]);
      ti[sg[it]->mp[a]] = ti[sg[it]->mp[b]] = td / 2;
      sg[it]->rm(a), sg[it]->rm(b);
      pq.push({sg[it]->qr().dis, it});
    }
    sort(ALL(tmp));
    tmp.resize(unique(ALL(tmp)) - tmp.begin());
    for (ll t : tmp)
      for (auto &p : pmp[t]) {
        int it = p.X;
        sg[it]->rm(p.Y);
        pq.push({sg[it]->qr().dis, it});
      }
  }
}
};

int x[MAXn], y[MAXn], dir[MAXn];

namespace p2 {
vector<ii> lr[MAXn], ud[MAXn];
int bit[MAXn];
void ins(int x, int k) {
  while (x < MAXn) bit[x] += k, x += x & -x;
}
int bqr(int x) {
  int ret = 0;
  while (x) ret += bit[x], x -= x & -x;
  return ret;
}
ll solve(ll n) {
  ll tt = 0;
  vector<int> uni, uni2;
  vector<pair<int, ii>> ch, qr;
  REP(i, n)
  if (dir[i] == L || dir[i] == R)uni.pb(y[i]);
  else uni2.pb(x[i]);

  sort(ALL(uni));sort(ALL(uni2));
  uni.resize(unique(ALL(uni)) - uni.begin());uni2.resize(unique(ALL(uni2)) - uni2.begin());

  REP(i, n) {
    if (dir[i] == L)lr[lower_bound(ALL(uni), y[i]) - uni.begin()].pb(ii(x[i] - ti[i], x[i]));
    else if (dir[i] == R)lr[lower_bound(ALL(uni), y[i]) - uni.begin()].pb(ii(x[i], x[i] + ti[i]));
    else if (dir[i] == U)ud[lower_bound(ALL(uni2), x[i]) - uni2.begin()].pb(ii(y[i] - ti[i], y[i]));
    else ud[lower_bound(ALL(uni2), x[i]) - uni2.begin()].pb(ii(y[i], y[i] + ti[i]));
  }
  REP(i, SZ(uni)) {
    auto &p = lr[i];
    sort(ALL(p));
    vector<ii> tmp;
    ii now = p[0];
    for (auto &x : p) {
      if (x.X > now.Y + 1)tmp.pb(now), now = x;
      else now.Y = max(now.Y, x.Y);
    }
    tmp.pb(now);
    for (auto &x : tmp)
      tt += x.Y - x.X + 1, ch.pb({x.X, {i + 1, 1}}), ch.pb({x.Y + 1, {i + 1, -1}});
  }
  REP(i, SZ(uni2)) {
    auto &p = ud[i];
    sort(ALL(p));
    vector<ii> tmp;
    ii now = p[0];
    for (auto &x : p) {
      if (x.X > now.Y + 1)tmp.pb(now), now = x;
      else now.Y = max(now.Y, x.Y);
    }
    tmp.pb(now);
    for (auto &x : tmp) tt += x.Y - x.X + 1, qr.pb({uni2[i], {x.X - 1, x.Y}});
  }
  int it = 0;
  sort(ALL(ch), [](auto &a, auto &b) { return a.X < b.X; });
  sort(ALL(qr), [](auto &a, auto &b) { return a.X < b.X; });
  for (auto &q : qr) {
    while (it < SZ(ch) && ch[it].X <= q.X)ins(ch[it].Y.X, ch[it].Y.Y), it++;
    tt -= bqr(upper_bound(ALL(uni), q.Y.Y) - uni.begin()) - bqr(upper_bound(ALL(uni), q.Y.X) - uni.begin());
  }
  return tt;
}
}

int main() {
  int n, m, k;
  input(n), input(m), input(k);
  REP(i, k) input(x[i]), input(y[i]), input(dir[i]);
  ll SK = (n + m) * 3LL, LR = 0, UD = SK, LU = UD + SK, RU = LU + SK, LD = RU + SK, RD = LD + SK;
  REP(i, k) {
    if (dir[i] == L)
      ti[i] = x[i] - 1, vp.pb({LR + y[i], L, {x[i], i}}),
      vp.pb({LU + (x[i] + y[i]), L, {x[i] - y[i], i}}),
      vp.pb({LD + (x[i] - y[i]), L, {x[i] + y[i], i}});
    else if (dir[i] == R)
      ti[i] = n - x[i], vp.pb({LR + y[i], R, {x[i], i}}),
      vp.pb({RU + (x[i] - y[i]), R, {x[i] + y[i], i}}),
      vp.pb({RD + (x[i] + y[i]), R, {x[i] - y[i], i}});
    else if (dir[i] == U)
      ti[i] = y[i] - 1, vp.pb({UD + x[i], L, {y[i], i}}),
      vp.pb({LU + (x[i] + y[i]), R, {x[i] - y[i], i}}),
      vp.pb({RU + (x[i] - y[i]), L, {x[i] + y[i], i}});
    else if (dir[i] == D)
      ti[i] = m - y[i], vp.pb({UD + x[i], R, {y[i], i}}),
      vp.pb({RD + (x[i] + y[i]), L, {x[i] - y[i], i}}),
      vp.pb({LD + (x[i] - y[i]), R, {x[i] + y[i], i}});
  }
  p1::solve();
  cout << p2::solve(k) << endl;
}
