/*
This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. 
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. 
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", 
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, 
return the length of the longest absolute path to a file in the abstracted file system. 
If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
*/

//gonna need a parser
    //symbols:
        //\n
        //\t
        //.
        //[a-Z and 0-9]
//tree structure
    //nodes, roots, leaves
        //get length while constructing
//while constructing tree, list all nodes and lengths
//search a tree structure
    //recursive, depth/widthwise

//class Node
    //string path
    //Node[] children

//parse rules
    //start must be "dir"
    //if followed by \n
        //must be followed by \t
        //must be followed by [a-Z 0-9]*
        //can be followed by .
        //must be followed by [a-Z]*
    //elif followed by 

//parser has a state with permitted inputs
//A starting state: get root name   | -> B
//B get depth state: get \t symbols |

//directories are terminated by \n
//files are terminated by .*

//states: 
    //reading name
    //determine if file or directory
    //determine depth

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum Type { DIR, FIL } ;
class Node;
class Node {
    public:
        Node() {
            path = "";
            parent = NULL;
            type = DIR;
            level = 0;
        }

        Node(string n) {
            path = n;
            parent = NULL;
        }

        Node(string n, Node *p) {
            path = (*p).getPath() + "\\" + n;
            parent = p;
        }

        Node(string n, Node *p, Type t) {
            path = (*p).getPath() + "\\" + n;
            parent = p;
            type = t;
        }

        Node(string n, Node *p, Type t, int l) {
            path = (*p).getPath() + "\\" + n;
            parent = p;
            type = t;
            level = l;
        }

        void setPath(string n) {
            path = n;
        }

        string getPath() {
            return path;
        }

        void setType(Type t) {
            type = t;
        }

        Type getType() {
            return type;
        }

        int getLevel() {
            return level;
        }
        
        void addChild(Node n) {
            children.push_back(n);
        }

        Node getChild(int n) {
            return children.at(n);
        }

        int numberOfChildren() {
            return children.size();
        }

        Node* getParent() {
            return parent;
        }

    private:
        string path;
        vector<Node> children;
        Node *parent;
        Type type;
        int level;
};

enum State { BEGIN, DEPTH, NAME, EXT };

class Parser {
    public:
        string symbols = "";
        State state = BEGIN;    
        int level = 0;
        Node root;
        Node * current = &root;

        Node parse(string input) {
            for(char& peek: input) {
                switch(state) {
                    case BEGIN:
                        if(peek == '\n') {
                            root.setPath(symbols);
                            resetSymbols();
                            resetLevel();
                            state = DEPTH;
                            // cout << "root dir found " << root.getPath() << endl;
                        } else {
                            symbols.push_back(peek);        //otherwise name still accumulating..
                        }
                        break;
                    case DEPTH:
                        if(peek == '\t') {
                            level += 1;
                        } else {
                            // cout << "level " << level << ", current level " << (*current).getLevel() << endl;
                            //travel up ancestry until current node level is one less than peeked level
                            //suppose previous as in current node was level 3 and peeked is level 1
                                //then current (3) parent (2) parent (1) parent (0) needs to be set to current
                            //suppose current was 1, and peeked level 1
                                //then current (1) parent (0) needs to be set to current
                            for (int i = (*current).getLevel() - level + 1; i > 0; i--) {
                                current = (*current).getParent();
                            }
                            symbols.push_back(peek);        //name has started accumulating
                            state = NAME;
                            cout << "current node " << (*current).getPath() << endl;
                        }
                        break;
                    case NAME:
                        if(peek == '\n') {                  //name was directory
                            Node n = newDir (symbols, current, level);
                            cout << "directory found "  << symbols << endl;
                            cout << (*current).getPath() << endl;
                            (*current).addChild(n);         //add this new node to parent
                            cout << (*current).getPath() << " now has " << (*current).numberOfChildren() << " children "  << endl;
                            current = &n;                   //consider this new node current
                            state = DEPTH;                  //move to next iteration
                            resetSymbols();                 //
                            resetLevel();
                            
                        } else if(false) {                  //check for illegal symbol, throw syntax error

                        } else if (peek =='.') {            //name was file, go to state EXT
                            state = EXT;                    //go to extension state
                            symbols.push_back(peek);
                        } else {
                            symbols.push_back(peek);        //otherwise name still accumulating..
                        }
                        break;
                    case EXT:
                        if(peek == '\n') {                  //full filename found. go to state DEPTH
                            Node n = newFile (symbols, current, level);
                            cout << "file found " << symbols << endl;
                            (*current).addChild(n);
                            cout << (*current).getPath() << " now has " << (*current).numberOfChildren() << " children "  << endl;
                            state = DEPTH;
                            
                            resetSymbols();
                            resetLevel();
                            
                        } else {
                            symbols.push_back(peek);        //otherwise extension still accumulating..
                        }
                        break;
                }

                // cout << symbols << endl;
            } //end of input. assuming correct syntax, state is now EXT or NAME 
            switch(state) {
                case NAME:  //latest set of symbols was dir
                    (*current).addChild(newDir(symbols, current, level));
                    break;
                case EXT:  //latest set of symbols was file
                    (*current).addChild(newFile(symbols, current, level));
                    break;
                case BEGIN:
                case DEPTH:
                    break;
            }
            return root;
        }
        void resetSymbols() {
            symbols = "";
        }
        void resetLevel() {
            level = 0;
        }

        Node newFile (string n, Node *p, int l) {
            return Node(n, p, FIL, l);
        }

        Node newDir (string n, Node *p, int l) {
            return Node(n, p, DIR, l);
        }
    private:
        
    
};

int main() {
    Parser p;
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    Node root = p.parse(input);
    cout << root.getChild(0).getPath() << " should equal subdir1" << endl;
    cout << root.getChild(0).getChild(0).getPath() << " should equal file1.ext" << endl;
    return 0;
}