#include "Node.h"

/**
*Node constructor
*/


Node::Node() {
	next_ = this;
	prev_ = this;
	shape_ = new Shape();
	isSentinal = true;
}

Node::Node(Shape* shape) {
	this->shape_ = shape;
	next_ = this;
	prev_ = this;
	isSentinal = false;
}

bool Node::isEmpty() {
	if (this->next_ == this)
		return true;
	
	return false;
}
// Inserts the node after the given node where_at
void Node::insertAfter(Node* where_at) {
	Node* our_node_pointer = new Node;
	our_node_pointer->shape_ = this->shape_;
	our_node_pointer->next_ = where_at->next_;
	our_node_pointer->prev_ = where_at;
	where_at->next_ = our_node_pointer;
}

//Removes the node from the linked list. **Note** the node is not deleted
void Node::remove(Node*){
	prev_->next_ = next_;
	next_->prev_ = prev_;
	next_ = this;
	prev_ = this;
}

//Deletes node
void Node::deleteNode(Node* node) {
	delete(node);
}

//Returns the node before this node. Is it supposed to return the node at the end of the list?
Node* Node::getEnd() {
	//Since you are calling the no-args constructor wouldn't cur->next_ be cur? -Jake
	//cur = new Node();
	//cur = next_;
	Node* cur=this;
	cur = cur->next_;
	while(cur != this) {
		cur = cur->next_;
	}
	//currently this returns the node before this, not the node at the end of the list. Not sure that that was intentional so I'm leaving it alone. -Jake
	return cur->prev_;
}

//adds a node to the end of the linked list
void Node::popOn(Node* node){ 
	/*node->prev_=this->getEnd();
	node->next_=this->getEnd()->next_;
	this->getEnd()->next_ = node;*/
	
	//This is probably a better, clearer way to write these lines. Program appears to function normally with this code.
	node->prev_=(*this).getEnd();
	node->next_=(*this).getEnd()->next_;
	(*this).getEnd()->next_ = node;

	/*next_= node;
	node->prev_=this;
	node->next_=next_;*/

}


//deletes the end node? -Jake
///FIX THIS!!!
void Node::popOff(Node* end) {
	//set list end's previous's next to end's next
	this->getEnd()->prev_->next_=this->getEnd()->next_;
	//set list end's next's previous to end's previous
	this->getEnd()->prev_->next_=this->getEnd()->prev_;
	//delete end/// BUT IT DELETES EVERYTHING??? Keep in mind your getEnd() method is returning the node before this, that could be your problem You may want to add another method for returning the end of the list.
	//you may consider making a getEndList() method that returns the node before the sentinel. -Jake
	//delete(end);
}

/*Example getEndList(){
	Node* cur=this;
	if(cur->isSentinal==true)
	{
		return cur->prev_;
	}
	while(cur->next_->isSentinal!=true)
	{
		cur=cur->next_;
	}
	return cur; **Note** for this method to always work as it is currently written you always have to have a sentinal node in your list and that node has to be the first node in the list.
}
*/

void Node::draw() {
	//Again this is probably a better way to do this. Also, why is it drawing triangles when you are clearly making circles? is that realted to the Circle.h file that I don't have? -Jake
	//shape_->circle();
	(*shape_).circle();
}

void Node::drawList() {
	//I am slightly confused as to how cur=new Node() allows you to go through the whole list
	//cur = new Node();
	//cur = next_;
	Node* cur=this;
	cur = cur->next_;

	while(cur != this) {
		cur->draw();
		cur = cur->next_;
	}
}