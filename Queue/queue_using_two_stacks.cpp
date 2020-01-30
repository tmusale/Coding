/*
Queue using two Stacks

Implement a Queue using 2 stacks s1 and s2 .

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output Format:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the quee and pop which returns 
a integer poped out from other queue.

Your Task:
Since this is a function problem, you don't need to take inputs. Just complete the provided functions. The printing is done 
automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input
2
5
1 2 1 3 2 1 4 2
4
1 2 2 2 1 4
Output
2 3
2 -1

Explanation:
Testcase1:
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3 


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.
*/

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code     
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        
        if (!s2.empty()) {
            int item = s2.top();
            s2.pop();
            return item;
        }
        
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int item = s2.top();
        s2.pop();
        
        return item;
}
