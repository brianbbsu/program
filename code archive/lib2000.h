#ifndef LIB2000_H_INCLUDED
#define LIB2000_H_INCLUDED

#include <vector>
#include <bitset>
#include <algorithm>
#include <random>
#include <cstdint>
#include <cstring>
#include <chrono>
#include <cstdio>
#define _PRINT_PYTHON
#ifdef _PRINT_PYTHON
#include <string>
#include <fstream>
const std::string filename = "charles_output.txt";
#endif

struct pos_type { float x, y; };
struct tool_type { pos_type pos; int type; };
struct spec_infor { int time; pos_type pos; };

namespace judge {

template <typename BidirectionalIterator>
  void insertion_sort(BidirectionalIterator __first, BidirectionalIterator __last) {
    if (__first == __last) return;

    BidirectionalIterator __it = __first;
    while (++__it != __last) {
        BidirectionalIterator __middle = __it, __right = __it;
        if (*__right < *--__middle) {
            typename std::iterator_traits<BidirectionalIterator>::value_type __val = std::move(*__it);
            *__right-- = *__middle;
            if (__middle != __first) {
                while (__val < *--__middle) {
                    *__right-- = *__middle;
                    if (__middle == __first) break;
                }
            }
            *__right = std::move(__val);
        }
    }
}

class fenwick_tree {
public:
	int c[503];
    fenwick_tree() { memset(c, 0, sizeof(c)); }
    void modify(int x, int v) { for (x++; x < 503; x += x & -x) c[x] += v; }
    int query(int x) { int v = 0; for (x++; x; x ^= x & -x) v += c[x]; return v; }
};

const int MAX_M = 1191;

typedef std::bitset<MAX_M> bools;
typedef std::uniform_int_distribution<int> irand;
typedef std::uniform_real_distribution<float> mrand;

template <class T> void del(const bools& m, std::vector<T>& vec) {
    size_t i = 0, j = 0;
    for (; i < vec.size(); i++, j++) {
        if (m[i]) j--;
        else if (i != j) vec[j] = vec[i];
    }
    vec.resize(j);
}

template <class T> void del(const bools& m, std::vector<T>& vec, bools& mh) {
    size_t i = 0, j = 0;
    for (; i < vec.size(); i++, j++) {
        if (m[i]) j--;
        else if (i != j) vec[j] = vec[i], mh[j] = mh[i];
    }
    vec.resize(j);
}

template <class T, class... U> void del(const bools& m, std::vector<T>& vec, U&... tail) {
    del(m, vec); del(m, tail...);
}

void vector_add_to(pos_type& a, const pos_type& b) { a.x += b.x; a.y += b.y; }
pos_type vector_add(const pos_type& a, const pos_type& b) { return {b.x + a.x, b.y + a.y}; }
pos_type vector_pos(const pos_type& a, const pos_type& b) { return {b.x - a.x, b.y - a.y}; }
pos_type vector_mul(const pos_type& a, float b) { return {a.x * b, a.y * b}; }
pos_type vector_neg(const pos_type& a) { return {-a.x, -a.y}; }
void vector_mul_to(pos_type& a, float b) { a.x *= b; a.y *= b; }
bool vector_comp(const pos_type& a, const pos_type& b) { return a.x < b.x; }
bool vector_c1_comp(const pos_type& a, float b) { return a.x < b; }
bool vector_c2_comp(float b, const pos_type& a) { return b < a.x; }
inline float sq(float a) { return a * a; }

const pos_type vec_zero = {0, 0};

inline float mag2(const pos_type& a) { return sq(a.x) + sq(a.y); }
inline float dist2(const pos_type& a, const pos_type& b) {
    return mag2(vector_pos(a, b));
}

const float PI = 3.14159265;
const float XRange = 100., YRange = 50.;
const float ball_speed = 0.12;
const float speed_lim = 1., accel_lim = .2;
const float sq_speed_lim = speed_lim * speed_lim, sq_accel_lim = accel_lim * accel_lim;
const float size_1 = 2., range_1 = 8.;
const float range_2 = 6., size_2 = 6., speed_2 = 1.6;
const float range_3 = 4.;
const float size_4 = 3.;
const float range_5 = 8., speed_5 = 0.8, speed_5_x = 0.4, speed_5_y = 0.69282;
const float range_6 = 12., speed_6 = 0.8;
const float ratio_7 = 0.2;
const float range_8 = 3.5;
const float range_9 = 10.;
const float range_10_x = 100, range_10_y = 8, speed_10 = 0.6;
const float tools_range = 2.;
const int time_1 = 125, time_2 = 350, interval_2 = 3;
const int time_3 = 300, time_4 = 150, interval_4 = 3, live_4 = 200;
const int time_6 = 50, time_7 = 200;
const int time_8 = 400, interval_8 = 8;
const int time_9 = 125;
const int ball_live = 650, ball_enable = 625;
const int tool_period = 200;
const int spec_warning_time = 150;

const int MAX_TIME_IN_SEC = 800;
const int MAX_TIME = MAX_TIME_IN_SEC * 50;
const double spawn_a = 1. / 20000, spawn_b = 1. / 37, spawn_c = 6;
const double spawn_total = MAX_TIME_IN_SEC * (spawn_c + MAX_TIME_IN_SEC * (spawn_b / 2 + MAX_TIME_IN_SEC * spawn_a / 3));
const float margin_adjust = 1.3;

const float sin_table[] = {0.0000000, 0.0043633, 0.0087265, 0.0130896, 0.0174524, 0.0218149, 0.0261769, 0.0305385, 0.0348995, 0.0392598, 0.0436194, 0.0479781, 0.0523360, 0.0566928, 0.0610485, 0.0654031, 0.0697565, 0.0741085, 0.0784591, 0.0828082, 0.0871557, 0.0915016, 0.0958458, 0.1001881, 0.1045285, 0.1088669, 0.1132032, 0.1175374, 0.1218693, 0.1261990, 0.1305262, 0.1348509, 0.1391731, 0.1434926, 0.1478094, 0.1521234, 0.1564345, 0.1607426, 0.1650476, 0.1693495, 0.1736482, 0.1779435, 0.1822355, 0.1865240, 0.1908090, 0.1950903, 0.1993679, 0.2036418, 0.2079117, 0.2121777, 0.2164396, 0.2206974, 0.2249511, 0.2292004, 0.2334454, 0.2376859, 0.2419219, 0.2461533, 0.2503800, 0.2546019, 0.2588190, 0.2630312, 0.2672384, 0.2714404, 0.2756374, 0.2798290, 0.2840153, 0.2881963, 0.2923717, 0.2965416, 0.3007058, 0.3048643, 0.3090170, 0.3131638, 0.3173047, 0.3214395, 0.3255682, 0.3296906, 0.3338069, 0.3379167, 0.3420201, 0.3461171, 0.3502074, 0.3542910, 0.3583679, 0.3624380, 0.3665012, 0.3705574, 0.3746066, 0.3786486, 0.3826834, 0.3867110, 0.3907311, 0.3947439, 0.3987491, 0.4027467, 0.4067366, 0.4107189, 0.4146932, 0.4186597, 0.4226183, 0.4265687, 0.4305111, 0.4344453, 0.4383711, 0.4422887, 0.4461978, 0.4500984, 0.4539905, 0.4578739, 0.4617486, 0.4656145, 0.4694716, 0.4733197, 0.4771588, 0.4809888, 0.4848096, 0.4886212, 0.4924236, 0.4962165, 0.5000000, 0.5037740, 0.5075384, 0.5112931, 0.5150381, 0.5187733, 0.5224986, 0.5262139, 0.5299193, 0.5336145, 0.5372996, 0.5409745, 0.5446390, 0.5482932, 0.5519370, 0.5555702, 0.5591929, 0.5628049, 0.5664062, 0.5699968, 0.5735764, 0.5771452, 0.5807030, 0.5842497, 0.5877853, 0.5913096, 0.5948228, 0.5983246, 0.6018150, 0.6052940, 0.6087614, 0.6122173, 0.6156615, 0.6190939, 0.6225146, 0.6259235, 0.6293204, 0.6327053, 0.6360782, 0.6394390, 0.6427876, 0.6461240, 0.6494480, 0.6527598, 0.6560590, 0.6593458, 0.6626200, 0.6658817, 0.6691306, 0.6723668, 0.6755902, 0.6788007, 0.6819984, 0.6851830, 0.6883546, 0.6915131, 0.6946584, 0.6977905, 0.7009093, 0.7040147, 0.7071068, 0.7101854, 0.7132504, 0.7163019, 0.7193398, 0.7223640, 0.7253744, 0.7283710, 0.7313537, 0.7343225, 0.7372773, 0.7402181, 0.7431448, 0.7460574, 0.7489557, 0.7518398, 0.7547096, 0.7575650, 0.7604060, 0.7632325, 0.7660444, 0.7688418, 0.7716246, 0.7743926, 0.7771460, 0.7798845, 0.7826082, 0.7853169, 0.7880108, 0.7906896, 0.7933533, 0.7960020, 0.7986355, 0.8012538, 0.8038569, 0.8064446, 0.8090170, 0.8115740, 0.8141155, 0.8166416, 0.8191520, 0.8216469, 0.8241262, 0.8265897, 0.8290376, 0.8314696, 0.8338858, 0.8362862, 0.8386706, 0.8410390, 0.8433914, 0.8457278, 0.8480481, 0.8503522, 0.8526402, 0.8549119, 0.8571673, 0.8594064, 0.8616292, 0.8638355, 0.8660254, 0.8681988, 0.8703557, 0.8724960, 0.8746197, 0.8767268, 0.8788171, 0.8808907, 0.8829476, 0.8849876, 0.8870108, 0.8890171, 0.8910065, 0.8929789, 0.8949344, 0.8968727, 0.8987940, 0.9006982, 0.9025853, 0.9044551, 0.9063078, 0.9081432, 0.9099613, 0.9117620, 0.9135455, 0.9153115, 0.9170601, 0.9187912, 0.9205049, 0.9222010, 0.9238795, 0.9255405, 0.9271839, 0.9288096, 0.9304176, 0.9320079, 0.9335804, 0.9351352, 0.9366722, 0.9381913, 0.9396926, 0.9411760, 0.9426415, 0.9440890, 0.9455186, 0.9469301, 0.9483237, 0.9496991, 0.9510565, 0.9523958, 0.9537170, 0.9550199, 0.9563048, 0.9575714, 0.9588197, 0.9600499, 0.9612617, 0.9624552, 0.9636305, 0.9647873, 0.9659258, 0.9670459, 0.9681476, 0.9692309, 0.9702957, 0.9713421, 0.9723699, 0.9733793, 0.9743701, 0.9753423, 0.9762960, 0.9772311, 0.9781476, 0.9790455, 0.9799247, 0.9807853, 0.9816272, 0.9824504, 0.9832549, 0.9840407, 0.9848078, 0.9855561, 0.9862856, 0.9869964, 0.9876883, 0.9883615, 0.9890159, 0.9896514, 0.9902681, 0.9908659, 0.9914449, 0.9920049, 0.9925462, 0.9930685, 0.9935719, 0.9940563, 0.9945219, 0.9949685, 0.9953962, 0.9958049, 0.9961947, 0.9965655, 0.9969173, 0.9972502, 0.9975641, 0.9978589, 0.9981348, 0.9983917, 0.9986295, 0.9988484, 0.9990482, 0.9992290, 0.9993908, 0.9995336, 0.9996573, 0.9997620, 0.9998477, 0.9999143, 0.9999619, 0.9999905, 1.0000000};
inline float m_sin(int i) {
    if (i <= 360) return sin_table[i];
    if (i <= 720) return sin_table[720 - i];
    if (i <= 1080) return -sin_table[i - 720];
    return -sin_table[1440 - i];
}
inline float m_cos(int i) {
    if (i <= 360) return sin_table[360 - i];
    if (i <= 720) return -sin_table[i - 360];
    if (i <= 1080) return -sin_table[1080 - i];
    return sin_table[i - 1080];
}
inline pos_type vector_ang(int ang, float amp) { return {m_cos(ang) * amp, m_sin(ang) * amp}; }

inline bool inside(const pos_type& a, float p) {
    return a.x >= -p && a.x <= p + XRange && a.y >= -p && a.y <= p + YRange;
}

class Charles {
    struct balls_notspec_t {
        std::vector<pos_type> pos;
        std::vector<int> time;
        bools slow, del;
        balls_notspec_t() { pos.reserve(MAX_M); time.reserve(MAX_M); }
        void trans(int i, int j) { pos[i] = pos[j], time[i] = time[j]; }
        void trans_a(int i, int j) { pos[i] = pos[j], time[i] = time[j], slow[i] = slow[j]; }
        void sort(bool);
    };
    struct temp_ball {
        pos_type pos, v, a;
        int time;
        bool operator<(const temp_ball& i) const { return pos.x < i.pos.x; }
    };
    struct balls_spec_t : public balls_notspec_t {
        std::vector<pos_type> v, a;
        balls_spec_t() {
        	pos.reserve(MAX_M); v.reserve(MAX_M);
        	a.reserve(MAX_M); time.reserve(MAX_M);
		}
		void trans(int i, int j) { pos[i] = pos[j], v[i] = v[j], a[i] = a[j], time[i] = time[j]; }
        void trans_a(int i, int j) { pos[i] = pos[j], v[i] = v[j], a[i] = a[j], time[i] = time[j], slow[i] = slow[j]; }
        void sort(bool);
        void merge(bool, bool, std::vector<temp_ball>&);
    };
    struct square_t {
        float x, ya, yb;
        pos_type v;
        bool kind;
        int time;
        bool run() {
            if (!time--) return false;
            x += v.x; ya += v.y; yb += v.y;
            return true;
        }
        bool operator<(const square_t i) const { return x < i.x; }
    };
    struct circle_t {
        pos_type pos, v;
        float r, r2;
        int time;
        bool run() {
            if (!time--) return false;
            vector_add_to(pos, v);
            return true;
        }
    };
    struct now_spec_t {
        pos_type pos;
        int time, kind;
    };

