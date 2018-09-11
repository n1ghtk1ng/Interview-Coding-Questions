 /* Jarvis March is finding convex or gift wrapping algorithm.

  Time complexity O(nh)
     n - number of points
     h - number of points on the boundary.
     Worst case O(n^2)

  Space complexity O(n^2)
  */
#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    bool operator<(const Point &other) const {
        if(x<other.x){
            return true;
        }
        else if(x==other.x){
            if(y<other.y){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    void print(){
        cout<<"x = "<<x<<" y = "<<y<<endl;
    }
};
int crossProduct(Point a, Point b, Point c) {
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return y2 * x1 - y1 * x2;
}
int distance(Point a, Point b, Point c) {
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    int t=(y1 * y1 + x1 * x1)-(y2 * y2 + x2 * x2);
//    cout<<"t = "<<t<<endl;
    return ((y1 * y1 + x1 * x1)-(y2 * y2 + x2 * x2));
    /**
     * Returns < 0 if 'b' is closer to 'a' compared to 'c', == 0 if 'b' and 'c' are same distance from 'a'
     * or > 0 if 'c' is closer to 'a' compared to 'b'.
     */
}
bool isequal(Point a,Point b){
if(a.x==b.x && a.y==b.y){
    return true;
}
return false;
}



set<Point>findConvexHull(vector<Point>points) {
        //first find leftmost point to start the march.
    Point start = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < start.x) {
            start = points[i];
        }
    }
    Point current = start;
//    current.print();
    //use set because this algorithm might try to insert duplicate point.
    set<Point> result;
    result.insert(start);
    set<Point> collinearPoints;
    while (true) {
//        current.print();
        Point nextTarget = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (isequal(points[i],current)) {
                continue;
            }
//            cout<<"current --> ";
//            current.print();
//            cout<<"nexttarget --> ";
//            nextTarget.print();
//            cout<<"points[i] -->";
//            points[i].print();
//            cout<<endl;
            int val = crossProduct(current, nextTarget, points[i]);
            //if val > 0 it means points[i] is on left of current -> nextTarget. Make him the nextTarget.
            if (val > 0) {
                nextTarget = points[i];
                //reset collinear points because we now have a new nextTarget.
                collinearPoints.clear();
            } else if (val == 0) { //if val is 0 then collinear current, nextTarget and points[i] are collinear.
                //if its collinear point then pick the further one but add closer one to list of collinear points.
                if (distance(current, nextTarget, points[i]) < 0) {
                    collinearPoints.insert(nextTarget);
                    nextTarget = points[i];
                } else { //just add points[i] to collinearPoints list. If nextTarget indeed is the next point on
                    //convex then all points in collinear points will be also on boundary.
                    collinearPoints.insert(points[i]);
                }
            }
            //else if val < 0 then nothing to do since points[i] is on right side of current -> nextTarget.
        }

        //add all points in collinearPoints to result.
        for(auto it=collinearPoints.begin();it!=collinearPoints.end();it++){
            result.insert(*it);
        }

        //if nextTarget is same as start it means we have formed an envelope and its done.
        if (isequal(nextTarget,start)) {
            break;
        }
        //add nextTarget to result and set current to nextTarget.
        result.insert(nextTarget);
//        cout<<"result is -->"<<endl;
/*
        for(auto it=result.begin();it!=result.end();it++){
            cout<<it->x<<" "<<it->y<<endl;
        }*/
//        cout<<endl;

        current = nextTarget;
    }
    return result;
}

int main() {
    vector<Point>points;

    Point a(0,3);
    Point b(2,2);
    Point c(1,1);
    Point d(2,1);
    Point e(3,0);
    Point f(0,0);
    Point g(3,3);

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);
    points.push_back(g);

    /*set<Point>s=findConvexHull(points);
    for(auto it=s.begin();it!=s.end();it++){
        cout<<it->x<<" "<<it->y<<endl;
    }*/
    int t=pow(2,31)-1;
    cout<<t<<endl;
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;

    return 0;
}
