#include <stdio.h>
#include <graphics.h>

#define MAX_VERTICES 10

// Function to draw the graph based on the adjacency matrix
void drawGraph(int adjacencyMatrix[][MAX_VERTICES], int numVertices)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define coordinates for drawing vertices
    int x[MAX_VERTICES] = {100, 200, 150, 300, 400, 350, 250, 500, 550, 450};
    int y[MAX_VERTICES] = {100, 200, 300, 400, 100, 200, 300, 400, 100, 200};

    // Draw vertices
    for (int i = 0; i < numVertices; i++)
    {
        circle(x[i], y[i], 20);
        char label[3];
        sprintf(label, "%d", i + 1);
        outtextxy(x[i] - 5, y[i] - 5, label);
    }

    // Draw edges based on the adjacency matrix
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (adjacencyMatrix[i][j])
            {
                line(x[i], y[i], x[j], y[j]);
            }
        }
    }

    getch();
    closegraph();
}

int main()
{
    int numVertices;
    printf("<[DRAW GRAPH USING ADJACENCY MATRIX]>\n\n");
    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    drawGraph(adjacencyMatrix, numVertices);

    return 0;
}
