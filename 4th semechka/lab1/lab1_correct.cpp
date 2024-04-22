#include <iostream>
#include <vector>
#include <cmath>

/*
Нахождение выпуклой оболочки множества точек

В данной задаче требуется ввести N точек своими координатами (x,y). 
Затем требуется определить, существует ли выпуклая оболочка заданного множества точек.
При этом можно использовать:
или алгоритм Грэхема, или алгоритм Джарвиса, или метод «разделяй и властвуй»
*/

class Spot
{
private:

    double x_m = 0;
    double y_m = 0;

public:

    Spot(double x, double y) : x_m(x), y_m(y) {};

    Spot(Spot* x) : x_m(x->get_x()), y_m(x->get_y()) {};

    double get_x() { return x_m; };

    double get_y() { return y_m; };

    void set_x(double x) { x_m = x; }

    void set_y(double y) { y_m = y; }

    bool operator == (const Spot& spot) const
    {
        return ((x_m == spot.x_m) and (y_m == spot.y_m));
    }

};

void PrintSpots(std::vector <Spot> spots)
{
    if (spots.size() < 3)
    {
        std::cout << "Cannot build the convex hull." << std::endl;
    }
    for (int i = 0; i < spots.size(); i++)
    {
        std::cout << "(" << spots[i].get_x() << " , " << spots[i].get_y() << ")" << std::endl;
    }
}

int LeftOrient(Spot start, Spot end1, Spot end2)
{
    double t1 = (end1.get_y() - start.get_y()) * (end2.get_x() - end1.get_x());

    double t2 = (end2.get_y() - end1.get_y()) * (end1.get_x() - start.get_x());

    // сравниваем вершины
    if (t1 < t2)
    {
        return  1;
    }
    else if (t1 == t2)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void PointSwap(Spot* p1, Spot* p2)
{
    Spot temp(p1->get_x(), p1->get_y());

    p1->set_x(p2->get_x());
    p1->set_y(p2->get_y());

    p2->set_x(temp.get_x());
    p2->set_y(temp.get_y());


}

Spot MinPoint(std::vector <Spot> spots)
{
    int size = spots.size();

    int l = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - l - 1; j++)
        {
            if (spots[j].get_x() > spots[j + 1].get_x())
            {
                PointSwap(&spots[j], &spots[j + 1]);
            }
        }
        l++;
    }

    return spots[0];
}

Spot BiggestDist(Spot start, Spot end1, Spot end2)
{
    double dist_1 = sqrt(pow((end1.get_x() - start.get_x()), 2) + pow(end1.get_y() - start.get_y(), 2));
    double dist_2 = sqrt(pow((end2.get_x() - start.get_x()), 2) + pow(end2.get_y() - start.get_y(), 2));
    
    if (dist_1 >= dist_2) 
    { 
        return end1; 
    }
    else
    {
        return end2;
    }
}

std::vector <Spot> JarvisAlg(std::vector <Spot> spots)
{
    int size = spots.size();
    Spot current = MinPoint(spots);
    std::vector <Spot> path;

    bool flag = true;

    while (flag)
    {
        path.push_back(current);

        Spot next = spots[0];

        for (int x = 0; x < size; x++)
        {
            int p = LeftOrient(current, next, spots[x]);

            if ((next == current) or p == 1)
            {
                next = spots[x];
            }
            if (p == 0)
            {
                next = BiggestDist(current, next, spots[x]);
            }
        }

        current = next;

        if (current == path[0])
        {
            flag = false;
        }
    }
    return path;
}


int main()
{
    Spot p1(0, 0);
    Spot p2(0, 10);
    Spot p3(100, 0);
    Spot p4(50, 50);
    Spot p5(0, 100);
    Spot p6(11, 0);
    Spot p7(10, 0);
    Spot p8(15, 0);
    Spot p9(45, 20);

    std::vector<Spot> forhull;

    forhull.push_back(p1);
    forhull.push_back(p2);
    forhull.push_back(p3);
    forhull.push_back(p4);
    forhull.push_back(p5);
    forhull.push_back(p6);
    forhull.push_back(p7);
    forhull.push_back(p8);
    forhull.push_back(p9);

    std::vector<Spot> hullpath = JarvisAlg(forhull);

    PrintSpots(hullpath);
}