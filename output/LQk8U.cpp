// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-09-27 16:01:48
// status:	0
// result:	15
// memory:	2724
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <numeric>

struct GEOGRAPHIC_REGION
{    
    float fNorthMost;
    float fSouthMost;
    float fWestMost;
    float fEastMost;
};

GEOGRAPHIC_REGION combine(const GEOGRAPHIC_REGION& accum, const GEOGRAPHIC_REGION& tocombine)
{
    GEOGRAPHIC_REGION combined = { 
        std::max(accum.fNorthMost, tocombine.fNorthMost),
        std::min(accum.fSouthMost, tocombine.fSouthMost),
        std::min(accum.fWestMost,  tocombine.fWestMost),
        std::max(accum.fEastMost,  tocombine.fEastMost)
    };
    return combined;
}

int main()
{
    const GEOGRAPHIC_REGION regions[] = 
    {
        { 2,-1,-1,1 },
        { 1,-2,-1,1 },
        { 1,-1,-2,1 },
        { 1,-1,-1,2 },
    };

    GEOGRAPHIC_REGION super = std::accumulate(regions, regions+4, regions[0], combine);

    std::cout << "{ " << super.fNorthMost << ", " 
                      << super.fSouthMost << ", "
                      << super.fWestMost << ", "
                      << super.fEastMost << " }" << std::endl;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
{ 2, -2, -2, 2 }

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
