
#include <iostream>

using namespace std;

void swap(int *x, int *y);

class MyMinHeap
{
private:
  int *harr;
  int capacity;
  int heap_size;

public:
  MyMinHeap(int c) : heap_size(0), capacity(c)
  {
    harr = new int[cap];
  }

  // to heapify a subtree with the root at given index
  void MyMinHeapify(int i);

  int parent(int index)
  {
    return (index - 1) / 2;
  }

  int left_child(int index)
  {
    return (2 * index + 1);
  }

  int right_child(int index)
  {
    return (2 * index + 2);
  }

  int extract_minimum()
  {
    if (heap_size <= 0)
    {
      return INT_MAX;
    }
    if (heap_size == 1)
    {
      heap_size--;
      return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MyMinHeapify(0);

    return root;
  }

  // Returns the minimum key (key at root) from min heap
  int getMin() { return harr[0]; }

  // Inserts a new key 'k'
  void insertKey(int k);
};

// Inserts a new key 'k'
void MyMinHeap::insertKey(int k)
{
  if (heap_size == capacity)
  {
    cout << "\nOverflow: Could not insertKey\n";
    return;
  }

  // First insert the new key at the end
  heap_size++;
  int i = heap_size - 1;
  harr[i] = k;

  // Fix the min heap property if it is violated
  while (i != 0 && harr[parent(i)] > harr[i])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MyMinHeap::MyMinHeapify(int i)
{
  int l = left_child(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l] < harr[i])
    smallest = l;
  if (r < heap_size && harr[r] < harr[smallest])
    smallest = r;
  if (smallest != i)
  {
    swap(&harr[i], &harr[smallest]);
    MyMinHeapify(smallest);
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  MyMinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
  cout << h.getMin();
  return 0;
}
