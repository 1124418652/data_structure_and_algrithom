#include <iostream>
#include "../include/graph_search.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<int> > graph = {{1, 0, 0, 0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 1, 1, 0, 1},
                                  {1, 0, 0, 1, 0, 1, 0, 0},
                                  {1, 1, 0, 0, 0, 1, 0, 0}};
    GraphSearch<int> search(graph, true, true);
    vector<vector<int> > res;
    std::cout << "num: " << search.globalSearch(res) << endl;
    for (size_t row = 0; row < res.size(); ++row){
        for (size_t col = 0; col < res[0].size(); ++col){
            cout << res[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}