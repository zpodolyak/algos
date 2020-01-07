#include <vector>
#include <queue>
#include <limits>
#include <functional>

struct node {
    int id;
    int weight;
    
    bool operator>(node const& other) const {
        return weight>other.weight;
    }
};

std::vector<int> graphDistances(std::vector<std::vector<int>> g, int s) {
    std::vector<int> result(g.size(), std::numeric_limits<int>::max());
    result[s]=0;  
    std::priority_queue<node, std::vector<node>, std::greater<>> q;     

    q.push({s, 0});
    while(!q.empty()) {
        auto curr = q.top();
        q.pop();
    
        int n = curr.id;
        for(int j=0; j<g.size(); ++j)
            if(g[n][j] != -1)
                if(result[n]+g[n][j] < result[j]) 
                    result[j] = result[n]+g[n][j], q.push({j,g[n][j]});
    }
    return result;
}
