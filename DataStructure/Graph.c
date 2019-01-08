#include"Graph.h"

Graph* CreateGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->VertexCount = 0;
	return graph;
}

void DestroyGraph(Graph * graph)
{
	while (graph->Vertices != NULL) {
		Vertex* vertices = graph->Vertices->Next;
		DestroyVertex(graph->Vertices);
		graph->Vertices = vertices;
	}
	free(graph);
}

Vertex * CreateVertex(ElementType data)
{
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->AdjList = NULL;
	vertex->Data = data;
	vertex->Index = -1;
	vertex->Next = NULL;
	vertex->Visited = NotVisited;
	return vertex;
}

void DestroyVertex(Vertex * vertex)
{
	while (vertex->AdjList != NULL) {
		Edge* edge = vertex->AdjList->Next;
		DestroyEdge(vertex->AdjList);
		vertex->AdjList = edge;
	}

	free(vertex);
}

Edge * CreateEdge(Vertex * from, Vertex * to, int weight)
{
	Edge* edge = (Edge*)malloc(sizeof(Edge));
	edge->From = from;
	edge->To = to;
	edge->Next = NULL;
	edge->Weight = 0;
	return edge;
}

void DestroyEdge(Edge * edge)
{
	free(edge);
}

void AddVertex(Graph * graph, Vertex * vertex)
{
	Vertex* vertexList = graph->Vertices;

	if (vertexList == NULL) {
		graph->Vertices = vertex;
	}
	else {
		while (vertexList->Next != NULL) {
			vertexList = vertexList->Next;
		}
		vertexList->Next = vertex;
	}
	vertex->Index = graph->VertexCount++;
}

void AddEdge(Vertex * vertex, Edge * edge)
{
	if (vertex->AdjList == NULL) {
		vertex->AdjList = edge;
	}
	else {
		Edge* AdjList = vertex->AdjList;
		while (AdjList->Next != NULL) {
			AdjList = AdjList->Next;
		}

		AdjList->Next = edge;
	}
}

void PrintGraph(Graph * graph)
{
	Vertex* vertex = NULL;
	Edge* edge = NULL;

	if ((vertex = graph->Vertices) == NULL) {
		return;
	}

	while (vertex != NULL) {
		printf("%d : ", vertex->Data);

		if ((edge = vertex->AdjList) == NULL) {
			vertex = vertex->Next;
			printf("\n");
			continue;
		}

		while (edge != NULL) {
			printf("%d[%d] ", edge->To->Data, edge->Weight);
			edge = edge->Next;
		}

		printf("\n");
		vertex = vertex->Next;
	}

	printf("\n");
}