    int turn; //0~50000
    int prev_slow, next_spec;
    pos_type charles, prev_pos;
    balls_notspec_t balls_notspec;
    balls_spec_t balls_spec;
    std::vector<square_t> square;
    std::vector<circle_t> circle;

    std::vector<tool_type> tools;
    std::vector<spec_infor> pre_specs;
    std::vector<now_spec_t> nowspec;

    bool is_protect;
    int t_gun, t_sword, t_fire, t_blue, t_spider;
    spec_infor pacman;
    float swiper_y, gun_angle;

    fenwick_tree BIT;

    std::default_random_engine gen;
    std::vector<int> spawn_time;
    size_t spawn_time_now;

    bool game_over;

    const size_t SQ_THRESH = 11;
    const size_t N_THRESH = 40;

#ifdef _PRINT_PYTHON
    std::fstream fout;
#endif

public:
    Charles(long long);
    bool play_a_round(pos_type);

    int get_turn() const { return turn; }
    const std::vector<pos_type>& get_balls_notspec() const { return balls_notspec.pos; }
	const std::vector<pos_type>& get_balls_spec() const { return balls_spec.pos; }
    std::vector<tool_type> get_tools() const { return tools; }
    std::vector<spec_infor> get_prespecs() const { return pre_specs; }
	pos_type get_charles_pos() const { return charles; }
    bool get_is_protect() const { return is_protect; }
    int get_gun_time() const { return t_gun; }
    int get_sword_time() const { return t_sword; }
    int get_fire_time() const { return t_fire; }
    int get_blue_energy() const { return t_blue; }
    int get_spider() const { return t_spider; }
    spec_infor get_pacman() const { return pacman; }
    pos_type get_reflect() const { return vector_add(charles, vector_pos(prev_pos, charles)); }

    void set_gun_angle(float f) { if (std::isfinite(f)) gun_angle = f; }

private:
	double newton_cal(double);
	std::vector<int> generate_spawn_time();

    int get_block(float f) { return f < 0 ? 0 : f >= YRange ? 501 : f * 10 + 1; }
    void check_square_sweep_line(const std::vector<pos_type>&, bools&);
    void check_square_bs(const std::vector<pos_type>&, bools&);
    void check_square_naive(const std::vector<pos_type>&, bools&);
    void check_circle_bs(const std::vector<pos_type>&, bools&);
    void check_circle_naive(const std::vector<pos_type>&, bools&);

