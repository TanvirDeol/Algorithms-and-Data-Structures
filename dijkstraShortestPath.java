//Dijkstra's Shortest Path Algorithm From GeeksForGeeks
//I just added comments to understand
import java.util.*;
public class dijkstraShortestPath {
	//integer array of distances between vertices(edges)
	int dist[];
	//a hashset structure that holds the index of vertices that have been visited.
	Set<Integer> settled;
	//a priority queue that holds node objects and removes the smallest one first (priority)
	PriorityQueue<Node> pq;
	//number of vertices
	int V;
	//a list of the neighbors that each node has, short for adjacent
	List<List<Node>> adj;
	//constructor
	public dijkstraShortestPath(int V) {
		this.V = V;
		dist= new int[V];
		settled = new HashSet<Integer>();
		//priority queue accepts vertex index and its node object
		pq = new PriorityQueue<Node>(V,new Node());
	}
	//
	public void dijkstra (List<List<Node>> adj,int src) {
		
		this.adj = adj;
		//first makes the distance of every node infinite
		for (int i =0;i<V;i++) {
			dist[i]= Integer.MAX_VALUE;
		}
		//adds source node to queue with distance 0
		pq.add(new Node(src,0));
		dist[src]= 0;
		//until the hashSet has not covered all vertices,
		//pop minimum node, get next node,get its neighbors,
		//minimize the distances, and stop when the hashSet has covered all vertices
		while (settled.size()!=V) {
			int u = pq.remove().node;
			settled.add(u);
			e_Neighbors(u);
		}
	}
	
	private void e_Neighbors (int u) {
		int edgeDistance = -1;
		int newDistance = -1;
		//creates a node v, for every neighbor of the node u
		for (int i=0;i<adj.get(u).size();i++) {
			Node v = adj.get(u).get(i);
			//if the hashSet doesn't already contain node v,
			//minimize its distance
			if (!settled.contains(v.node)) {
			edgeDistance = v.cost;
			newDistance = dist[u] +edgeDistance;
			}
			//if the newly found distance is less than the preset distance
			//update the distance 
			if (newDistance<dist[v.node]) {
				dist[v.node]= newDistance;
			}
			//add the new node V to the priority queue
			pq.add(new Node(v.node,dist[v.node]));
		}
		
	}
	
	public static void main(String[] args) {
		int V= 5;
		//index of source node<usually 0)
		int source =0;
		//list of adjacent nodes list created
		List<List<Node> > adj = new ArrayList<List<Node> >(); 
		  
        // Initialize list for every node 
        for (int i = 0; i < V; i++) { 
            List<Node> item = new ArrayList<Node>(); 
            //this adds every neighbor list, to the main list of adjacent nodes
            adj.add(item); 
        } 
        //neighboring nodes for nodes are created (node number, edge cost)
		 adj.get(0).add(new Node(1, 9)); 
	     adj.get(0).add(new Node(2, 6)); 
	     adj.get(0).add(new Node(3, 5)); 
	     adj.get(0).add(new Node(4, 3)); 	  
	     adj.get(2).add(new Node(1, 2)); 
	     adj.get(2).add(new Node(3, 4)); 
	  
	        // Calculate the single source shortest path 
	        dijkstraShortestPath dpq = new dijkstraShortestPath(V); 
	        dpq.dijkstra(adj, source); 
	  
	        // Print the shortest path to all the nodes 
	        // from the source node 
	        System.out.println("The shorted path from node :"); 
	       //iterates through array of nodes and prints shortest path between source node and i node.
	        for (int i = 0; i < dpq.dist.length; i++) 
	            System.out.println(source + " to " + i + " is "
	                               + dpq.dist[i]); 

	}
	
}
//builds on top of already existing node class
class Node implements Comparator<Node> { 
    public int node; 
    public int cost; 
  
    public Node() 
    { 
    } 
  //now it can take in cost
    public Node(int node, int cost) 
    { 
        this.node = node; 
        this.cost = cost; 
    } 
  
    @Override
    //compares two nodes by seeing their costs
    public int compare(Node node1, Node node2) 
    { 
        if (node1.cost < node2.cost) 
            return -1; 
        if (node1.cost > node2.cost) 
            return 1; 
        return 0; 
    } 
}
