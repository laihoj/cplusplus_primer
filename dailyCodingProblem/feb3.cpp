#include <iostream>

using namespace std;

/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, 
it holds a field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; 
it has an add(element) which adds the element to the end, 
and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), 
you can assume you have access to get_pointer and dereference_pointer 
functions that converts between nodes and memory addresses.
*/

//list struct
//objects have a memory address
//objects are linked to the list by add
//init empty list
//add first item
//add second item
//add subsequent item

/*
&a = 0001
&b = 1101
&c = 1111
&d = 1001
&e = 0010

xor gives 1 if both bits are different, otherwise 0
suppose linked suchly:
a->b->c->d->e
then
a.both == xor(0, b) == 0001
b.both == xor(a, c) == 1110
c.both == xor(b, d) == 0100
d.both == xor(c, e) == 1101
e.both == xor(e, 0) == 0010

traversal of list:
suppose we are at b and want the next (which is c)
if we have address of a, we can get c from b.both
c = xor(a, b.both) == 1111
traversal from first to last (or last to first) requires remembering previous address

get node at index i of list:
    - throw error if i < 0 OR i >= li.length

    // can try to be smart by traversing backwards if i > li.length/2, but never mind for now optimisations
    int current_i = 0;
    int prevAddress = 0;
    Node currentNode = li.first;
    while(current_i < i) {
        
        prevAddress = xor(prevAddress, currentNode.both);
        currentNode = * prevAddress;
        current_i++;
    }


*/


class Node {
    public:
        Node(int k){  key = k; };
        Node * both;
        int getKey() { return key; };
    private:
        int key;
};

Node* myXOR(Node* n1, Node* n2) {
    // cout << "n1: " << n1 << ", n2: " << n2 << ", xor: " << (Node *) ((uintptr_t) n1 ^ (uintptr_t) n2) << endl;
    return (Node *) ((uintptr_t) n1 ^ (uintptr_t) n2); //cast pointers to uint to do bitwise XOR
};

class List {
    private:
        
        // Node * lastNode = nullptr;
        int length = 0;
    public:
        List() {};
        Node * firstNode = 0;
        // Node * first() {
        //     return firstNode;
        // };
        // Node * last() {
        //     return lastNode;
        // };

        //setFirst
        //setLast
        void add(Node *n) {
            //dummy
            if (firstNode == 0) {
                firstNode = n; //use setters irl
                firstNode->both = myXOR(0, firstNode);
                length ++;
                cout << "first add " << length << " " << firstNode->both << endl;
            } else {
                cout << "nonempty list " << endl;
                /*
                previously lastnode.both = xor(*secondLastNode, 0)
                so secondlastnode = xor(lastnode.both, 0)
                then
                lastnode.both = xor(*secondLastNode, *latestNode)
                and latestnode.both = xor(lastnode, 0)
                */
                cout << "n: " << n << endl;
                Node *lastNode = get(length);
                cout << "lastNode: " << lastNode << endl;
                Node *secondLastNode = myXOR(lastNode->both, 0);
                cout << "secondLastNode: " << secondLastNode << endl;
                lastNode->both = myXOR(secondLastNode, n);
                cout << "xor(secondlastnode, n): " << lastNode->both << endl;
                n->both = myXOR(lastNode, 0);
                // lastNode->both = (Node *) ((uintptr_t) lastNode ^ (uintptr_t) *n); //cast pointers to uint to do bitwise XOR
                length++;
                cout << "subsequent add " << length << " " << n->both << endl;
            }
            //todo the rest
        };
        Node * get(int i) {
            int current_i = 0;
            Node * prevAddress = 0;
            Node * currentNode = firstNode; //currentNode is alias to first item in list
            // cout << "currentNode: " << currentNode << " firstNode: " << firstNode << endl;
            while(current_i < i) {
                cout << "prevAddress was: " << prevAddress << endl;
                cout << "currentNode->both was: " << currentNode->both << endl;
                prevAddress = myXOR(prevAddress, currentNode->both);
                cout << "prevAddress is now: " << prevAddress << endl;
                // prevAddress = (Node *) ((uintptr_t) prevAddress ^ (uintptr_t) currentNode.both); //cast pointers to uint to do bitwise XOR
                currentNode = prevAddress;
                current_i++;
            }
            return currentNode;
        };
};

#include <bitset>

uintptr_t XOR(uintptr_t a, uintptr_t b)
{
    return a ^ b;
}


int main() {
    
    uintptr_t addresses[4] = {
        0b110,
        0b1010,
        0b1000110,
        0b10010
    };

    const int len = (sizeof(addresses)/sizeof(*addresses));
    uintptr_t boths[len] = {0};
    int count = 0;

    //printout init state 
    for(int i = 0; i < len; i++) {
        cout << "add_" << i << " " << bitset<8>(addresses[i]) << endl;    
    }
    

    //special case add first
    boths[0] = 0;
    for(int i = 0; i < len; i++) {
        cout << "step 0 both_" << i << " " << bitset<8>(boths[i]) << endl;    
    }
    count++;
    
    //generic case add subsequent
    while(count < len) 
    {
        boths[count] = XOR(addresses[count - 1], 0);
        boths[count - 1] = XOR(XOR(boths[count - 1], 0), addresses[count]);
        for(int i = 0; i < len; i++) {
            cout << "step " << count << " both_" << i << " " << bitset<8>(boths[i]) << endl;    
        }
        count++;
    }

    return 0;
}