    int find_nearest_bs(const std::vector<pos_type>&, const bools&, const pos_type&, float&);
    int find_nearest_naive(const std::vector<pos_type>&, const bools&, const pos_type&, float&);

    void add_one_circle(pos_type, pos_type, int, int);
    void add_one_square(pos_type, pos_type, int, int);
    void add_one_ball(pos_type);

    float get_rand_for_pos();
	void generate_random_ball();

    void move_charles(pos_type);
    void del_and_move_square();
    void check_square();
    void del_and_move_circle();
    void check_circle();
    void deal_pacman();
    void deal_swiper();
    bool deal_spec(bool&);
    bool deal_notspec(bool&);
    bool add_spec(const now_spec_t&, std::vector<temp_ball>&);
    void add_spec();
    void add_notspec();
    void check_tools();
    void add_tools();

#ifdef _PRINT_PYTHON
    void print();
#endif
};

void Charles::balls_notspec_t::sort(bool t)
{
    pos_type pl;
    int tl, N = pos.size();
    if (t) {
        bool sl;
        for (int i = 1, j; i < N; i++) {
            if (pos[i].x < pos[i - 1].x) {
                pl = pos[i], tl = time[i], sl = slow[i];
                trans_a(i, i - 1);
                for (j = i - 2; j >= 0 && pl.x < pos[j].x; j--) trans_a(j + 1, j);
                j++;
                pos[j] = pl, time[j] = tl, slow[j] = sl;
            }
        }
    }
    else {
        for (int i = 1, j; i < N; i++) {
            if (pos[i].x < pos[i - 1].x) {
                pl = pos[i], tl = time[i];
                trans(i, i - 1);
                for (j = i - 2; j >= 0 && pl.x < pos[j].x; j--) trans(j + 1, j);
                j++;
                pos[j] = pl, time[j] = tl;
            }
        }
    }
}

void Charles::balls_spec_t::sort(bool t)
{
    pos_type pl, vl, al;
    int tl, N = pos.size();
    if (t) {
        bool sl;
        for (int i = 1, j; i < N; i++) {
            if (pos[i].x < pos[i - 1].x) {
                pl = pos[i], vl = v[i], al = a[i], tl = time[i], sl = slow[i];
                trans_a(i, i - 1);
                for (j = i - 2; j >= 0 && pl.x < pos[j].x; j--) trans_a(j + 1, j);
                j++;
                pos[j] = pl, v[j] = vl, a[j] = al, time[j] = tl, slow[j] = sl;
            }
        }
    }
    else {
        for (int i = 1, j; i < N; i++) {
            if (pos[i].x < pos[i - 1].x) {
                pl = pos[i], vl = v[i], al = a[i], tl = time[i];
                trans(i, i - 1);
                for (j = i - 2; j >= 0 && pl.x < pos[j].x; j--) trans(j + 1, j);
                j++;
                pos[j] = pl, v[j] = vl, a[j] = al, time[j] = tl;
            }
        }
    }
}

void Charles::balls_spec_t::merge(bool t, bool nowspider, std::vector<temp_ball>& source)
{
    int N = pos.size() + source.size(), M = pos.size();
    pos.resize(N); v.resize(N); a.resize(N); time.resize(N);
    if (t) {
		if (nowspider)
			for (auto& i : source) vector_mul_to(i.v, ratio_7), i.time /= ratio_7;
        int i = N - 1, j = M - 1;
        for (; j >= 0; i--, j--) {
            for (; source.size() && pos[j].x < source.back().pos.x; i--) {
                auto& b = source.back();
                pos[i] = b.pos, v[i] = b.v, a[i] = b.a, time[i] = b.time;
                slow[i] = nowspider;
                source.pop_back();
            }
            if (i != j) trans_a(i, j);
            else return;
        }
        for (; i >= 0; i--) {
            auto& b = source.back();
            pos[i] = b.pos, v[i] = b.v, a[i] = b.a, time[i] = b.time;
            slow[i] = nowspider;
            source.pop_back();
        }
    }
    else {
        int i = N - 1, j = M - 1;
        for (; j >= 0; i--, j--) {
            for (; source.size() && pos[j].x < source.back().pos.x; i--) {
                auto& b = source.back();
                pos[i] = b.pos, v[i] = b.v, a[i] = b.a, time[i] = b.time, slow[i] = false;
                source.pop_back();
            }
            if (i != j) trans(i, j), slow[i] = false;
            else return;
        }
        for (; i >= 0; i--) {
            auto& b = source.back();
            pos[i] = b.pos, v[i] = b.v, a[i] = b.a, time[i] = b.time, slow[i] = false;
            source.pop_back();
        }
    }
}

Charles::Charles(long long seed = 0) : gen(seed)
{
    turn = 0;
    swiper_y = pacman.time = t_gun = t_sword = t_fire = t_blue = t_spider = -1;
    game_over = is_protect = false;

    prev_slow = -10000;
    prev_pos = charles = {XRange / 2, YRange / 2};
    prev_pos.x += 0.01;

    square.reserve(100);
    circle.reserve(10);
#ifdef _PRINT_PYTHON
    fout.open(filename, std::ios::out);
#endif

    spawn_time = generate_spawn_time();
    spawn_time_now = 0;
    next_spec = mrand(1500, 1800)(gen);
}

bool Charles::play_a_round(pos_type new_pos)
{
	if (!std::isfinite(new_pos.x) || !std::isfinite(new_pos.y)) {
		puts("Not a valid position.");
		exit(0);
	}
	if (game_over) return false;
    move_charles(new_pos);
    del_and_move_square();
    check_square();
    del_and_move_circle();
    check_circle();
    deal_pacman();
    deal_swiper();
    bool flag = false;
    if (!deal_spec(flag) || !deal_notspec(flag)) return false;
    if (flag) {
        is_protect = false;
        add_one_circle(charles, vec_zero, range_1, time_1);
    }
    add_spec();
    add_notspec();
    check_tools();
    add_tools();
#ifdef _PRINT_PYTHON
    print();
#endif
    turn++;
    return true;
}

double Charles::newton_cal(double a)
{
    double x = 340;
    for (int i = 0; i < 5; i++)
		x -= (x * (spawn_c + x * (spawn_b / 2 + x * spawn_a / 3)) - a) / (spawn_c + x * (spawn_b + x * spawn_a));
    return x;
}

std::vector<int> Charles::generate_spawn_time()
{
    std::vector<int> tans(spawn_total);
    std::uniform_real_distribution<double> __trand(0, spawn_total);
    const double rate = 0.9;
    for (int i = 0; i < spawn_total; i++) {
        if (i < spawn_total * rate) tans[i] = newton_cal(i / rate) * 50;
        else tans[i] = newton_cal(__trand(gen)) * 50;
    }
    sort(tans.begin(), tans.end());
	return tans;
}

void Charles::check_square_sweep_line(const std::vector<pos_type>& balls, bools& del)
{
    int N = balls.size(), i = 0;
    for (auto& sq : square) {
        for (; i < N && balls[i].x <= sq.x; i++)
            if (!del[i] && BIT.query(get_block(balls[i].y))) del[i] = true;
        if (sq.kind) {
            BIT.modify(get_block(sq.ya), 1);
            BIT.modify(get_block(sq.yb), -1);
        }
        else {
            BIT.modify(get_block(sq.ya), -1);
            BIT.modify(get_block(sq.yb), 1);
        }
    }
}

void Charles::check_square_bs(const std::vector<pos_type>& balls, bools& del)
{
    for (auto& sq : square) {
        if (!sq.kind) continue;
        int l = std::lower_bound(balls.begin(), balls.end(), sq.x, vector_c1_comp) - balls.begin();
        int r = std::upper_bound(balls.begin(), balls.end(), sq.x + sq.yb - sq.ya, vector_c2_comp) - balls.begin();
        for (int i = l; i < r; i++)
            if (!del[i] && sq.ya <= balls[i].y && balls[i].y <= sq.yb) del[i] = true;
    }
}

void Charles::check_square_naive(const std::vector<pos_type>& balls, bools& del)
{
    int N = balls.size();
    for (auto& sq : square) {
        if (!sq.kind) continue;
        float tp = sq.x + sq.yb - sq.ya;
        for (int i = 0; i < N; i++)
            if (!del[i] && sq.x <= balls[i].x && balls[i].x <= tp &&
                sq.ya <= balls[i].y && balls[i].y <= sq.yb) del[i] = true;
    }
}

void Charles::check_circle_bs(const std::vector<pos_type>& balls, bools& del)
{
    for (auto& c : circle) {
        int l = std::lower_bound(balls.begin(), balls.end(), c.pos.x - c.r, vector_c1_comp) - balls.begin();
        int r = std::upper_bound(balls.begin(), balls.end(), c.pos.x + c.r, vector_c2_comp) - balls.begin();
        for (int i = l; i < r; i++)
            if (!del[i] && dist2(c.pos, balls[i]) <= c.r2) del[i] = true;
    }
}

void Charles::check_circle_naive(const std::vector<pos_type>& balls, bools& del)
{
    int N = balls.size();
    for (int i = 0; i < N; i++) {
        if (!del[i]) {
            for (auto& c : circle) {
                if (dist2(c.pos, balls[i]) <= c.r2) {
                    del[i] = true;
                    break;
                }
            }
        }
    }
}

int Charles::find_nearest_bs(const std::vector<pos_type>& balls, const bools& del,
                             const pos_type& pos, float& mn)
{
    static int ans, N, mid, i;
    static float temp;
    ans = -1, N = balls.size();
    mid = std::lower_bound(balls.begin(), balls.end(), pos.x, vector_c1_comp) - balls.begin();

    for (i = mid; i >= 0 && sq(pos.x - balls[i].x) < mn; i--)
        if (!del[i] && inside(balls[i], 2) && (temp = dist2(pos, balls[i])) < mn) ans = i, mn = temp;
    for (i = mid + 1; i < N && sq(pos.x - balls[i].x) < mn; i++)
        if (!del[i] && inside(balls[i], 2) && (temp = dist2(pos, balls[i])) < mn) ans = i, mn = temp;
    return ans;
}

int Charles::find_nearest_naive(const std::vector<pos_type>& balls, const bools& del,
                                const pos_type& pos, float& mn)
{
    static int ans;
    static float temp;
    ans = -1;
    for (size_t i = 0; i < balls.size(); i++)
        if (!del[i] && inside(balls[i], 2) && (temp = dist2(pos, balls[i])) < mn) ans = i, mn = temp;
    return ans;
}

void Charles::add_one_circle(pos_type center, pos_type v, int r, int time)
{
    circle.push_back({center, v, (float)r, (float)(r * r), time});
}

void Charles::add_one_square(pos_type center, pos_type v, int r, int time)
{
    float g = (float)r / 2; float ya = center.y - g, yb = center.y + g;
    square.push_back({center.x - g, ya, yb, v, true, time});
    square.push_back({center.x + g, ya, yb, v, false, time});
}

void Charles::add_one_ball(pos_type pos)
{
    balls_notspec.slow[balls_notspec.pos.size()] = t_spider != -1;
    balls_notspec.pos.push_back(pos);
    balls_notspec.time.push_back(ball_live);
}

float Charles::get_rand_for_pos()
{
	static const float fa = 1 / (3 * margin_adjust + 1), fb = 1 - fa, fpa = fa * 3;
    static std::uniform_real_distribution<float> mrand(-1, 1);
    float h = mrand(gen), x = h;
    x -= (x * (fb + x * x * fa) - h) / (fb + fpa * x * x);
    x -= (x * (fb + x * x * fa) - h) / (fb + fpa * x * x);
    return x;
}

void Charles::generate_random_ball()
{
	if (nowspec.size()) return;
	pos_type pos;
    do {
		pos = {get_rand_for_pos() * (XRange / 2 + 1.5f) + XRange / 2, get_rand_for_pos() * (YRange / 2 + 1.5f) + YRange / 2};
	} while (dist2(pos, charles) <= 2.25);
    add_one_ball(pos);
}


void Charles::move_charles(pos_type __pos)
{
    if (t_gun == -1) {
        static float __f;
        static pos_type __temp;
        if ((__f = dist2(__pos, charles)) > sq_speed_lim) {
            __pos = vector_add(charles, vector_mul(vector_pos(charles, __pos), speed_lim / sqrt(__f)));
        }
        __temp = charles;
        vector_add_to(charles, vector_pos(prev_pos, charles));
        if ((__f = dist2(__pos, charles)) > sq_accel_lim) {
            __pos = vector_add(charles, vector_mul(vector_pos(charles, __pos), accel_lim / sqrt(__f)));
        }
        if (__pos.x < 0) __pos.x = 0;
        else if (__pos.x > XRange) __pos.x = XRange;
        if (__pos.y < 0) __pos.y = 0;
        else if (__pos.y > YRange) __pos.y = YRange;
        prev_pos = __temp;
        charles = __pos;
        if (prev_pos.x == charles.x && prev_pos.y == charles.y) prev_pos.x += 0.01;
    }
}

void Charles::del_and_move_square()
{
    size_t i = 0, j = 0;
    for (; i < square.size(); i++, j++) {
        if (!square[i].time--) j--;
        else {
            auto& sq = square[j];
            if (i != j) square[j] = square[i];
            sq.x += sq.v.x;
            sq.ya += sq.v.y;
            sq.yb += sq.v.y;
        }
    }
    square.resize(j);
}

void Charles::check_square()
{
    if (square.size() > SQ_THRESH) {
        check_square_sweep_line(balls_notspec.pos, balls_notspec.del);
        check_square_sweep_line(balls_spec.pos, balls_spec.del);
    }
    else {
        if (balls_notspec.pos.size() > N_THRESH) check_square_bs(balls_notspec.pos, balls_notspec.del);
        else check_square_naive(balls_notspec.pos, balls_notspec.del);
        if (balls_spec.pos.size() > N_THRESH) check_square_bs(balls_spec.pos, balls_spec.del);
        else check_square_naive(balls_spec.pos, balls_spec.del);
    }
}

void Charles::del_and_move_circle()
{
    size_t i = 0, j = 0;
    for (; i < circle.size(); i++, j++) {
        if (!circle[i].time--) j--;
        else {
            if (i != j) circle[j] = circle[i];
            vector_add_to(circle[j].pos, circle[j].v);
        }
    }
    circle.resize(j);
}

void Charles::check_circle()
{
    if (balls_notspec.pos.size() > N_THRESH) check_circle_bs(balls_notspec.pos, balls_notspec.del);
    else check_circle_naive(balls_notspec.pos, balls_notspec.del);
    if (balls_spec.pos.size() > N_THRESH) check_circle_bs(balls_spec.pos, balls_spec.del);
    else check_circle_naive(balls_spec.pos, balls_spec.del);
}

void Charles::deal_pacman()
{
    static std::vector<circle_t> temp_circle(1);
    if (pacman.time > 0) {
        if (pacman.time-- % interval_8) return;

        float mn = 1e+20;
        int ans1 = balls_notspec.pos.size() > N_THRESH ?
                   find_nearest_bs(balls_notspec.pos, balls_notspec.del, pacman.pos, mn) :
                   find_nearest_naive(balls_notspec.pos, balls_notspec.del, pacman.pos, mn);
        int ans2 = balls_spec.pos.size() > N_THRESH ?
                   find_nearest_bs(balls_spec.pos, balls_spec.del, pacman.pos, mn) :
                   find_nearest_naive(balls_spec.pos, balls_spec.del, pacman.pos, mn);
        if (ans2 != -1) pacman.pos = balls_spec.pos[ans2];
        else if (ans1 != -1) pacman.pos = balls_notspec.pos[ans1];

        temp_circle[0] = {pacman.pos, pos_type(), range_8, sq(range_8), 1};
        temp_circle.swap(circle);
        check_circle();
        temp_circle.swap(circle);
    }
    else pacman.time = -1;
}

void Charles::deal_swiper()
{
	if (swiper_y < 0) return;
	{
		auto& B = balls_spec;
		for (size_t i = 0; i < B.pos.size(); i++)
			if (!B.del[i] && B.pos[i].y >= swiper_y && B.pos[i].y <= swiper_y + range_10_y)
				B.del[i] = true;
	} {
		auto& B = balls_notspec;
		for (size_t i = 0; i < B.pos.size(); i++)
			if (!B.del[i] && B.pos[i].y >= swiper_y && B.pos[i].y <= swiper_y + range_10_y)
				B.del[i] = true;
	}
    swiper_y += speed_10;
    if (swiper_y > YRange) swiper_y = -1;
}

bool Charles::deal_spec(bool& flag)
{
	auto& B = balls_spec;
	float d2;
	for (size_t i = 0; i < B.pos.size(); i++) {
		if (!B.del[i]) {
			if (!B.time[i]--) { B.del[i] = true; continue; }

			d2 = dist2(charles, B.pos[i]);
			if ((t_gun != -1 && d2 < sq(range_2)) ||
				(t_sword != -1 && d2 < sq(range_3))) B.del[i] = true;
			else if ((is_protect || flag) && d2 < sq(size_1)) B.del[i] = flag = true;
#ifndef _NO_DEATH
			else if (d2 < 1) return false;
#endif
			else {
				vector_add_to(B.v[i], B.a[i]);
				vector_add_to(B.pos[i], B.v[i]);
			}
		}
	}
	del(B.del, B.pos, B.v, B.a, B.time, B.slow);
	B.del.reset();
	B.sort(turn - prev_slow <= ball_live + time_7);
	return true;
}

bool Charles::deal_notspec(bool& flag)
{
	auto& B = balls_notspec;
	float d2;
	pos_type posvec;
	for (size_t i = 0; i < B.pos.size(); i++) {
		if (!B.del[i]) {
			if (!B.time[i]--) { B.del[i] = true; continue; }

			posvec = vector_pos(B.pos[i], charles);
			d2 = mag2(posvec = vector_pos(B.pos[i], charles));
			if ((t_gun != -1 && d2 < sq(range_2)) ||
				(t_sword != -1 && d2 < sq(range_3))) B.del[i] = true;
			else if (((is_protect && B.time[i] <= ball_enable) || flag) && d2 < sq(size_1))
				B.del[i] = flag = true;
			else if (B.time[i] <= ball_enable) {
#ifndef _NO_DEATH
				if (d2 < 1) return false;
#endif
				vector_add_to(B.pos[i], vector_mul((t_gun != -1 || t_sword != -1) ? vector_neg(posvec) : posvec,
												   (B.slow[i] ? ratio_7 * ball_speed : ball_speed) / sqrt(d2)));
			}
		}
	}
	del(B.del, B.pos, B.time, B.slow);
	B.del.reset();
	B.sort(turn - prev_slow <= ball_live + time_7);
	return true;
}

const short spec_2_time[] = {199, 200, 201, 202, 203, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 216, 215, 215, 214, 214, 214, 213, 213, 213, 212, 212, 212, 211, 211, 211, 210, 210, 210, 209, 209, 209, 209, 208, 208, 208, 208, 207, 207, 207, 207, 206, 206, 206, 206, 206, 205, 205, 205, 205, 205, 204, 204, 204, 204, 204, 204, 203, 203, 203, 203, 203, 203, 203, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 201, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 203, 203, 203, 203, 203, 203, 203, 203, 204, 204, 204, 204, 204, 204, 204, 205, 205, 205, 205, 205, 205, 206, 206, 206, 206, 206, 206, 207, 207, 207, 207, 207, 208, 208, 208, 208, 208, 209, 209, 209, 209, 210, 210, 210, 210, 211, 211, 211, 211, 211, 212, 212, 212, 213, 213, 213, 213, 214, 214, 214, 214, 215, 215, 215, 216, 215, 209, 203, 199, 195, 191, 188, 185, 182, 180, 177, 175, 173, 171, 169, 167, 165, 163, 162, 160, 159, 157, 156, 155, 153, 152, 151, 150, 148, 147, 146, 145, 144, 143, 142, 141, 140, 140, 139, 138, 137, 136, 135, 135, 134, 133, 132, 132, 131, 130, 130, 129, 129, 128, 127, 127, 126, 126, 125, 124, 124, 123, 123, 122, 122, 121, 121, 120, 120, 119, 119, 119, 118, 118, 117, 117, 116, 116, 116, 115, 115, 115, 114, 114, 114, 113, 113, 112, 112, 112, 112, 111, 111, 111, 110, 110, 110, 109, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 113, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 118, 118, 119, 119, 119, 118, 117, 116, 115, 114, 114, 113, 112, 111, 110, 110, 109, 108, 108, 107, 106, 106, 105, 105, 104, 103, 103, 102, 102, 101, 101, 100, 100, 99, 99, 98, 98, 97, 97, 96, 96, 96, 95, 95, 94, 94, 94, 93, 93, 92, 92, 92, 91, 91, 91, 90, 90, 90, 89, 89, 89, 88, 88, 88, 88, 87, 87, 87, 87, 86, 86, 86, 85, 85, 85, 85, 84, 84, 84, 84, 84, 83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 80, 80, 80, 80, 80, 80, 79, 79, 79, 79, 79, 79, 79, 78, 78, 78, 78, 78, 78, 78, 78, 77, 77, 77, 77, 77, 77, 77, 77, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 78, 78, 78, 78, 78, 78, 78, 78, 79, 79, 79, 79, 79, 79, 79, 79, 80, 80, 80, 80, 80, 80, 80, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83, 84, 84, 84, 84, 84, 84, 85, 85, 85, 85, 85, 86, 86, 86, 86, 86, 87, 87, 87, 87, 88, 88, 88, 88, 88, 89, 89, 89, 89, 90, 90, 90, 90, 90, 91, 91, 91, 91, 92, 92, 92, 93, 93, 93, 93, 94, 94, 94, 94, 95, 95, 95, 96, 96, 96, 96, 97, 97, 97, 98, 98, 98, 99, 99, 99, 99, 100, 100, 100, 101, 101, 101, 102, 102, 102, 103, 103, 104, 104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 108, 108, 108, 109, 109, 110, 110, 110, 111, 111, 112, 112, 113, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 117, 118, 118, 119, 119, 119, 118, 118, 117, 117, 116, 116, 116, 115, 115, 115, 114, 114, 114, 113, 113, 112, 112, 112, 112, 111, 111, 111, 110, 110, 110, 109, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 113, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 126, 126, 126, 127, 127, 127, 128, 128, 128, 129, 129, 130, 130, 130, 131, 131, 132, 132, 132, 133, 133, 134, 134, 135, 135, 135, 136, 136, 137, 137, 138, 138, 138, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 144, 144, 145, 145, 146, 146, 147, 147, 148, 148, 149, 149, 150, 150, 151, 151, 152, 153, 153, 154, 154, 155, 155, 156, 157, 157, 158, 158, 159, 160, 160, 161, 161, 162, 163, 163, 164, 165, 165, 166, 166, 167, 168, 168, 169, 170, 170, 171, 172, 173, 173, 174, 175, 175, 176, 177, 177, 178, 179, 180, 180, 181, 182, 183, 183, 184, 185, 186, 187, 187, 188, 189, 190, 191, 191, 192, 193, 194, 195, 196, 196, 197, 198, 199};
const short spec_6_time[] = {180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 182, 182, 182, 182, 182, 182, 182, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 185, 185, 185, 185, 185, 186, 186, 186, 186, 187, 187, 187, 187, 187, 188, 188, 188, 188, 189, 189, 189, 190, 190, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194, 194, 195, 195, 195, 196, 196, 196, 194, 192, 191, 189, 187, 185, 184, 182, 180, 179, 177, 176, 174, 173, 171, 170, 169, 167, 166, 165, 163, 162, 161, 160, 158, 157, 156, 155, 154, 153, 152, 150, 149, 148, 147, 146, 145, 144, 143, 143, 142, 141, 140, 139, 138, 137, 136, 136, 135, 134, 133, 132, 132, 131, 130, 129, 129, 128, 127, 127, 126, 125, 125, 124, 123, 123, 122, 121, 121, 120, 120, 119, 118, 118, 117, 117, 116, 116, 115, 115, 114, 114, 113, 113, 112, 112, 111, 111, 110, 110, 109, 109, 108, 108, 108, 107, 107, 106, 106, 106, 105, 105, 104, 104, 104, 103, 103, 102, 102, 102, 101, 101, 101, 100, 100, 100, 99, 99, 99, 98, 98, 98, 97, 97, 97, 97, 96, 96, 96, 95, 95, 95, 95, 94, 94, 94, 94, 93, 93, 93, 93, 92, 92, 92, 92, 91, 91, 91, 91, 91, 90, 90, 90, 90, 89, 89, 89, 89, 89, 89, 88, 88, 88, 88, 88, 87, 87, 87, 87, 87, 87, 86, 86, 86, 86, 86, 86, 85, 85, 85, 85, 85, 85, 85, 84, 84, 84, 84, 84, 84, 84, 84, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 84, 84, 84, 84, 84, 84, 84, 84, 85, 85, 85, 85, 85, 85, 85, 86, 86, 86, 86, 86, 86, 87, 87, 87, 87, 87, 87, 88, 88, 88, 88, 88, 89, 89, 89, 89, 89, 89, 90, 90, 90, 90, 91, 91, 91, 91, 91, 92, 92, 92, 92, 93, 93, 93, 93, 94, 94, 94, 94, 95, 95, 95, 95, 96, 96, 96, 97, 97, 97, 97, 98, 98, 98, 99, 99, 99, 99, 99, 98, 98, 97, 96, 96, 95, 95, 94, 94, 93, 93, 92, 92, 91, 91, 90, 90, 90, 89, 89, 88, 88, 87, 87, 87, 86, 86, 85, 85, 85, 84, 84, 84, 83, 83, 83, 82, 82, 82, 81, 81, 81, 80, 80, 80, 79, 79, 79, 78, 78, 78, 78, 77, 77, 77, 76, 76, 76, 76, 75, 75, 75, 75, 74, 74, 74, 74, 73, 73, 73, 73, 73, 72, 72, 72, 72, 71, 71, 71, 71, 71, 70, 70, 70, 70, 70, 69, 69, 69, 69, 69, 69, 68, 68, 68, 68, 68, 68, 67, 67, 67, 67, 67, 67, 67, 66, 66, 66, 66, 66, 66, 66, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 64, 64, 64, 64, 64, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 64, 64, 64, 64, 64, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 66, 66, 66, 66, 66, 66, 66, 67, 67, 67, 67, 67, 67, 67, 68, 68, 68, 68, 68, 68, 69, 69, 69, 69, 69, 69, 70, 70, 70, 70, 70, 71, 71, 71, 71, 71, 72, 72, 72, 72, 73, 73, 73, 73, 73, 74, 74, 74, 74, 75, 75, 75, 75, 76, 76, 76, 76, 77, 77, 77, 78, 78, 78, 78, 79, 79, 79, 80, 80, 80, 81, 81, 81, 82, 82, 82, 83, 83, 83, 84, 84, 84, 85, 85, 85, 86, 86, 87, 87, 87, 88, 88, 89, 89, 90, 90, 90, 91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 98, 98, 99, 99, 99, 99, 99, 98, 98, 98, 97, 97, 97, 97, 96, 96, 96, 95, 95, 95, 95, 94, 94, 94, 94, 93, 93, 93, 93, 92, 92, 92, 92, 91, 91, 91, 91, 91, 90, 90, 90, 90, 89, 89, 89, 89, 89, 89, 88, 88, 88, 88, 88, 87, 87, 87, 87, 87, 87, 86, 86, 86, 86, 86, 86, 85, 85, 85, 85, 85, 85, 85, 84, 84, 84, 84, 84, 84, 84, 84, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 84, 84, 84, 84, 84, 84, 84, 84, 85, 85, 85, 85, 85, 85, 85, 86, 86, 86, 86, 86, 86, 87, 87, 87, 87, 87, 87, 88, 88, 88, 88, 88, 89, 89, 89, 89, 89, 89, 90, 90, 90, 90, 91, 91, 91, 91, 91, 92, 92, 92, 92, 93, 93, 93, 93, 94, 94, 94, 94, 95, 95, 95, 95, 96, 96, 96, 97, 97, 97, 97, 98, 98, 98, 99, 99, 99, 100, 100, 100, 101, 101, 101, 102, 102, 102, 103, 103, 104, 104, 104, 105, 105, 106, 106, 106, 107, 107, 108, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 120, 120, 121, 121, 122, 123, 123, 124, 125, 125, 126, 127, 127, 128, 129, 129, 130, 131, 132, 132, 133, 134, 135, 136, 136, 137, 138, 139, 140, 141, 142, 143, 143, 144, 145, 146, 147, 148, 149, 150, 152, 153, 154, 155, 156, 157, 158, 160, 161, 162, 163, 165, 166, 167, 169, 170, 171, 173, 174, 176, 177, 179, 180, 182, 184, 185, 187, 189, 191, 192, 194, 196, 196, 196, 195, 195, 195, 194, 194, 194, 193, 193, 193, 192, 192, 192, 191, 191, 191, 190, 190, 190, 190, 189, 189, 189, 188, 188, 188, 188, 187, 187, 187, 187, 187, 186, 186, 186, 186, 185, 185, 185, 185, 185, 184, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 182, 182, 182, 182, 182, 182, 182, 181, 181, 181, 181, 181, 181, 181, 181, 181, 181, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180};
const short spec_5_time[] = {224, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 226, 226, 226, 226, 226, 226, 226, 226, 226, 227, 227, 227, 227, 227, 227, 227, 228, 228, 228, 228, 228, 229, 229, 229, 229, 229, 230, 230, 230, 230, 230, 231, 231, 231, 231, 232, 232, 232, 232, 233, 233, 233, 234, 234, 234, 234, 235, 235, 235, 236, 236, 236, 237, 237, 237, 238, 238, 239, 239, 239, 240, 240, 241, 241, 241, 242, 242, 243, 243, 243, 244, 244, 245, 245, 245, 243, 241, 238, 236, 234, 232, 230, 228, 226, 224, 222, 220, 218, 216, 214, 213, 211, 209, 207, 206, 204, 203, 201, 199, 198, 197, 195, 194, 192, 191, 190, 188, 187, 186, 184, 183, 182, 181, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 158, 157, 156, 155, 154, 153, 153, 152, 151, 150, 150, 149, 148, 148, 147, 146, 145, 145, 144, 143, 143, 142, 142, 141, 140, 140, 139, 139, 138, 137, 137, 136, 136, 135, 135, 134, 134, 133, 133, 132, 132, 131, 131, 130, 130, 129, 129, 128, 128, 127, 127, 126, 126, 126, 125, 125, 124, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 118, 117, 117, 117, 116, 116, 116, 116, 115, 115, 115, 114, 114, 114, 114, 113, 113, 113, 112, 112, 112, 112, 111, 111, 111, 111, 111, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 106, 106, 106, 106, 106, 106, 105, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 106, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 124, 123, 123, 122, 121, 121, 120, 119, 119, 118, 117, 117, 116, 116, 115, 114, 114, 113, 113, 112, 112, 111, 111, 110, 109, 109, 108, 108, 107, 107, 107, 106, 106, 105, 105, 104, 104, 103, 103, 102, 102, 102, 101, 101, 100, 100, 100, 99, 99, 99, 98, 98, 97, 97, 97, 96, 96, 96, 95, 95, 95, 94, 94, 94, 93, 93, 93, 93, 92, 92, 92, 91, 91, 91, 91, 90, 90, 90, 89, 89, 89, 89, 88, 88, 88, 88, 87, 87, 87, 87, 87, 86, 86, 86, 86, 85, 85, 85, 85, 85, 84, 84, 84, 84, 84, 83, 83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 81, 81, 80, 80, 80, 80, 80, 80, 80, 79, 79, 79, 79, 79, 79, 79, 79, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 79, 79, 79, 79, 79, 79, 79, 79, 80, 80, 80, 80, 80, 80, 80, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83, 84, 84, 84, 84, 84, 85, 85, 85, 85, 85, 86, 86, 86, 86, 87, 87, 87, 87, 87, 88, 88, 88, 88, 89, 89, 89, 89, 90, 90, 90, 91, 91, 91, 91, 92, 92, 92, 93, 93, 93, 93, 94, 94, 94, 95, 95, 95, 96, 96, 96, 97, 97, 97, 98, 98, 99, 99, 99, 100, 100, 100, 101, 101, 102, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 107, 108, 108, 109, 109, 110, 111, 111, 112, 112, 113, 113, 114, 114, 115, 116, 116, 117, 117, 118, 119, 119, 120, 121, 121, 122, 123, 123, 124, 124, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 118, 117, 117, 117, 116, 116, 116, 116, 115, 115, 115, 114, 114, 114, 114, 113, 113, 113, 112, 112, 112, 112, 111, 111, 111, 111, 111, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 108, 108, 108, 108, 107, 107, 107, 107, 107, 106, 106, 106, 106, 106, 106, 105, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 106, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 125, 125, 126, 126, 126, 127, 127, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 137, 138, 139, 139, 140, 140, 141, 142, 142, 143, 143, 144, 145, 145, 146, 147, 148, 148, 149, 150, 150, 151, 152, 153, 153, 154, 155, 156, 157, 158, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 181, 182, 183, 184, 186, 187, 188, 190, 191, 192, 194, 195, 197, 198, 199, 201, 203, 204, 206, 207, 209, 211, 213, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 241, 243, 245, 245, 245, 244, 244, 243, 243, 243, 242, 242, 241, 241, 241, 240, 240, 239, 239, 239, 238, 238, 237, 237, 237, 236, 236, 236, 235, 235, 235, 234, 234, 234, 234, 233, 233, 233, 232, 232, 232, 232, 231, 231, 231, 231, 230, 230, 230, 230, 230, 229, 229, 229, 229, 229, 228, 228, 228, 228, 228, 227, 227, 227, 227, 227, 227, 227, 226, 226, 226, 226, 226, 226, 226, 226, 226, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225, 225};

bool Charles::add_spec(const now_spec_t& T, std::vector<temp_ball>& ans)
{
	switch (T.kind) {
		case 0: {
			if (T.time == 224) return true;
			if ((T.time & 31) < 24 && (T.time & 31) % 5 == 0) {
				for (int i = 11; i >= 0; i--) {
					if (!(i % 4)) continue;
					ans.push_back({T.pos, (pos_type){sin_table[360 - i * 7] * 0.5f, sin_table[i * 7] * 0.5f},
								   vec_zero, 191});
					ans.push_back({T.pos, (pos_type){ans.back().v.x, -ans.back().v.y}, vec_zero, 191});
				}
			}
			break;
		}
		case 1: {
			if (T.time == 250) return true;
			int Q = (((T.time << 2) + (T.time << 5 ^ T.time << 6)) ^ T.time) % 141;
			if (Q > 70) {
				Q = 141 - Q;
				ans.push_back({T.pos, (pos_type){sin_table[360 - Q] * 0.5f, sin_table[Q] * -0.5f}, vec_zero, 191});
			}
			else ans.push_back({T.pos, (pos_type){sin_table[360 - Q] * 0.5f, sin_table[Q] * 0.5f}, vec_zero, 191});
			break;
		}
		case 2: {
			if (T.time == 150) return true;
			if (T.time % 6 == 0) {
				for (int i = 0, j = 1080, k = 0; i < 1440; i += 40, j += 40, k++) {
					if (j >= 1440) j -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vector_ang(j, 0.002), spec_2_time[i]});
				}
			}
			break;
		}
		case 3: {
			if (T.time == 150) return true;
			if (T.time % 6 == 0) {
				for (int i = 900 - T.time * 5/2, j = 540 - T.time * 5/2, k = 0; k < 36; i += 40, j += 40, k++) {
					if (k % 9 > 4) continue;
					if (i >= 1440) i -= 1440;
					if (j >= 1440) j -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vector_ang(j, 0.002), spec_2_time[i]});
				}
			}
			break;
		}
		case 4: {
			if (T.time == 200) return true;
			if (T.time % 10 == 0) {
				pos_type temp = vector_pos(T.pos, charles);
				ans.push_back({T.pos, vector_mul(temp, 0.35 / sqrt(mag2(temp))), vec_zero, 283});
			}
			break;
		}
		case 5: {
			if (T.time == 150) return true;
			if (T.time % 3 == 0) {
				for (int i = 700, j = 0; j < 8; i += 190, j++) {
					int c = i + m_sin((T.time * 27 + i / 20) % 1440) * 60;
					if (c >= 1440) c -= 1440;
					ans.push_back({T.pos, vector_ang(c, 0.4), vec_zero, spec_5_time[c]});
				}
			}
			break;
		}
		case 6: {
			if (T.time == 230) return true;
			int c = (230 - T.time) * 36 % 1440;
			int d = c - 18 < 0 ? c + 1422 : c - 18;
			ans.push_back({T.pos, vector_ang(d, 0.5), vec_zero, spec_6_time[d]});
			ans.push_back({T.pos, vector_ang(c, 0.5), vec_zero, spec_6_time[c]});
			vector_add_to(ans.back().pos, vector_mul(ans.back().v, 0.5));
			break;
		}
		case 7: {
			if (T.time == 151) return true;
			if (T.time % 100 == 0) {
				for (int i = 0; i < 1440; i += 12) {
					if (i < 60) continue;
					int c = T.pos.y < YRange / 2 ? i : 1440 - i;
					ans.push_back({T.pos, vector_ang(c, 0.4), vec_zero, spec_5_time[c]});
				}
			}
			else if (T.time % 100 == 50) {
				for (int i = 0; i < 1440; i += 12) {
					if (i >= 90 && i < 150) continue;
					int c = T.pos.y < YRange / 2 ? i : 1440 - i;
					ans.push_back({T.pos, vector_ang(c, 0.4), vec_zero, spec_5_time[c]});
				}
			}
			break;
		}
		case 8: {
			if (T.time == 176) return true;
			pos_type temp = vector_pos(T.pos, charles);
			if (T.time % 35 == 0) {
				int c = atan2(temp.y, temp.x) / PI * 720;
				if (c < 0) c += 1440;
				for (int i = 1200 + c, j = 0; j < 9; i += 60, j++) {
					if (i >= 1440) i -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.25), vec_zero, spec_6_time[c] * 2 + 1});
				}
			}
			break;
		}
		case 9: {
			if (T.time == 150) return true;
			if (T.time % 7 == 0) {
				for (int i = (160 - T.time) * 5 % 1440, j = i + 360, k = 0; k < 4; i += 360, j += 360, k++) {
					if (i >= 1440) i -= 1440;
					if (j >= 1440) j -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vector_ang(j, 0.002), spec_2_time[1440 - i]});
				}
			}
			else if (T.time % 7 == 3) {
				for (int i = T.time * 5 % 1440, j = i + 1080, k = 0; k < 4; i += 360, j += 360, k++) {
					if (i >= 1440) i -= 1440;
					if (j >= 1440) j -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vector_ang(j, 0.002), spec_2_time[i]});
				}
			}
			if (T.time % 4 == 0) {
				for (int i = (170 - T.time) * 6 % 1440, k = 0; k < 4; i += 360, k++) {
					if (i >= 1440) i -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vec_zero, spec_5_time[i]});
				}
			}
			else if (T.time % 4 == 2) {
				for (int i = T.time * 6 % 1440, k = 0; k < 4; i += 360, k++) {
					if (i >= 1440) i -= 1440;
					ans.push_back({T.pos, vector_ang(i, 0.4), vec_zero, spec_5_time[i]});
				}
			}
			break;
		}
	}
	return false;
}

