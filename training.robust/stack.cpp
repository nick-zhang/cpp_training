
namespace {

	template<class T>
	class Stack
	{
	private:
		size_t capacity;
		size_t used;
		T* values;

	public:
		Stack(size_t size): capacity(size), used(0), values(new T[size]) {}
		~Stack(){delete[] values;}

		Stack(const Stack& other)
		{
			
		}

		Stack& operator = (const Stack& other)
		{

		}
	};

	Stack<int> stack(10);
}