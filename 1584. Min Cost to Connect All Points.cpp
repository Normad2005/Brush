#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:

    int id[1010];
    int size[1010];
    void init(){
        for(int i=0;i<1010;i++){
            size[i] = 1;
            id[i] = i;
        }
            
        
    }
    int find(int i){
        if(i != id[i])
            id[i] = find(id[i]);
        return id[i];
    }

    void Union(int p, int q){
        int proot = find(p);
        int qroot = find(q);
        if(size[proot] > size[qroot]){
            id[qroot] = proot;
            size[proot] += size[qroot];
        }
        else{
            id[proot] = qroot;
            size[qroot] += size[proot];
        }
    }
    struct Edge {
        int u, v, w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };

    vector<Edge > edges;
    int manhattan(const vector<int > &a, const vector<int > &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    static bool cmp(const Edge &a, const Edge &b){
        return a.w < b.w;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        init();
        int cost = 0;
        for(int i=0;i<points.size();i++)
            for(int j=i+1;j<points.size();j++){
                    int dist = manhattan(points[i], points[j]);
                    Edge e(i, j, dist);
                    edges.push_back(e);
            }
        
        sort(edges.begin(), edges.end(), Solution::cmp);

        for(int i=0;i<edges.size();i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if(find(u) != find(v)){
                Union(u, v);
                cost += w;
            }
        }
        return cost;
    }
    
};