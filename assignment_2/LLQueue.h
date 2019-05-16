// Pure virtual abstract base class representing a minimal queue
class Queue {
	public:
	// c'tor and d'tor
	Queue() { }

	// pre-condition:  given an integer 'e'
	// post-condition: the queue will contain 'e' at one end of the data structure
	virtual void enqueue(int e) = 0;

	// pre-condition:  queue must not be empty
	// post-condition: the integer at the other end of the data structure is returned,
	//                 and also removed from the structure
	virtual int dequeue() = 0;

	virtual bool isEmpty() = 0;
	virtual void print() = 0;

};


/*******************************************
declaration of Node class
*******************************************/
class Node{
 public:
 	Node(int); //constructor
	int data_=0;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node* head=nullptr;
	Node* tail=nullptr;
};

/*******************************************
declaration of myQueue Class
*******************************************/
class myQueue : public Queue {
	public:
	myQueue(int);
	myQueue(){};
	~myQueue();
	void enqueue(int e) override;
	int dequeue() override;
	bool isEmpty() override;
	void print() override;
	
	Node* head=nullptr;
	Node* tail=nullptr;
	Node* temp=nullptr;
	Node* holder=nullptr;
	int size_=0;

};

