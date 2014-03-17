// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-10-31 01:52:19
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>

struct extrapolate
{
     extrapolate(double slope, double x1, double y1) 
         : _slope(slope), _x1(x1), _y1(y1) 
     {
     }

     double y(double x) const // return y for given x
     {
          return _y1 + (x-_x1)*_slope;                  
     }

  private:
     double _slope, _x1, _y1;
};

int main()
{
    extrapolate line1(0.5, 1, 1);
    for (int i=-3; i<3; i++)
    {
        double x = i;
        double y = line1.y(x);

        std::cout << "(" << x << ", " << y << "), ";
    }
    std::cout << std::endl;

    extrapolate line2(-5, -3, -3);
    for (int i=-3; i<3; i++)
    {
        double x = i;
        double y = line2.y(x);

        std::cout << "(" << x << ", " << y << "), ";
    }
    std::cout << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
(-3, -1), (-2, -0.5), (-1, 0), (0, 0.5), (1, 1), (2, 1.5), 
(-3, -3), (-2, -8), (-1, -13), (0, -18), (1, -23), (2, -28), 

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
