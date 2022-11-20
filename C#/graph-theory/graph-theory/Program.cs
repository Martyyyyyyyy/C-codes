using static System.Console;
using static System.Convert;

Write("Enter number of vertices: ");
int h = ToInt32(ReadLine());
while (h < 1)
{
    Write("Enter correct value:");
    h = ToInt32(ReadLine());
}
Graph a = new Graph(h);
class Vertex
{
    int vertexIndex;
    public List<Vertex> adjacentVertices;
    public int Index
    {
        get { return vertexIndex; }
        set { vertexIndex = value; }
    }
    public Vertex(int index)
    {
        vertexIndex = index;
        adjacentVertices = new List<Vertex>();
    }
}

class RibSet
{
    int size;
    int amountVert;
    int[] firstVertices;
    int[] secondVertices;
    public int Size { get { return size; } }
    public RibSet()
    {
        size = 0;
    }
    public RibSet(int amount, int numVert)
    {
        size = amount;
        amountVert = numVert;
        firstVertices = new int[amount];
        secondVertices = new int[amount];
        addRibs();
    }
    void addRibs()
    {
        for (int i = 0; i < firstVertices.Length; i++)
        {
            enterRib("", i);
        }
    }
    void enterRib(string msg, int ind)
    {
        WriteLine($"Enter {msg} rib for pseudograph: ");
        firstVertices[ind] = ToInt32(ReadLine());
        while (firstVertices[ind] < 1 || firstVertices[ind] > amountVert)
        {
            WriteLine("Enter correct value: ");
            firstVertices[ind] = ToInt32(ReadLine());
        }
        secondVertices[ind] = ToInt32(ReadLine());
        while (secondVertices[ind] < 1 || secondVertices[ind] > amountVert)
        {
            WriteLine("Enter correct value: ");
            secondVertices[ind] = ToInt32(ReadLine());
        }
    }
    public List<Vertex> searchAdjacentVetices(int index, List<Vertex> l)
    {
        List<Vertex> result = new List<Vertex>();
        for (int i = 0; i < firstVertices.Length; i++)
        {
            if (firstVertices[i] == index)
                result.Add(l.ToArray()[secondVertices[i] - 1]);
            else if (secondVertices[i] == index)
                result.Add(l.ToArray()[firstVertices[i] - 1]);
        }
        return result;
    }
}

class Graph
{
    public int AmountVertices { get; set; }
    int q;
    public List<Vertex> vertices;
    public RibSet ribsSet = new RibSet();
    int[,] matrix_adjacency;
    public Graph(int amountVertices)
    {
        AmountVertices = amountVertices;
        matrix_adjacency = new int[amountVertices, amountVertices];
        vertices = new List<Vertex>();
        for (int i = 0; i < amountVertices; i++)
        {
            vertices.Add(new Vertex(i + 1));
        }
        addEdges();
        if (q == 0)
        {
            WriteLine("Matrix of adjacency: ");
            for (int i = 0; i < amountVertices; i++, Write('\n'))
                for (int j = 0; j < amountVertices; j++, Write(' '))
                    Write(matrix_adjacency[i, j]);
        }
        else
        {
            foreach (Vertex v in vertices) v.adjacentVertices = ribsSet.searchAdjacentVetices(v.Index, vertices);
            for (int i = 0; i < amountVertices; i++)
                for (int j = 0; j < amountVertices; j++)
                    for (int k = 0; k < vertices[i].adjacentVertices.Count; k++)
                        if (vertices[i].adjacentVertices[k].Index == j + 1)
                            matrix_adjacency[i, j]++;
            WriteLine("Matrix of adjacency: ");
            for (int i = 0; i < amountVertices; i++, Write('\n'))
                for (int j = 0; j < amountVertices; j++, Write(' '))
                    Write(matrix_adjacency[i, j]);
        }
    }
    void addEdges()
    {
        WriteLine("Enter number of ribs: ");
        q = ToInt32(ReadLine());
        while (q < 0)
        {
            WriteLine("Enter correct value: ");
            q = ToInt32(ReadLine());
        }
        if (q == 0) return;
        ribsSet = new RibSet(q, AmountVertices);
    }
}
