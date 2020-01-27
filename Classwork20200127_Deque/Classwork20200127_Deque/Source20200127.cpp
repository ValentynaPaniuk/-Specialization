#include <iostream>
#include <string>
#include <iomanip> // для setw
#include <cassert> // для assert
#include <vector>//Conteiner
#include <deque> //Cherga (Dostyp do 1-ho i ostannioho elementa)
#include <stack> //Adapter, Struktyra danyh, pryncip FILO, Dostyp do ostannioho elementa

using namespace std;

/*ООП
Написати реалізацію класу stack бібліотеки STL на основі елементів типу double. 
Основна програма повинна містити код створення об'єкта, після чого потрібно "програти" методи даного класу. 
Оцінка залежить від повноти реалізації методів даного класу. */



template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline T pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
};


// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека
	return top;
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}


int main()
{
	/*deque<int> container = {8,5,3};
	container.push_back(10);
	container.push_front(12);

	for (deque<int>::const_iterator i = container.begin(); i < container.end(); i++)
	{
		cout << "Znachennia komirky: " << *i << endl;
	}
	 */
	
	//===================================================
	//stack<int, vector<int>> arr;
	//arr.push(5);
	//arr.push(8);
	//arr.push(7);
	//auto test = arr._Get_container(); //auto - typ danyh lyubyi
	//cout << test[2] << endl;


	//=========================================================
	/*stack<int, vector<int>> arr;
	arr.push(2);
	arr.push(6);
	arr.push(9);
	arr.push(5);
	
	arr.
	auto containerType = arr._Get_container();
	cout << "containerElement => " << containerType[2] << endl;
	cout << "Size => " << arr.size() << endl;
	cout << "Top element => " << arr.top() << endl;
	arr.pop();
	cout << "Top element => " << arr.top() << endl;
	cout << "All elements " << endl;
	while (!arr.empty()) {
		cout << arr.top() << endl;
		arr.pop();
	}*/

	Stack<double> a;
	a.push(3.2);
	a.push(4.2);
	a.push(6.2);
	a.push(7.2);
	a.push(8.2);
	a.push(9.2);
	
	cout << "Zarezwrvovano misce pid stack: " << a.getStackSize << endl;
	a.printStack();
	cout <<"Size Stack: "<< a.getTop() << endl;
	a.pop();
	cout << "After delete last element: " << endl;
	a.printStack();
	cout <<"Size Stack: "<< a.getTop() << endl;
	
	cout<<a.Peek(3);



	system("pause");
	return 0;
}