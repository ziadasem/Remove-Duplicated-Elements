# Remove Duplicated Elements in a list

 
This algorithm detects duplicated elements in a list and removes them. it finds the duplicate number in a way similar to the binary search algorithm and iterates with the number of duplicated elements.


**limitations**

 - input list must be sorted
 - elements should have same step size i.e. 2,4,6,8 or 10,20,30,40

## working of code
 **1- Finding the number of duplicated elements**
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if the list is sorted and the difference between elements is equal then this equation should be true

    expected_list_length = last_element - first_element + 1

if this equation isn't true, the **difference between actual length and expected length** is the number of duplicates 

 **2- Finding the correct element**
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; the state that the list should be is that every element should be equal to this condition 
 

    expected_element = first_element + difference * current_index
  
for example 

    [2,6,10,14,18], step = 4

 at index 3 element should be equal to **2 + 4*3 = 14**
 if an element is in its place -achieve the above equation- that means this element and the previous elements are in their position without duplication, so duplication will be in **next elements only**.
 
 **3- Finding the duplicated element**
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; like binary search the middle element of the array is checked does it achieve the above the condition :
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if true**: that means the left part is ordered and without duplication 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;then we will search in the right part.
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**if false**: that means the left part has a duplication so we will 
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;update the index of middle of the list to be the **middle of the left part**
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and repeat the search until finding the duplicated element.

  **4- Remove all the duplicated elements**
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Repeat the previous steps with the number of the duplication 
 
## Testing
the following lists are inputs to the function

    {-3,-1,1,1,3},
	{-10,-7,-4,-1,2,2,5},
    {-1,0,0,0,0,0},
    {0,0,0,0,0,0},
	{-1,-1,-1,-1,-1,-1},
	
	{-3,-2,-1,0,0},
    {4,4,7,7,10,10,13,16},                              
    {1,2,3},
	{100,200,300,300,300,400,400,400},
    {11,14,17,20,23},
    
	{12,16,20,24,24},
    {11,11,17,23,23},
    {11,17,23,23,29},
    {11,17,23,29,29},
    {11,17,17,23,29},

the output

    -3, -1, 1, 3
	-10, -7, -4, -1, 2, 5
	-1, 0
	0
	-1
	
	-3, -2, -1, 0
	4, 7, 10, 13, 16
	1, 2, 3
	100, 200, 300, 400
	11, 14, 17, 20, 23
	
	12, 16, 20, 24
	11, 17, 23
	11, 17, 23, 29
	11, 17, 23, 29
	11, 17, 23, 29

## Help and support
if you have an improvement for this code or have failed test case, please share it with me

