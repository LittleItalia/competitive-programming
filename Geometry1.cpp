#define x first
#define y second
using pii = pair<int, int>;

// Tich vo huong 
int dot(pii A, pii B, pii C) {
    pii AB, AC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    return AB.x * AC.x + AB.y * AC.y;
}

// Tich co huong 2D
int cross(pii A, pii B, pii C) {
    pii AB, AC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    return AB.x * AC.y - AB.y * AC.x;
}

// Khoang cach tu A den B
double distance(pii A, pii B) {
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

// Khoang cach tu diem C den duong thang AB
double linePointDist(pii A, pii B, pii C, bool isSegment) {
    double dist = abs(cross(A, B, C)) / distance(A, B);
    if (isSegment) {
        int dot1 = dot(B, A, C);
        if (dot1 < 0) return distance(B, C);
        int dot2 = dot(A, B, C);
        if (dot2 < 0) return distance(A, C);
    }
    return dist;
}
