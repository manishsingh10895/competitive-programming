# Arrays

- # Left Rotation **By using juggling method**
    **Shifting an array with certain number of places (N)**

    - Array is divided in different sets (GCD (size, N))
    - Then Elements in each set are shifted to the corresponding place in left set
    - Method 3 on [Left Rotation](http://www.geeksforgeeks.org/array-rotation/)

 - # Binary Search in a Rotated Array
    **Searching for an element in a sorted and rotated array**

    - First find the first position in array where the next element is lower than the previous element (pivot)
    - Divide the array into two sets from the pivot point
    - Apply binary search on left set if first element of the array is less than the **element to search** (key)
    - Else Apply Binary search on the right set