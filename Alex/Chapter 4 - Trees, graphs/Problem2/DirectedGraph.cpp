#include "DirectedGraph.h"
#include <list>
#include <vector>
#include <queue>

using namespace std;

void DirectedGraph::addArc(int a, int b)
{
     vertex* A = getVertex(a);
     vertex* B = getVertex(b);
     if (A == NULL || B == NULL)
     {
         printf("Graph doesn't contain both values(%d, %d) needed to add an arc.\n", a, b);      
     }
     else
     {
         while (A->next != NULL)
         {
               A = A->next;
         }
         vertex* aux = (vertex*)malloc(sizeof(vertex));
         aux->info = b;
         aux->next = NULL;
         A->next = aux;
         printf("Adding value %d to the list of adjancency list for Vertex with value %d.\n", b, a);
     }          
     
}

vertex* DirectedGraph::getVertex(int info)
{
        for (list<vertex*>::iterator it = mVertices.begin(); it != mVertices.end(); it++)
        {
            if ((*it)->info == info)
            {
                //printf("Vertex with info %d has been found in graph.\n", info);
                return *it;
            }
        }
        printf("Vertex with info %d has not been found in graph.\n", info);
        return NULL;
}

void DirectedGraph::addVertex(int info)
{
     bool isInList = false;
     for (list<vertex*>::iterator it = mVertices.begin(); it != mVertices.end(); it++)
     {
         if ((*it)->info == info)
         {
             isInList = true;
         }
     }
     if (isInList)
     {
         printf("Vertex with info %d already existed in the graph - no new vertex added.\n", info);
     }
     else
     {
         vertex* v = (vertex*) malloc(sizeof(vertex));
         v->info = info;
         v->next = NULL;
         printf("Vertex with info %d has been added to the graph.\n", info);
         mVertices.push_back(v);
         
     }
}

int DirectedGraph::countVertices()
{
    return mVertices.size();
}

queue<int> DirectedGraph::BFS(int info)
{
     int len = countVertices();
     vector<int> colors(len); // 0 - white, 1 - grey, 2 - black
     vector<int> d(len);
     queue<int> result;
     queue<int> q;
     for (int i = 0; i < len; i++)
     {
         colors[i] = 0;
         d[i] = 1000;
     }
     q.push(info);
     colors[info] = 1;
     d[info] = 0;
     while (!q.empty())
     {
           int u = q.front();
           vertex* temp = getVertex(u);
           while (temp != NULL)
           {
                 if (colors[temp->info] == 0)
                 {
                     colors[temp->info] = 1;
                     d[temp->info] = d[u] + 1;
                     q.push(temp->info);
                 }
                 temp = temp->next;
           } 
           colors[u] = 2;
           printf("%d ", u);
           result.push(u);
           q.pop();
     }
     printf("\n");
     return result;
}

bool DirectedGraph::isSReachableFromT(int t, int s)
{
     queue<int> bfs = BFS(t);
     while (!bfs.empty())
     {
           
           if (bfs.front() == s)
           {
               return true;
           }
           else
           {
               bfs.pop();
           }
     }
     return false;
}
