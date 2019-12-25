import java.util.*;
public class graphBFSandDFS {
//Driver Code
	public static void main(String[] args) {
	//A Graph object is created, it has 4 vertices
	//the edges represent the connections between the vertices
		Graph graph = new Graph(4);
		 graph.addEdge(0, 1); 
	     graph.addEdge(0, 2); 
	     graph.addEdge(1, 2); 
	     graph.addEdge(2, 0); 
	     graph.addEdge(2, 3); 
	     graph.addEdge(3, 3); 
	  
	     System.out.println("Following is Breadth First Traversal "+ 
	                           "(starting from vertex 2)"); 
	     //Calling the methods
	     graph.BFS(2); 
	     graph.DFS(2);
	}

}
class Graph{
	//V = number of vertices
	int V;
	//a list created for every vertex that tells what 
	//other vertices its connected to
	LinkedList<Integer> adj[];
	//constructor that takes in number of vertices
	Graph (int vert) {
		V = vert;
		adj = new LinkedList[V];
		//creates a new LinkedList for very vertex in the graph
		for (int i=0;i<V;i++) {
			adj[i]= new LinkedList();
		}
	}
	//this adds a vertex to another vertex, 
	//this is what's stored in the linked list
	void addEdge(int vert, int edgeVert) {
	 adj[vert].add(edgeVert);
	}
	void BFS(int s) {
	//a boolean array is created for all vertices that
	//have been visited
	boolean visited[] = new boolean[V];
	//a queue is created, its used to recursively start
	//from one vertex and link to the next, using FIFO
	LinkedList<Integer> queue = new LinkedList<Integer>();
	//flags this vertex is visited
	visited[s] = true;
	//now its added to the queue
	queue.add(s);
		
	while(queue.size()!=0) {
		//the last value is popped from the queue and assigned to s
		s = queue.poll();
		System.out.println(s+" ");
		//iterator object helps iterate through edges of vertex
		Iterator<Integer> itr = adj[s].listIterator();
		//while a vertex is connected to another
		while (itr.hasNext()) {
		//assign the next vertex to n
			int n = itr.next();
			//if it hasn't been visited, make it visited
			//now add it to the queue so that this runs recursively
			if(visited[n]==false) {
				visited[n]= true;
				queue.add(n);
			}
		}
			
	}
}
	//this method just calls the DFSUtil method after 
	//creating a boolean array
	void DFS(int v) {

		boolean visited[] = new boolean[V];
		DFSUtil(v,visited);

	}
	
	void DFSUtil(int v,boolean[]visited) {
		//marks the current vertex as visited
        visited[v] = true; 
        System.out.print(v+" "); 
        //iterates similarly through the linked list
        //while a vertex is connected to another unvisited vertex,
        //add that vertex to the queue and repeat.
        Iterator<Integer> i = adj[v].listIterator(); 
        while (i.hasNext()) 
        {   int n = i.next(); 
            if (!visited[n]) 
                DFSUtil(n, visited); 
        } 
	}
	
}