#include <string>
#include <unordered_map>
#include <vector>

#include "union_find.hpp"

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    // 使用带权值的并查集来实现
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // 首先对数据进行预处理，将其加入并查集
        unordered_map<string, int> map(equations.size() * 2);
        UnionFind u(equations.size() * 2);
        int id = 0;
        for (int i = 0; i < equations.size(); i++) {
            string val1 = equations[i][0];
            string val2 = equations[i][1];

            if (!map.count(val1)) {
                map[val1] = id++;
            }

            if (!map.count(val2)) {
                map[val2] = id++;
            }

            u.union_(map[val1], map[val2], values[i]);
        }

        vector<double> results;
        for (int i = 0; i < queries.size(); i++) {
            string val1 = queries[i][0];
            string val2 = queries[i][1];

            if (!map.count(val1) || !map.count(val2))
                results.push_back(-1.0);
            else
                results.push_back(u.isConnected(map[val1], map[val2]));
        }

        return results;
    }
};