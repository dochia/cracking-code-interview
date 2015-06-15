#include <list>
#include <queue>
using namespace std;

typedef struct Vertex
{
        int info;
        Vertex* next;     
} vertex;


class DirectedGraph
{
     private:
             list<vertex*> mVertices;
     public:
            void addVertex(int info);
            void addArc(int a, int b);
            vertex* getVertex(int info); 
            int countVertices();
            queue<int> BFS(int info); 
            bool isSReachableFromT(int t, int s);
};
