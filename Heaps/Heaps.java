import java.util.Arrays;

public class Heaps {

	public static abstract class Heap {
		protected int capacity = 10, size = 0;
		protected int[] items = new int[capacity];
		public int[] sortedArray = new int[capacity];
		private int sortedSize = 0;

		protected int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
		protected int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
		protected int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

		protected int leftChild(int index) { return items[getLeftChildIndex(index)]; }
		protected int rightChild(int index) { return items[getRightChildIndex(index)]; }
		protected int parent(int index) { return items[getParentIndex(index)]; }

		protected boolean hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
		protected boolean hasRightChild(int index) { return getRightChildIndex(index) < size; }
		protected boolean hasParent(int index) { return getParentIndex(index) >= 0; }

		protected abstract void heapifyUp();
		protected abstract void heapifyDown();

		protected void swap(int indexOne, int indexTwo) {
			int temp = items[indexOne];
			items[indexOne] = items[indexTwo];
			items[indexTwo] = temp;
		}

		protected void ensureExtraCapacity() {
			if (size == capacity) {
				capacity *= 2;
				items = Arrays.copyOf(items, capacity);
			}
		}

		public void add(int item) {
			ensureExtraCapacity();
			items[size] = item;
			size++;
			heapifyUp();
		}

		public int peek() {
			if (size == 0) throw new IllegalStateException();
			return items[0];
		}

		public int poll() {
			if (size == 0) throw new IllegalStateException();
			int item = items[0];
			sortedArray[sortedSize++] = item;
			// items[0] = items[size - 1];
			swap(0, size - 1); // keep the copy of removed element
			size--;
			heapifyDown();
			return item;
		}

		public void display() {
			System.out.print("Array: ");
			for (int i = 0; i < size; i++) {
				System.out.print(items[i] + " ");
			}
			System.out.print("\n");
		}

		public void deleteAll(int[] arr) {
			if (arr.length == 0) { return; }
			// backup
			int temp = this.size;
			int[] tempItems = Arrays.copyOf(this.items, capacity);
			for (int i = 0; i < temp; i++) {
				this.poll();
			}
			// restore
			this.size = temp;
			this.items = tempItems;
		}

		public void sort() {
			deleteAll(items);
			System.out.print("Sorted: ");
			for (int i = 0; i < sortedSize; i++) {
				System.out.print(sortedArray[i] + " ");
			}
			System.out.print("\n");
			this.sortedSize = 0;
		}
	}

	public static class MinIntHeap extends Heap {
		@Override
		protected void heapifyUp() {
			int index = size - 1;
			while(hasParent(index) && parent(index) > items[index]) {
				swap(index, getParentIndex(index));
				index = getParentIndex(index);
			}

		}

		@Override
		protected void heapifyDown() {
			int index = 0;
			while(hasLeftChild(index)) {
				int smallerChildIndex = getLeftChildIndex(index);
				if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
					smallerChildIndex = getRightChildIndex(index);
				}

				if (items[smallerChildIndex] < items[index]) {
					swap(smallerChildIndex, index);
				} else {
					break;
				}

				index = smallerChildIndex;
			}
		}
	}

	public static class MaxIntHeap extends Heap {
		@Override
		protected void heapifyUp() {
			int index = size - 1;
			while (hasParent(index) && parent(index) < items[index]) {
				swap(index, getParentIndex(index));
				index = getParentIndex(index);
			}

		}

		@Override 
		protected void heapifyDown() {
			int index = 0;
			while (hasLeftChild(index)) {
				int largerChildIndex = getLeftChildIndex(index);
				if (hasRightChild(index) && rightChild(index) > leftChild(index)) {
					largerChildIndex = getRightChildIndex(index);
				}

				if (items[index] < items[largerChildIndex]) {
					swap(index, largerChildIndex);
				} else {
					break;
				}

				index = largerChildIndex;
			}
		}
	}

	public static void main(String[] args) {
		MaxIntHeap maxHeap = new MaxIntHeap();
		maxHeap.add(10);
		maxHeap.add(1);
		maxHeap.add(30);
		maxHeap.add(40);
		maxHeap.add(27);
		maxHeap.display();
		System.out.println("Largest value: " + maxHeap.peek());
		maxHeap.poll();
		maxHeap.display();
		System.out.println("Largest value: " + maxHeap.peek());
		maxHeap.sort();
		maxHeap.add(99);
		maxHeap.display();
		maxHeap.sort();
	}
}