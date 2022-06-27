struct P {
    int x, y;
    void read() {
        cin >> x >> y;
    }

    P operator -=(P b) {
        return {x -= b.x, y -= b.y};
    }

    int operator *(P b) {
        return x * b.y - y * b.x;
    }
};

LD angle(P &p) {
    if (p.x == 0) {
        if (p.y == 0) {
            return INF;
        } else if (p.y > 0) {
            return PI / 2.0;
        } else {
            return -PI / 2.0;
        }
    }

    if (p.x > 0) {
        if (p.y > 0) {
            return atan2((LD)p.y, (LD)p.x);
        } else if (p.y == 0) {
            return 0;
        } else {
            return -atan2((LD)(-1 * p.y), (LD)p.x);
        }
    } else {
        if (p.y > 0) {
            return PI - atan2((LD)abs(p.y), (LD)abs(p.x));
        } else if (p.y == 0) {
            return -PI;
        } else {
            return -PI + atan2((LD)abs(p.y), (LD)abs(p.x));
        }
    }
}
