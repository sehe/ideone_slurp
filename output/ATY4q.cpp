// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2011-11-09 16:58:54
// status:	0
// result:	15
// memory:	2864
// signal:	0
// public:	true
// ------------------------------------------------
#include <iostream>
#include <fstream>
#include <boost/assign.hpp>
#include <boost/array.hpp>
#include <vector>
#include <set>

namespace mxdetail
{
    typedef size_t cell_id; // row * COLS + col

    template <typename T> struct area
    {
        T value;
        typedef std::vector<cell_id> cells_t;
        cells_t cells;
    };

    template <typename T, size_t Rows, size_t Cols>
        std::vector<area<T> > getareas(const boost::array<boost::array<T, Cols>, Rows>& matrix)
    {
        typedef boost::array<boost::array<T, Cols>, Rows> mtx;
        std::vector<area<T> > areas;

        struct visitor_t
        {
            const mtx& matrix;
            std::set<cell_id> visited;

            visitor_t(const mtx& mtx) : matrix(mtx) { }

            area<T> start(const int row, const int col)
            {
                area<T> result;
                visit(row, col, result);
                return result;
            }

            void visit(const int row, const int col, area<T>& current)
            {
                const cell_id id = row*Cols+col;
                if (visited.end() != visited.find(id))
                    return;

                bool matches = current.cells.empty() || (matrix[row][col] == current.value);

                if (matches)
                {
                    visited.insert(id);
                    current.value = matrix[row][col];
                    current.cells.push_back(id);

                    // process neighbours
                    for (int nrow=std::max(0, row-1); nrow < std::min((int) Rows, row+2); nrow++)
                    for (int ncol=std::max(0, col-1); ncol < std::min((int) Cols, col+2); ncol++)
                        /* if (ncol!=col || nrow!=row) */
                            visit(nrow, ncol, current);
                }
            }
        } visitor(matrix);

        for (int r=0; r < (int) Rows; r++)
            for (int c=0; c < (int) Cols; c++)
            {
                mxdetail::area<int> area = visitor.start(r,c);
                if (!area.cells.empty()) // happens when startpoint already visited
                    areas.push_back(area);
            }

        return areas;
    }
}


template <typename T, size_t N>
   boost::array<T, N> make_array(const T (&a)[N])
{
    boost::array<T, N> result;
    std::copy(a, a+N, result.begin());
    return result;
}

int main()
{
    typedef boost::array<int, 3> row;

    int row0[] = { 1  , 2, 3, };
    int row1[] = { 1  , 3, 3, };
    int row2[] = { 1  , 3, 3, };
    int row3[] = { 100, 2, 1, };

    boost::array<row, 4> matrix;
    matrix[0] = make_array(row0);
    matrix[1] = make_array(row1);
    matrix[2] = make_array(row2);
    matrix[3] = make_array(row3);

    typedef std::vector<mxdetail::area<int> > areas_t;
    typedef areas_t::value_type::cells_t cells_t; 

    areas_t areas = mxdetail::getareas(matrix);
    for (areas_t::const_iterator it=areas.begin(); it!=areas.end(); ++it)
    {
        std::cout << "area of " << it->value << ": ";
        for (cells_t::const_iterator pit=it->cells.begin(); pit!=it->cells.end(); ++pit)
        {
            int row = *pit / 3, col = *pit % 3;
            std::cout << "(" << row << "," << col << "), ";
        }
        std::cout << std::endl;
    }
    std::cout << "areas detected: " << areas.size() << std::endl;

}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
area of 1: (0,0), (1,0), (2,0), 
area of 2: (0,1), 
area of 3: (0,2), (1,1), (1,2), (2,1), (2,2), 
area of 100: (3,0), 
area of 2: (3,1), 
area of 1: (3,2), 
areas detected: 6

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
