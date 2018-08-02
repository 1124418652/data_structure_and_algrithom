template<class T>
class Node
{
	private:
		T data;
		Node<T> *link;
	public:
		Node();
		~Node();
		Node(const T &data);
};