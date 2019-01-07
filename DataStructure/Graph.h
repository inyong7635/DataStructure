#pragma once
#ifndef  GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct tagVertex {
	ElementType Data;
	int Visited;
	int Index;

	struct tageVertex* Next;
	Edge* AdjList;
}Vertex;

typedef struct tagEdge {
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* To;
}Edge;

typedef struct tagGraph {
	Vertex* Vertices;
	int VertexCount;
}Graph;

Graph* CreatGraph();
void DestroyGraph(Graph *graph);

Vertex* CreateVertex(ElementType data);
void DestroyVertex(Vertex* vertex);

Edge* CreateEdge(Vertex* from, Vertex* to, int weight);
void DestroyEdge(Edge* edge);

void AddVertex(Graph* graph, Vertex* vertex);
void AddEdge(Vertex* vertex, Edge* edge);
void PrintGraph(Graph* graph);

#endif