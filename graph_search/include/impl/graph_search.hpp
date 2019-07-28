#ifndef IMPL_GRAPH_SEARCH_HPP_
#define IMPL_GRAPH_SEARCH_HPP_

#include "../graph_search.h"

template<typename DataT>
GraphSearch<DataT>::GraphSearch(const std::vector<std::vector<DataT> > &graph,
                                bool breadth_first, bool eight_neighber)
: breadth_first(breadth_first), eight_neighber(eight_neighber)
{
    if (graph.empty())
    {
        std::cerr << "Input can't be empty!" << std::endl;
        exit(-1);
    }
    _rows = graph.size();
    _cols = graph[0].size();
    this->graph = graph;
    visit = new int* [this->_rows];
    for (int row = 0; row < _rows; ++row)
    {
        visit[row] = new int [_cols];
        memset(visit[row], 0, _cols * sizeof(int));
        res.push_back(std::vector<int>(_cols, 0));
        std::cout << visit[row][_cols - 1] << std::endl;
    }
    if (eight_neighber)
    {
        bias_coord = std::vector<Coord>{{-1, -1}, {-1, 0},
                                        {-1, 1}, {0, 1},
                                        {1, 1}, {1, 0},
                                        {1, -1}, {0, -1}};
    }else   // 4邻域
    {
        bias_coord = std::vector<Coord>{{0, -1}, {-1, 0},
                                        {0, 1}, {1, 0}};
    }
}

template<typename DataT>
GraphSearch<DataT>::~GraphSearch()
{
    for (int row = 0; row < _rows; ++row)
        delete [] visit[row];
    delete visit;
}

template<typename DataT> void
GraphSearch<DataT>::singleSearch(Coord begin, int label,
    bool breadth_first)
{
    std::deque<Coord> tmp_deque;
    tmp_deque.push_back(begin);
    res[begin.row][begin.col] = label;
    while (!tmp_deque.empty())
    {
        Coord curr(0, 0);
        if (breadth_first)
        {
            curr = tmp_deque.front();
            tmp_deque.pop_front();
        }else
        {
            curr = tmp_deque.back();
            tmp_deque.pop_back();
        }
        for (auto bias: bias_coord)
        {
            int neighber_row = curr.row + bias.row;
            int neighber_col = curr.col + bias.col;
            if (neighber_row >=0 && neighber_row < _rows
                && neighber_col >= 0 && neighber_col < _cols
                && graph[neighber_row][neighber_col] > 0 
                && visit[neighber_row][neighber_col] == 0)
            {
                tmp_deque.push_back(Coord(neighber_row, neighber_col));
                visit[neighber_row][neighber_col] += 1;
                res[neighber_row][neighber_col] = label;
            }
        }
    }
}

template<typename DataT> int
GraphSearch<DataT>::globalSearch(std::vector<std::vector<int> > &res)
{
    int flag = 1;    // 区域标签
    int region_num = 0;
    for (int row = 0; row < _rows; ++row)
    {
        for (int col = 0; col < _cols; ++col)
        {
            if (visit[row][col] == 0 && graph[row][col] > 0)
            {
                Coord begin(row, col);
                this->singleSearch(begin, flag, this->breadth_first);
                flag++;
                region_num++;
            }
        }
    }
    res = this->res;
    return region_num;
}

#endif // !IMPL_GRAPH_SEARCH_HPP_