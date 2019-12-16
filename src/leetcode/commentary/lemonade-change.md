# Lemonade Change

Given the `bills` array. `bills[i]` is either 5, 10 or 20. I can return 10 with a 5. Nothing else. I can return 20 with three 5s or one 5 & a 10. So I can just create an int array of size 3 and store the count of different changes I have as I traverse along the array.

For a test case. Suppose the example of `[5,5,10,10,20]`. To start with `change=[0,0,0]`. Then after 2 iterations I have `change=[2,0,0]`. Then I return 10 with a 5, and I have `change=[1,1,0]`. Then I return 10 with another 5, and I have `change=[0,2,0]`. Finally, for 20, neither I have three 5s nor I have one 5 and one 10. So the output is `false`.