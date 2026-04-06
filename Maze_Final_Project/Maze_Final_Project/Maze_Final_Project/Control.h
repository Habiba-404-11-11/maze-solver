#ifndef CONTROL_H
#define CONTROL_H


struct Point {
    int r, c;

    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }

    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};
struct Cordinates {
    Point start;
	Point goal;
    int R = 15, C = 15;
	
};

struct DNode {
    int x, y;
    int cost;

    bool operator<(const DNode& other) const {
        return cost > other.cost; // Min-heap
    }
};

 struct BNode {
       int x, y;
       int cost;
   };

 struct ANode {
     int x, y;
     int g;
     int f;

     bool operator<(const ANode& other) const {
         if (f == other.f) return g > other.g;
         return f > other.f;
     }
 };

struct Bucket {
    MyVector<BNode> nodes;
    int size;
};



#endif