//BFS and DFS traversal using balanced trees
//Tanvir Deol

import java.util.*;
public class BFandDFTraversal {
//method to create node
	private static Node createTree() {
		Node node = new Node(1,
						new Node(2,new Node(3),new Node(4))
						,new Node(5, new Node(6), new Node(7)));
		
		return node;
	}
//driver code
	public static void main(String[] args) {
		Node tree = createTree();
		dfs(tree);
		bfs(tree);

	}
//BFS method, prints data level by level	
	public static void bfs(Node tree) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(tree);
		while(!q.isEmpty()) {
			tree = q.remove();
			System.out.println(tree.data + " ");
			if (tree.left!=null) {
				q.add(tree.left);
			}
			if (tree.right!=null) {
				q.add(tree.right);
			}
		}
	}
//DFS method, prints data chronologically, not  by levels
//Also its recursive
	public static void dfs(Node tree) {
		if (tree==null) {
			return;
		}
		System.out.println(tree.data + " ");
		dfs(tree.left);
		dfs(tree.right);
	}
}
//Node class with 2 types of constructors
class Node{
	int data;
	Node left;
	Node right;
	
	public Node(int data){
		this.data = data;
	}
	public Node(int data, Node left, Node right){
		this.data = data;
		this.left =left;
		this.right = right;
	}
}