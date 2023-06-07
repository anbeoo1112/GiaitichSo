#include <iostream>

// Định nghĩa cấu trúc điểm 2D
struct Point {
    double x;
    double y;
};

// Tìm giao điểm của hai đường thẳng bằng phương pháp dây cung
bool findIntersection(const Point& p1, const Point& p2, const Point& p3, const Point& p4, Point& intersection) {
    double x1 = p1.x;
    double y1 = p1.y;
    double x2 = p2.x;
    double y2 = p2.y;
    double x3 = p3.x;
    double y3 = p3.y;
    double x4 = p4.x;
    double y4 = p4.y;

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denominator == 0) {
        // Hai đường thẳng song song
        return false;
    }

    double numeratorX = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    double numeratorY = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);

    intersection.x = numeratorX / denominator;
    intersection.y = numeratorY / denominator;

    return true;
}

int main() {
    // Định nghĩa các điểm của hai đường thẳng
    Point p1 = {0, 1};
    Point p2 = {1, 3};
    Point p3 = {0, 8};
    Point p4 = {1, 13};

    Point intersection;

    if (findIntersection(p1, p2, p3, p4, intersection)) {
        std::cout << "Giao điểm của hai đường thẳng là (" << intersection.x << ", " << intersection.y << ")" << std::endl;
    } else {
        std::cout << "Hai đường thẳng là song song và không có giao điểm." << std::endl;
    }

    return 0;
}
