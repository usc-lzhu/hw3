#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  int m;  // m-ary tree
  std::vector<T> data;
  PComparator comp;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  m(m), comp(c) { }

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() { }

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  // adds new item to end of vector
  data.push_back(item);
  std::size_t index = size() - 1;

  // traverse up the tree
  while (index != 0) {
    std::size_t parentIndex = (index - 1) / m;
    T& current = data[index];
    T& parent = data[parentIndex];

    // stop loop is current node is "worst" than parent
    if (!comp(current, parent)) {
        break;
    }
    
    // swap current and parent node if current is "better"
    std::swap(current, parent);

    // update index
    index = parentIndex;
  } 
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  // checks if data size is 0
  if (size() == 0) {
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  // return size of data
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("top: underflow error");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  // return best node
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("pop: underflow error");
  }

  // swap best and worst node and pop previous best node
  std::swap(data[0], data[size() - 1]);

  data.pop_back();

  std::size_t index = 0;
  size_t bestChildIndex = -1;
  size_t childIndex = -1;

  // traverse down the tree
  while (m * index + 1 < size()) {
    // find "best" child node
    bestChildIndex = m * index + 1;
    for(int i = 1; i <= m; i++) {
      childIndex = m * index + i;
      if (childIndex < size() && comp(data[childIndex], data[bestChildIndex])) {
        bestChildIndex = childIndex;
      }
    }

    // swap current and child node if child is better than parent
    T& current = data[index];
    T& bestChild = data[bestChildIndex];

    if (comp(bestChild, current)) {
      std::swap(current, bestChild);
      index = bestChildIndex;
    }
		else {
			break;
		}
		
  }
}


#endif

