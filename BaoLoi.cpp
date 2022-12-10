#include <bits/stdc++.h>
#pragma ("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll  long long
#define db  double
#define str string
#define vl  vector<ll>
#define pii pair<int, int>
#define pll  pair<ll, ll>
#define vpii vector<pii>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sqr(i) i * i
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const db pi = acos(1);
const int MOD = 1e9 + 19972207;
const ll INF = 1e18;
const int MAXN = 300005;
const int EPS = 1e-9;

struct point {
    db x, y;
    point() { x = y = 0.0; }
    point(db _x, db _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y  - other.y) < EPS)); 
    }
};

db dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

db DEG_TO_RAD(db d) {
    return d * pi / 180.0; 
}
db RAD_TO_DEG(db d) {
    return d * 180.0 / pi;
}

point rotation(point p, db alpha) {
    db rad = DEG_TO_RAD(alpha);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

point rotations(point p1, point p2, db alpha) {
    db rad = DEG_TO_RAD(alpha);
    point p3, p4;
    p3.x = p1.x - p2.x;
    p3.y = p1.y - p2.y;
    p4 = point(p3.x * cos(rad) - p3.y * sin(rad), p3.x * sin(rad) + p3.y * cos(rad));
    return point(p4.x + p2.x, p4.y + p2.y);
}

struct line {
    db a, b, c;
};

line makeLine(point p1, point p2) {
    line l1;
    if(p1.x == p2.x) {
        l1.a = 1;
        l1.b = 0;
        l1.c = - p1.x;
    } else {
        l1.a = (p2.y - p1.y) / (p1.x - p2.x);
        l1.b = 1;
        l1.c = - (l1.a) * p1.x - p1.y;
    }
    return l1;
}

bool Parallel(line l1, line l2) { // Kiem tra song song
    return (l1.a == l2.a) && (l1.b == l2.b);
}

bool Same(line l1, line l2) { // kiem tra trung
    return Parallel(l1, l2) && (l1.c == l2.c);
}

bool Intersect(line l1, line l2, point &p) { // kiem tra l1 co cat l2 hay ko
    if(Parallel(l1, l2)) return false;
    p.x = (l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
    p.y = (l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    return true;
}

struct vect {
    db x, y;
    vect(db _x, db _y) {
        x = _x;
        y = _y;
    }
};

vect operator + (const point &B, const point &A) {
    return vect(B.x + A.x, B.y + A.y);
}

vect operator - (const point &B, const point &A) { // vecAB = B - A
    return vect(B.x - A.x, B.y - A.y);
}

vect getVect(point a, point b) { // lay vector
    return vect(b.x - a.x, b.y - a.y);
}

vect scale(vect v, db k) { // nhan vector voi 1 so nguyen k != 0
    return vect(v.x * k, v.y * k);
}

point translate(point p, vect v) { // tinh tien diem p theo vector v
    return point(v.x + p.x, v.y + p.y);
}

db getLength(vect v) { // do dai vector v
    return hypot(v.x, v.y);
}

db sqrLen(vect v) { // binh phuong do dai vector
    return v.x * v.x + v.y * v.y;
}

db scalar(vect v1, vect v2) { // tich vo huong 2 vector v1 va v2
    return (v1.x * v2.x + v1.y * v2.y);
}

db cross(vect v1, vect v2) { // tich co huong 2 vector v1 va v2
    return (v1.x * v2.y - v1.y * v2.x);
}

db getLength_sq(vect v) {
    return v.x * v.x + v.y * v.y;
}

db distToLine(point p, point a, point b) {
    vect AP = getVect(a, p), AB = getVect(a, b);
    db k = scalar(AP, AB) / getLength_sq(AB);
    point c = translate(a, scale(AB, k));
    return dist(p, c);
}

db distToLineSegment(point p, point a, point b) {
    vect AP = getVect(a, p), AB = getVect(a, b);
    db k = scalar(AP, AB) / getLength_sq(AB);
    if(k < 0.0) {
        return dist(p, a);
    }
    if(k > 1.0) {
        return dist(p, b);
    }
    return distToLine(p, a, b);
}

void FindFootOfTheAltitude(point A, point B, point C, point &cur) { // Tim toa do chan duong cao
    line l = makeLine(B, C);
    double ans = -(l.a * A.x + l.b * A.y + l.c) / (l.a * l.a + l.b * l.b);
    cur.x = ans * l.a + A.x;
    cur.y = ans * l.b + A.y;
}

db slope(point A, point B) { // Tim he co so
    if(B.x - A.x != 0)
        return (B.y - A.y) / (B.x - A.x);
    return 1e8;
}

void FindIntersect(point A, point B, point C, point D, point &cur) {   // Tim toa do giao diem cua 2 doan thang
    long double a1 = B.y - A.y;
    long double b1 = A.x - B.x;
    long double c1 = a1 * (A.x) + b1 * (A.y);
    long double a2 = D.y - C.y;
    long double b2 = C.x - D.x;
    long double c2 = a2 * (C.x) + b2 * (C.y);
    long double determinant = a1*b2 - a2*b1;
    if(determinant == 0) {
        cur.x = FLT_MAX;
        cur.y = FLT_MAX;
    }
    else {
        cur.x = 1.0*(b2*c1 - b1*c2)/determinant;
        cur.y = 1.0*(a1*c2 - a2*c1)/determinant;
    }
}

int CCW(point A, point B, point C) {
    vect AB = getVect(A, B);
    vect AC = getVect(A, C);
    if(cross(AB, AC) > 0) 
        return 1;  // diem C nam phia tren doan thang AB
    else
    if(cross(AB, AC) < 0) 
        return -1; // diem C nam phia duoi doan thang AB
    return 0; 
}

map<pll, ll> res;
int n, m;
point q[MAXN], p[MAXN], A;

bool CCWInConvexHull(const point& D, const point& E, const point& F){
    return cross(E - D, F - E) > 0;
}

void GrahamScan(){
    sort(p+1, p+n, [](const point& B, const point& C){
        vect u = B - A, v = C - A;
        ll temp = cross(u, v);
        return temp > 0 || (temp == 0 && sqrLen(u) < sqrLen(v));
    });
}

void BuildConvexHull(){
    m = 0;
    for(int i = 0; i < n; i++){
        while (m >= 2 && !CCWInConvexHull(q[m - 2], q[m - 1], p[i]))
            m--;
        q[m++] = p[i];
    }
}

db AreaOfTriangle(point c, point a, point b) {
    return ((db) 1 / 2 * distToLineSegment(c, a, b) * dist(a, b));
}

db quadrilateral(const point& A, const point& B, const point& C, const point& D){
    return abs(((A.x * B.y+B.x * C.y+C.x * D.y+D.x * A.y) - 
        (A.y * B.x+B.y * C.x+C.y * D.x+D.y * A.x))) / 2;
}

void solve() {
    cin >> n;
    ll pos = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        res[{p[i].x, p[i].y}] = i + 1;
    }
    A = p[0];
    for(int i = 1; i < n; i++){
        if(p[i].y < A.y){
            A = p[i];
            pos = i;
        }
        if(p[i].y == A.y){
            if(p[i].x < A.x){
                A.x = p[i].x;
                pos = i;
            }
        }
    }
    swap(p[0], p[pos]);
    GrahamScan();
    BuildConvexHull();
    cout << m << '\n';
    ll ans = 0;
    q[m] = q[0];
    for(int i = 1; i <= m; i++) 
        ans += (q[i - 1].x * q[i].y) - (q[i - 1].y * q[i].x);
    ans = abs(ans);
    vl cur;
    for(int i = 0; i < m; i++) {
        ll tmp = res[{q[i].x, q[i].y}];
        cur.pb(tmp);
    }
    sort(cur.begin(), cur.end());
    for(int i = 0; i < m; i++) {
        cout << q[i].x << " " << q[i].y << '\n';
    }
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
