#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

#include <iostream>

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

    std::vector<T> heapVector;

    int mAry;

    PComparator thisComparator;

};

// Add implementation of member functions here

template<typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : 
    mAry(m), thisComparator(c)
{



}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{



}

template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{

    return heapVector.size();

}

template<typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{

    return Heap<T,PComparator>::size() == 0;

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Current heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  else
  {

    return heapVector[0];

  }

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Current heap is empty");

  }

  if(Heap<T,PComparator>::size() == 1)
  {

   //  std::cout << "Popping, but size is 1" << std::endl;

    heapVector.pop_back(); 

    return;

  }

  else
  {

   //  std::cout << "Popping standard style." << std::endl;

    // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
    // {

    //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

    // }

    std::swap(heapVector[0], heapVector[Heap<T,PComparator>::size() - 1]);

    heapVector.pop_back();

   //  std::cout << "After initial pop," << std:: endl;

    // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
    // {

    //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

    // }

    std::size_t index = 0;

    while(index < Heap<T,PComparator>::size())
    {

       //  std::cout << "Popping, with index of " << index << std::endl;

        // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
        // {

        //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

        // }

        int* childrenIndices = new int[mAry];

        for(int i = 0; i < mAry; i++)
        {

            childrenIndices[i] = (mAry * index) + (i + 1);

        }

        T& current = heapVector[index];

        size_t bestItemIndex = index;

        T& bestItem = current;

       //  std::cout << "Setting best ItemIndex to current Index of " << index << std::endl;

        // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
        // {

        //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

        // }

        for(int i = 0; i < mAry; i++)
        {   

           //  std::cout << "Currently on mAry = " << i << std::endl;
            
           //  std::cout << "bestItemIndex is " << bestItemIndex << std::endl;
                    
           //  std::cout << "currentItemIndex is " << index << std::endl;

            // for(int j = 0; j < int(Heap<T,PComparator>::size()); j++)
            // {
                
            //    //  std::cout << "Heap[" << j << "] is currently " << heapVector[j] << std::endl;
    
            // }

            if(childrenIndices[i] < int(Heap<T,PComparator>::size()))
            {

                if(thisComparator(heapVector[childrenIndices[i]], heapVector[bestItemIndex]))
                {

                   //  std::cout << "Found a new best item!" << std::endl;

                    // bestItem = heapVector[childrenIndices[i]];

                    bestItemIndex = childrenIndices[i];

                   //  std::cout << "bestItemIndex is " << bestItemIndex << std::endl;
                    
                   //  std::cout << "currentItemIndex is " << index << std::endl;

                }

                else if(thisComparator(heapVector[bestItemIndex], heapVector[childrenIndices[i]]))
                {

                   //  std::cout << "Best item is still the best!" << std::endl;

                }

                else
                {

                   //  std::cout << "These items are equal!" << std::endl;

                }

            }

        }

        if(bestItemIndex != index)
        {

           //  std::cout << "Swapping!" << std::endl;

            // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
            // {
        
            //     // std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;
        
            // }
            
           //  std::cout << "bestItemIndex is " << bestItemIndex << std::endl;
                    
           //  std::cout << "currentItemIndex is " << index << std::endl;

            std::swap(heapVector[index], heapVector[bestItemIndex]);

            // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
            // {
        
            //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;
        
            // }

            index = bestItemIndex;

        }

        else
        {

           //  std::cout << "Best Item is still current! Breaking!" << std::endl;

           //  std::cout << "bestItemIndex is " << bestItemIndex << std::endl;
                    
           //  std::cout << "currentItemIndex is " << index << std::endl;

            break;

        }

        delete [] childrenIndices;

    }

   //  std::cout << "After all trickling down with pop," << std::endl;

    // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
    // {

    //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

    // }

  }

}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{

    heapVector.push_back(item);

    if(Heap<T,PComparator>::size() == 1)
    {

        std::cout << "Pushing with size 1" << std::endl;

        // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
        // {
            
        //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;
    
        // }

        return;

    }

    std::size_t index = Heap<T,PComparator>::size() - 1;

    // std::cout << "Standard Pushing!" << std::endl;

    // for(int i = 0; i < Heap<T,PComparator>::size(); i++)
    // {
        
    //    //  std::cout << "Heap[" << i << "] is currently " << heapVector[i] << std::endl;

    // }

    while(index != 0)
    {

        // std::cout << "Pushing with index of " << index << std::endl;

        std::size_t parentIndex = (index - 1) / mAry;

        // std::cout << "Parent has index of " << parentIndex << std::endl;

        T& current = heapVector[index];

        T& parent = heapVector[parentIndex];

        if(thisComparator(heapVector[parentIndex], heapVector[index]))
        {

            break;

        }

        else if(thisComparator(heapVector[index], heapVector[parentIndex]))
        {

            std::swap(heapVector[index], heapVector[parentIndex]);

            index = parentIndex;

        }

        else if(current == parent)
        {

            break;

        }

    }

}



#endif