void Charles::add_spec()
{
	std::vector<temp_ball> newball;
	std::vector<size_t> del;
	for (size_t i = 0; i < nowspec.size(); i++)
		if (add_spec(nowspec[i], newball)) del.push_back(i);
	std::reverse(del.begin(), del.end());
	for (size_t i : del) nowspec.erase(nowspec.begin() + i);
	std::sort(newball.begin(), newball.end());

	if (newball.size()) balls_spec.merge(turn - prev_slow <= ball_live + time_7, t_spider != -1, newball);
	for (auto& i : nowspec) i.time++;

    if (next_spec <= turn + spec_warning_time) {
        next_spec += 750 * exp((double)-turn / 10000) + 250 + irand(0, 50)(gen);
        if (balls_spec.pos.size() <= 300 && irand(0, 4)(gen) < 3)
			pre_specs.push_back({spec_warning_time, (pos_type){mrand(10, 30)(gen), mrand(10, 40)(gen)}});
    }

	del.clear();
    for (size_t i = 0; i < pre_specs.size(); i++) {
        if (!--pre_specs[i].time) {
			del.push_back(i);
            nowspec.push_back({pre_specs[i].pos, 0, irand(0, 9)(gen)});
        }
    }
    std::reverse(del.begin(), del.end());
    for (size_t i : del) pre_specs.erase(pre_specs.begin() + i);
}

