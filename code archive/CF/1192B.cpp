#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(_a) (int)_a.size()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;

namespace pre{
struct edge{ll to, id, c;};
vector<edge> v[MAXn];
void dfs(int now, int f){
    for(int i = 0;i < SZ(v[now]);i ++)
        if(v[now][i].to == f)
            v[now].erase(v[now].begin() + i);
    for(int i = 0;i < SZ(v[now]);i ++)
        dfs(v[now][i].to, now);
}
void go(int n){
    for(int i = 1;i < n;i ++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        v[b].pb({a, i, c}), v[a].pb({b, i, c});
    }
    dfs(1, -1);
}
}

const int RAKE = 0, COMPRESS = 1;

struct cluster {
    ll du, dv, len, ans;
    int tp;
    cluster *lc, *rc, *p;
    cluster():du(0), dv(0), len(0), ans(0), tp(-1), lc(0), rc(0), p(0){}
};

void contract(cluster *a, cluster *b, cluster *c, int tp){ // rake a into b or compress a and b as c (a on top)
    c->tp = tp;
    c->lc = a, c->rc = b;
    a->p = b->p = c;
    if(tp == RAKE)c->len = b->len, c->du = max(a->du, b->du), c->dv = max(a->du + b->len, b->dv);
    else c->len = a->len + b->len, c->du = max(a->du, b->du + a->len), c->dv = max(a->dv + b->len, b->dv);
    c->ans = max({a->ans, b->ans, tp == RAKE ? a->du + b->du : a->dv + b->du});
}

void update(cluster *c){
    while(c->p){
        c = c->p;
        contract(c->lc, c->rc, c, c->tp);
    }
}

cluster *lf[MAXn], *cls[MAXn];
vector<int> v[MAXn];
int ep[MAXn], nct, u[MAXn];

void dfs(int now){
    u[now] = 0;
    for(ll k:v[now])dfs(k);
    if(now != 1 && SZ(v[now]) == 1){
        if(!u[v[now][0]]){
            u[now] = u[v[now][0]] = 1;
            cluster *c = new cluster;
            contract(cls[now], cls[v[now][0]], c, COMPRESS);
            v[now].swap(v[v[now][0]]);
            cls[now] = c;
            nct --;
        }
        return;
    }
    vector<int> nv;
    deque<int> q;
    for(auto t:v[now])
        if(u[t])nv.pb(t);
        else if(SZ(v[t]) == 0)q.push_front(t);
        else q.push_back(t);
    while(SZ(q) >= 2 && SZ(v[q.front()]) == 0){
        int a = q.front(), b = q.back();
        q.pop_front(), q.pop_back();
        cluster *c = new cluster;
        contract(cls[a], cls[b], c, RAKE);
        nv.pb(b);
        cls[b] = c;
        nct --;
        u[a] = u[b] = 1;
    }
    while(SZ(q))nv.pb(q.front()), q.pop_front();
    
    v[now] = nv;
}

int main()
{
    IOS();
    ll n, q, w;
    cin >> n >> q >> w;
    pre::go(n);
    for(int i = 1;i <= n;i ++)
        for(auto &p:pre::v[i]){
            v[i].pb(p.to);
            lf[p.to] = new cluster;
            lf[p.to]->du = lf[p.to]->dv = lf[p.to]->len = lf[p.to]->ans = p.c;
            ep[p.id] = p.to;
            cls[p.to] = lf[p.to];
        }
    nct = n - 1;
    while(nct > 1)dfs(1);
    ll lst = 0;
    while(q--){
        ll d, e;
        cin >> d >> e;
        d = (d + lst) % (n - 1) + 1;
        e = (e + lst) % w;
        cluster *c = lf[ep[d]];
        c->du = c->dv = c->len = c->ans = e;
        update(c);
        cout << (lst = cls[v[1][0]]->ans) << "\n";
    }
}
