#include"GraphTraversal.h"

void DFS(Vertex * vertex)
{
	Edge *edge = NULL;

	printf("%d ", vertex->Data);
	vertex->Visited = Visited;

	edge = vertex->AdjList;

	while (edge != NULL) {
		if (edge->To != NULL && edge->To->Visited == NotVisited) {
			DFS(edge->To);
		}
		edge = edge->Next;
	}
}