void Charles::add_notspec()
{
	for (; spawn_time_now < spawn_time.size() && spawn_time[spawn_time_now] == turn; spawn_time_now++) {
        generate_random_ball();
    }
}

void Charles::check_tools()
{
	std::vector<size_t> del;
    for (size_t i = 0; i < tools.size(); i++) {
        if (dist2(charles, tools[i].pos) > sq(tools_range)) continue;
        switch (tools[i].type) {
			case 1: is_protect = true; break;
			case 2: t_gun = time_2; break;
			case 3: t_sword = time_3; break;
			case 4: t_fire = time_4; break;
			case 5: {
                add_one_circle(tools[i].pos, {-speed_5, 0}, range_5, (tools[i].pos.x + range_5) / speed_5);
                add_one_circle(tools[i].pos, {speed_5_x, -speed_5_y}, range_5, (tools[i].pos.y + range_5) / speed_5_y);
                add_one_circle(tools[i].pos, {speed_5_x, speed_5_y}, range_5, ((YRange - tools[i].pos.y) + range_5) / speed_5_y);
                break;
			}
			case 6: t_blue = time_6; break;
			case 7: {
                t_spider = time_7;
                prev_slow = turn;
                balls_notspec.slow.set();
                for (size_t i = 0; i < balls_spec.pos.size(); i++)
                    if (!balls_spec.slow[i]) vector_mul_to(balls_spec.v[i], ratio_7);
				balls_spec.slow.set();
				for (auto& i : balls_spec.time) i /= ratio_7;
				break;
			}
			case 8: pacman = {time_8, tools[i].pos}; break;
            case 9: add_one_circle(tools[i].pos, vec_zero, range_9, time_9); break;
			case 10: swiper_y = 0; break;
        }
        del.push_back(i);
    }
    reverse(del.begin(), del.end());
    for (size_t i : del) tools.erase(tools.begin() + i);
}

