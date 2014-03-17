// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-05 14:38:12
// status:	0
// result:	15
// memory:	3436
// signal:	0
// public:	false
// ------------------------------------------------
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cassert>
#include <tuple>

struct Vector3
{
    float x, y, z;

    Vector3() {}

    Vector3(float xx, float yy, float zz)
    {
        x = xx, y = yy, z = zz;
    }

    inline bool operator==(const Vector3& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool operator<(const Vector3& other) const
    {
        return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
};

std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
{
    return stream 
        << "(" 
        << std::setw(2) << std::setfill(' ') << vector.x << ", " 
        << std::setw(2) << std::setfill(' ') << vector.y << ", " 
        << std::setw(2) << std::setfill(' ') << vector.z 
        << ")";
}

struct Edge
{
    Vector3 EndPoints[2];

    Edge() {}

    Edge(Vector3 p, Vector3 q)
    {
        // swap order
        if (q < p) { using std::swap; swap(p, q); } // the invariant
        EndPoints[0] = p;
        EndPoints[1] = q;
    }

    inline bool operator==(const Edge& other) const {
        return std::tie(EndPoints[0], EndPoints[1]) == std::tie(other.EndPoints[0], other.EndPoints[1]);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Edge& vector);
    friend std::ostream& operator<<(std::ostream& stream, const Edge* vector);
};

struct EdgePtrEqual {
    bool operator()(Edge const* a, Edge const* b) const {
        return *a == *b;
    }
};

std::ostream& operator<<(std::ostream& stream, const Edge& edge)
{
    return stream << edge.EndPoints[0] << " -- " << edge.EndPoints[1];
}

std::ostream& operator<<(std::ostream& stream, const Edge* edge)
{
    return stream << edge->EndPoints[0] << " -- " << edge->EndPoints[1];
}


namespace std
{
    template <> struct hash<Edge>
    {
        std::size_t operator()(const Edge& edge) const {
            Vector3 p0 = edge.EndPoints[0];
            Vector3 p1 = edge.EndPoints[1];

            assert(p0 < p1); // the invariant

            auto hash_p = [](Vector3 const& p) { return (unsigned(p.x*73856093u) ^ unsigned(p.y*19349663u) ^ unsigned(p.z*83492791u)) % 1024u; };

            return hash_p(p0) ^ (hash_p(p1) << 3);
        }
    };

    template <> struct hash<Edge*> {
        std::size_t operator()(const Edge* edge) const { 
            return hash<Edge>()(*edge); 
        }
    };
}

using EdgeSet    = std::unordered_set<Edge,  std::hash<Edge>>;
using EdgePtrSet = std::unordered_set<Edge*, std::hash<Edge*>, EdgePtrEqual>;

void add_edge(EdgeSet& table, Edge edge)
{
    EdgeSet::const_iterator it = table.find(edge);
    if (it == table.end()) table.insert(edge);
    else std::cout << "Table already contains edge " << edge << std::endl;
}

void add_edge(EdgePtrSet& table, Edge* edge)
{
    EdgePtrSet::const_iterator it = table.find(edge);
    if (it == table.end()) table.insert(edge);
    else std::cout << "Table already contains edge " << edge << std::endl;
}


void print_table(EdgeSet& table)
{
    std::cout << std::endl;
    std::cout << "Table has " << table.size() << " elements:" << std::endl;

    for (auto it = table.begin(); it != table.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << std::endl;
}

void print_table(EdgePtrSet& table)
{
    std::cout << std::endl;
    std::cout << "Table has " << table.size() << " elements:" << std::endl;

    for (auto it = table.begin(); it != table.end(); ++it)
        std::cout << *(*it) << std::endl;

    std::cout << std::endl;
}


int main()
{
    EdgeSet table;
    EdgePtrSet ptable;

    Edge e0(Vector3( 1.f,  0.f,  0.f), Vector3(-1.f,  0.f,  0.f));
    Edge e1(Vector3(-1.f,  0.f,  0.f), Vector3( 1.f,  0.f,  0.f));

    add_edge(table, e0);
    add_edge(table, e1);

    print_table(table);

    add_edge(ptable, &e0);
    add_edge(ptable, &e1);

    print_table(ptable);

    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
Table already contains edge (-1,  0,  0) -- ( 1,  0,  0)

Table has 1 elements:
(-1,  0,  0) -- ( 1,  0,  0)

Table already contains edge (-1,  0,  0) -- ( 1,  0,  0)

Table has 1 elements:
(-1,  0,  0) -- ( 1,  0,  0)


#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
