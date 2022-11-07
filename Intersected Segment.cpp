struct Point {
    db x, y;
    Point() { x = y = 0.0; }
    Point(db _x, db _y) : x(_x), y(_y) {}
};

struct Vec {
    db x, y;
    Vec(db _x, db _y) {
        x = _x;
        y = _y;
    }
};

Vec operator - (const Point &B, const Point &A) { 
    return Vec(B.x - A.x, B.y - A.y);
}
int sign(double x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}
double cross(Vec AB, Vec AC) {
    return AB.x * AC.y - AC.x * AB.y;
}
double dot(Vec AB, Vec AC) {
    return AB.x * AC.x + AB.y * AC.y;
}
bool intersect(Point A, Point B, Point C, Point D) {
    int ABxAC = sign(cross(B - A, C - A));
    int ABxAD = sign(cross(B - A, D - A));
    int CDxCA = sign(cross(D - C, A - C));
    int CDxCB = sign(cross(D - C, B - C));
    if (ABxAC == 0 || ABxAD == 0 || CDxCA == 0 || CDxCB == 0) {
        if (ABxAC == 0 && sign(dot(A - C, B - C)) <= 0) return true;
        if (ABxAD == 0 && sign(dot(A - D, B - D)) <= 0) return true;
        if (CDxCA == 0 && sign(dot(C - A, D - A)) <= 0) return true;
        if (CDxCB == 0 && sign(dot(C - B, D - B)) <= 0) return true;
        return false;
    }
    return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}