void Charles::add_tools()
{
	static int prev_tool = -1;
	bool sq_add = false;
    if (turn && turn % tool_period == 0 && tools.size() < 3) {
        pos_type temp;
        int kind;
        do {
			temp = {mrand(3, XRange - 3)(gen), mrand(3, YRange - 3)(gen)};
		} while (dist2(temp, charles) <= 16);
        bool flag = is_protect;
        for (auto& i : tools)
			if (i.type == 1) flag = true;
		do kind = irand(0, 10)(gen); while (kind == prev_tool || (flag && kind == 1));
		tools.push_back({temp, kind});
        prev_tool = kind;
    }
    if (t_gun != -1) { //2
        if (t_gun % interval_2 == 0) {
			int gun_angle_temp = int(gun_angle / PI * 720) % 1440;
			if (gun_angle_temp < 0) gun_angle_temp += 1440;
            pos_type v = vector_mul({m_cos(gun_angle_temp), m_sin(gun_angle_temp)}, speed_2);
            add_one_square(vector_add(charles, vector_mul(v, 2)), v, size_2, 76);
            sq_add = true;
        }
        if (!--t_gun) t_gun = -1;
    }
    if (t_sword != -1) //3
		if (!--t_sword) t_sword = -1;
	if (t_fire != -1) { //4
        if (t_fire % interval_4 == 0) add_one_square(charles, vec_zero, size_4, live_4), sq_add = true;
        if (!--t_fire) t_fire = -1;
    }
    if (t_blue != -1) { //6
        if (!--t_blue) {
            pos_type dir = vector_pos(prev_pos, charles);
            add_one_circle(charles, vector_mul(dir, speed_6 / sqrt(mag2(dir))), range_6, 154);
            t_blue = -1;
        }
    }
    if (t_spider != -1 && !--t_spider) t_spider = -1;
    if (sq_add) insertion_sort(square.begin(), square.end());
}

