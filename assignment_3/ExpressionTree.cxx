#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include "ExpressionTree.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::ExpressionTree(const string& infix)
  : tree(nullptr)
{
  cout << "Converting from infix   '" << infix << "' to postfix notation\n";
  string postfix = convertInfixToPostfix(infix);
  cout << "Converting from postfix '" << postfix << "' to expression tree\n";
  buildTreeFromPostfix(postfix);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::~ExpressionTree()
{
  clear(tree);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool ExpressionTree::isOperator(const string& s) const
{
  return s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int ExpressionTree::opPrecedence(const string& op1, const string& op2) const
{
  int op1Int = (op1 == "/" || op1 == "*") ? 1 : 0;
  int op2Int = (op2 == "/" || op2 == "*") ? 1 : 0;

  return op1Int - op2Int;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Be thankful that I didn't ask for this method in the assignment!
string ExpressionTree::convertInfixToPostfix(const string& infix) const
{
  stack<string> stack;
  vector<string> result;

  istringstream in(infix);
  for(string s; in >> s; )
  {
    if(!isOperator(s))
      result.push_back(s);
    else if(stack.empty() || stack.top() == "(")
      stack.push(s);
    else if(s == "(")
      stack.push(s);
    else if(s == ")")
    {
      while(stack.top() != "(")
      {
        result.push_back(stack.top());
        stack.pop();
      }
      stack.pop();
    }
    else  // look at precedence of operators
    {
      int precedence = opPrecedence(s, stack.top());
      if(precedence > 0)
        stack.push(s);
      else
      {
        result.push_back(stack.top());
        stack.pop();
        stack.push(s);
      }
    }
  }
  while(!stack.empty())
  {
    result.push_back(stack.top());
    stack.pop();
  }

  // Generate postfix form
  string postfix;
  for(const auto& s: result)
    postfix += s + " ";

  return postfix;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Create an expression tree from a postfix expression
// pre-condition:   a valid postfix expression (each part separated by space)
// post-condition:  'tree' points to a valid expression tree
void ExpressionTree::buildTreeFromPostfix(const string& postfix)
{
  /* Algorithm
      create a stack containing ExprNode pointers
      for each string 's' in the postfix expression
        create a new ExprNode containing 's'
        if 's' is an operand
          push the new node to the stack
        else if 's' is an operator
          pop two values from stack, make them children of the new node,
          and and push the node to the stack
        end if
      end for

      at the end, the stack contains one item; the expression tree
   */

	int length=postfix.size();		//find the length of the string passed
	ExprNode* op = nullptr;  		//ExprNode pointer to an operand
	ExprNode* stackNode1= nullptr;		//
	string space=" ";
	string hold=postfix;
	
	
	while(hold.size() != 0){ 	//while the string contains something
		string temp=getOp(hold);	//call getOp function
		bool check=isOperator(temp);	//call isOperator fucntion
		if ( check == false){		//if it is not an operator
			stackNode1 = new ExprNode(temp);	//make a ExprNode that holds the value of the operand
			myStack.push(stackNode1);		//push onto stack
		} 
		else {	//if it is an operator
			op = new ExprNode(temp);	//make a new ExprNode, that holds the value of the operator
			op->right=myStack.top();	//make the right operand the top value of the stack
			myStack.pop();			//pop the stack
			op->left=myStack.top();		//make the left operand the top value of the stack
			myStack.pop();			//pop the stack
			myStack.push(op);		//push the operator pointer onto the stack
		}
	}
	tree=myStack.top();	//tree will be the top element of the stack after traversal through the string
	myStack.pop();		//pop the value off the stack

}

//Get the operator/operand of the string one by one
// pre-condition:   A valid postfix expression will be passed
// post-condition:  Will return the first operator/operand value in the string
string ExpressionTree::getOp(string& hold){
	string s="";
	int length=hold.size();
	int pos=0;
	for( int i=0; hold.at(i) != ' ' ; i++)	{
		s=hold.substr(0,i+1);
		pos++;
	}
	hold=hold.substr(pos+1,length);	
return s;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Traverse the expression tree and generate the result
// pre-condition:   an expression tree already exists
//                  (ie, buildTreeFromPostfix() has already been called)
// post-condition:  the expression tree is traversed, and the final
//                  output calculated (the tree is not modified)
double ExpressionTree::evaluate(const ExprNode* tree) const
{
  /* Algorithm
      if root is nullptr then return 0.0
      else perform a postorder traversal on the root

      if data at root is an operator
        let right operand be the evaluation of the left child of root
        let left operand be the evaluation of the right child of root
        return the result of combining the left and right children using that operator
      else
        return the data at root converted to a double (hint: use stod)
      end if
   */

	if (tree==nullptr){		//if there is nothing in the tree, return a value of 0.0
		return 0.0;
	}
		if(tree->left==nullptr && tree->right == nullptr){	//if it is a leaf node, convert the value into a double
		return stod(tree->data);
		}
		double left_value=evaluate(tree->left);		//iterate left
 		double right_value=evaluate(tree->right);	//iterate right

		if(tree->data=="+")			//if the value of the node in the tree is a operator, perform the 	designated operation with the operands
			return right_value+left_value;
		else if (tree->data=="-")
			return left_value-right_value;
		else if (tree->data=="*")
			return left_value*right_value;
		else if (tree->data=="/")
                        return left_value/right_value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Utility function to clear memory
void ExpressionTree::clear(ExprNode* tree )
{
	ExprNode* temp=tree;		//start at the root
	if(temp->left != nullptr)	//use post order traversal and delete the nodes one by one
		clear(temp->left);
	if(temp->right !=nullptr)
		clear(temp->right);
	delete temp;
	tree=nullptr;	//after all nodes have been deleted, set the tree/root to null

}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int ac, char* av[])
{
  ExpressionTree expr1("2 / ( 3 + 7 )");
  cout << "Final evaluation: " << expr1.evaluate() << endl;
  cout << endl;

  ExpressionTree expr2("2 / ( 3 - 7 ) * 5");
  cout << "Final evaluation: " << expr2.evaluate() << endl;
}
