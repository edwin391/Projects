import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;

public class Solution {
    //stack

    //g.addEdge(vertices, width)
    private int V;                              // No. of vertices
    private LinkedList<Integer> adj[];          // Adjacency list

    Solution(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void DFS(int v) {
        boolean visited[] = new boolean[V];

        Stack<Integer> stack = new Stack<Integer>();
        stack.add(v);

        visited[v] = true;

        while(!stack.isEmpty()) {
            int current = stack.pop();
            System.out.println(current + " ");

            Iterator<Integer> i = adj[current].listIterator();
            while(i.hasNext()) {
                int n = i.next();
                if(!visited[n]) {
                    stack.add(n);
                    visited[n] = true;
                }
            }
        }
    }
}
