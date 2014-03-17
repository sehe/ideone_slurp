// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-08-30 00:25:41
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	false
// ------------------------------------------------
#include <fstream>
#include <cstdlib>

int main(int i,const char**v)
{
    for(int n=0; n<atoi(v[2]); ++n)
    {
        std::ifstream ifs(v[1]);
        *v="out.txt";
        char b[40][83], O[]="...X.....";
        for(i=0; i<40; ++i)
        {
            ifs>>b[i];
        }
        std::ofstream ofs(*v);
        ofs<<b[0]<<'\n';
        for(i=1; i<39; ++i)
        {
            ofs<<'.';
            for(int j=1; j<79; ++j)
            {
                O[2] = b[i][j];
                ofs << O[
                    (b[i+-1][j+0]   == 'X')
                    +(b[i+1][j+0]   == 'X')
                    +(b[i+0][j+-1]  == 'X')
                    +(b[i+0][j+1]   == 'X')
                    +(b[i+-1][j+-1] == 'X')
                    +(b[i+1][j+1]   == 'X')
                    +(b[i+1][j+-1]  == 'X')
                    +(b[i+-1][j+1]  == 'X')];
            }
            ofs<<".\n";
        }
        ofs<<b[0]<<'\n';
    }
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
