class Point {
    private:
        int x,y;
    
    public:
        Point (int x = 0, int y = 0) { this->x = x; this->y = y; }
        int getX() const { return x; }
        int getY() const { return y; }
        void setX(const int new_x) { x = new_x; }
        void setY(const int new_y) { x = new_y; }
};

class PointArray {
    private:
        Point *points;
        int size;
    
    public:
        PointArray();
        PointArray(const Point points[],const int size);
        PointArray(const PointArray& pv);
        ~PointArray();
        
        void resize(int n);
        void push_back(const Point &p);
        void insert(const int position, const Point &p);
        void remove(const int position);
        const int getSize() const;
        void clear();
        Point * get (const int pos) ;
        const Point * get (const int pos) const ;
};

class Polygon {
    protected:
        PointArray points;
        static int numPolygons;
    
    public:
        Polygon(const Point points[], const int size);
        Polygon(const PointArray &pointarr);
        ~Polygon();
        virtual double area() const = 0;
        static int getNumPolygons() { return numPolygons; }
        int getNumSides() { return points.getSize(); }
        const PointArray *getPoints() const { return &points; }
        
};

class Rectangle : public Polygon {
    public:
        Rectangle(const Point &pt1, const Point &pt2);
        Rectangle(const int a, const int b, const int c, const int d);
        virtual double area() const;
    
};

class Triangle : public Polygon {
    public:
        Triangle(const Point &pt1, const Point &pt2, const Point &pt3);
        virtual double area() const;
};





