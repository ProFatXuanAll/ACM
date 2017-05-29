#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define maxn ((int)1e7)
#define INF (0x3f3f3f3f)

static int N, size[50], s[50];
static int pos[maxn+5], fenx[maxn+5];

struct point {
    int val, mac;
    point (int val = 0, int mac = 0) {
        this->val = val;
        this->mac = mac;
    }
};

static queue<int> q;
static vector<point> v;

static int lowbit(int index);
static bool cmp(const point& a, const point& b);
static int getsum(int index);
static void add(int index, int v);
static int get_distance(int i);
static void hit(int i);
static void put_ans();
static void solve();

int main () {
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &size[i]);

        v.clear();
        int x, y, n;
        char order[50];
        while (scanf("%s", order) == 1 && strcmp(order, "END")) {
            if (order[0] == 'R') {
                scanf("%d%d%d", &x, &y, &n);
                for (int i = 0; i < n; i++)
                    v.push_back(point(x + y * i, v.size() + 1));
            } else if (order[0] == 'A') {
                scanf("%d", &x);
                v.push_back(point(x, v.size() + 1));
            } else
                q.push(v.size());
        }
        solve();
    }
    return 0;
}

static int lowbit(int index)
{
	return index&(-index);
}

static bool cmp (const point& a, const point& b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.mac < b.mac;
}

static int getsum (int index) {
    int res = 0;
    while (index>0) {
        res += fenx[index];
        index -= lowbit(index);
    }
    return res;
}

static void add (int index, int v) {
    while (index <= maxn) {
        fenx[index] += v;
        index += lowbit(index);
    }
}

static int get_distance (int i) {
    if (pos[i] == -INF)
        return INF;
    return i - pos[i] - getsum(i) + getsum(pos[i] - 1);
}

static void hit (int i) {
    if (i <= 0)
        return;
    add(i, 1);
}

static void put_ans() {
    for (int i = 1; i <= N; i++)
        printf("%d%c", s[i], i == N ? '\n' : ' ');
    memset(s, 0, sizeof(s));
}

static void solve () {
    memset(s, 0, sizeof(s));
    memset(fenx, 0, sizeof(fenx));

    int n = v.size();
    sort(v.begin(), v.end(), cmp);


    if (q.front() == 0) {
        put_ans();
        q.pop();
    }

    if (n == 0)
        return;
    pos[v[0].mac] = -INF;
    for (int i = 1; i < n; i++) {
        if (v[i].val == v[i-1].val)
            pos[v[i].mac] = v[i-1].mac;
        else
            pos[v[i].mac] = -INF;
    }

    for (int i = 1; i <= n; i++) {
        int dist = get_distance(i);
        int mv = 1;

        while (mv <= N && size[mv] < dist) {
            s[mv]++;
            mv++;
        }

        while (i == q.front()) {
            put_ans();

            q.pop();
            if (q.empty())
                break;
        }
        hit(pos[i]);
    }

    while (!q.empty())
        q.pop();
}