#ifdef _PRINT_PYTHON
void Charles::print()
{
	//square
	fout << square.size() / 2 + (swiper_y >= 0 ? 1 : 0) << '\n';
	for (const auto& i : square)
		if (i.kind) fout << i.x + (i.yb - i.ya) / 2 << '\n' << (i.ya + i.yb) / 2 << '\n' << i.yb - i.ya << '\n' << i.yb - i.ya << '\n';
	if (swiper_y >= 0) fout << XRange / 2 << '\n' << swiper_y + range_10_y / 2 << '\n' << range_10_x << '\n' << range_10_y << '\n';
	//circle
	struct cir { pos_type pos; float r; int kind; };
	std::vector<cir> cirs;
	for (size_t i = 0; i < balls_notspec.pos.size(); i++)
		cirs.push_back({balls_notspec.pos[i], 0.3, balls_notspec.slow[i] ? 1 : 0});
	for (size_t i = 0; i < balls_spec.pos.size(); i++)
		cirs.push_back({balls_spec.pos[i], 0.3, balls_spec.slow[i] ? 3 : 2});
	for (const auto& i : circle) cirs.push_back({i.pos, i.r, 4});
	if (pacman.time != -1) cirs.push_back({pacman.pos, range_8, 4});
	for (const auto& i : tools) cirs.push_back({i.pos, tools_range, i.type + 5});
	cirs.push_back({charles, t_gun != -1 ? range_2 : t_sword != -1 ? range_3 : 1, 16});

	fout << cirs.size() << '\n';
	for (auto& i : cirs) fout << i.pos.x << '\n' << i.pos.y << '\n' << i.r << '\n' << i.kind << '\n';
	fout << std::flush;
}
#endif

