#ifndef GRAPH_SEARCH_H_
#define GRAPH_SEARCH_H_

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

template <typename DataT>
class GraphSearch
{
    typedef struct Coord{
        int row;
        int col;
        Coord(int _row, int _col): row(_row), col(_col){}
    }Coord;

public:

    /** \brief 构造函数，初始化成员变量
      * param[in] graph 二维向量表示的图结构
      * param[in] breadth_first 布尔类型值，表示是否使用广度优先搜索
      * param[in] eight_beighber 布尔类型值，表示使用八邻域或四邻域
      */
    GraphSearch(const std::vector<std::vector<DataT> > &graph, 
                bool breadth_first = true, bool eight_neighber = true);
    
    /** \brief 析构函数，释放动态分配的内存空间 */
    virtual 
    ~GraphSearch();

    void 
    singleSearch(Coord begin, int label, bool breadth_first = true);

    int 
    globalSearch(std::vector<std::vector<int> > &res);

protected:

    std::vector<std::vector<DataT> > graph;
    std::vector<std::vector<int> > res;
    std::vector<Coord> bias_coord;
    int **visit;
    int _rows;
    int _cols;
    bool breadth_first;
    bool eight_neighber;
};

#include "impl/graph_search.hpp"

#endif // !GRAPH_SEARCH_H_