Charles* Game;

std::chrono::system_clock::time_point Time1;
std::chrono::nanoseconds Total;

void start_clock() {
    Time1 = std::chrono::system_clock::now();
}
long long pause_clock() {
	using namespace std::chrono;
    auto t = duration_cast<nanoseconds>(system_clock::now() - Time1);
    Total += t;
    return t.count();
}

} //namespace

#include <ctime>
#include <cstdlib>

void init();
pos_type play();

int get_time() { return judge::Game->get_turn(); }
const std::vector<pos_type>& get_ball() { return judge::Game->get_balls_notspec(); }
const std::vector<pos_type>& get_ball_spec() { return judge::Game->get_balls_spec(); }
std::vector<tool_type> get_tool() { return judge::Game->get_tools(); }
std::vector<spec_infor> get_spec() { return judge::Game->get_prespecs(); }
pos_type get_pos() { return judge::Game->get_charles_pos(); }
bool is_protected() { return judge::Game->get_is_protect(); }
int gun_time() { return judge::Game->get_gun_time(); }
int sword_time() { return judge::Game->get_sword_time(); }
int fire_time() { return judge::Game->get_fire_time(); }
int blue_energy() { return judge::Game->get_blue_energy(); }
int spider_web() { return judge::Game->get_spider(); }
spec_infor pacman() { return judge::Game->get_pacman(); }
void set_gun(float angle) { judge::Game->set_gun_angle(angle); }

int main()
{
	using namespace judge;

	long long Seed;
    scanf("%lld", &Seed);

    Game = new Charles(Seed);

    init();
    int t_pause = 0;
    while (1) {
		pos_type pos;
        if (!t_pause) {
			start_clock();
			pos = play();
			t_pause = pause_clock() / 4000000;
        }
        else pos = Game->get_reflect();

        if (!Game->play_a_round(pos) || Game->get_turn() == MAX_TIME) break;
    }

    long double Score = (long double)Game->get_turn() / 50;
    long double UserExecTime = (long double)Total.count() / 1000000;

    if (Game->get_turn() < 400) {
		printf("Score: %.2lf\nExecution Time: %.3lf (ms)\n", (double)Score, (double)UserExecTime);
		return 0;
    }

    long long FinalTime = 55000 + std::max(UserExecTime, (long double)500) - (Score * (Score / 25 + 28));

    printf("Score: %.2lf\nExecution Time: %.3lf (ms)\nFinal Time: %.1lf (ms)\n",
			(double)Score, (double)UserExecTime, (double)FinalTime);
}

#endif // LIB2000_H_INCLUDED
