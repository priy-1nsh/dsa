# C++ Standard Template and Library (STL)

**Example** - We want to print what is 2 to the power 9.

**What we will do** is -

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // print 2^9
    int ans = 1;
    for (int i = 0; i < 8; i++) {
        ans = ans * 2;
    }
    return ans;
}
```

**What C++ STL does is** - it gives you hidden functions, which underneath implements the code.

For eg, for the above example -

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << pow(2, 9); // prints 512
    return 0;
}
```

`pow()` funciton under the hood implements the same logic.

What we will cover -

- ALL THE CONTAINERS

- ALL THE ALGORITHMS

- ALL THE FUNCTIONS

- ALL THE ITERATORS

## 1. pair (utility library)

What if we want to store two variables in a single variable, that is, under the same variable name.

```cpp
void explainPair() {
    pair<int, int> pr1 = {2, 8};
    cout << pr1.first << " " << pr1.second << endl;
}
int main() {
    explainPair();
    return 0;
}
```

Syntax - `pair<int, int> variableName = make_pair(value, value);` OR `pair<int, int> variableName = {value, value}`.

What if we want to store an integer and a character together ?

```cpp
pair<int, char> pr2 = make_pair(2, 'b');
cout << pr2.first << " " << pr2.second << endl;
```

Can we store another pair inside the pair ? Yes.

```cpp
// pair inside pair
pair<pair<int, char>, int> pr3 = {{4, 'c'}, 8};
```

To access `'c'`, we can write -

```cpp
cout << pr3.first.second << endl; // prints 'c'
```

Similarly, we can store pairs inside pairs and so on... This is known as the concept of **nested pairs**.

This is known as the **pair class**.

This pair class is also under the `std` library, hence we always need to write `using namespace std`.

---

## 2. Vectors

If we need to store 5 elements, we can definitely use an array but if we need to store like 7 elemnets in the same array, we can't do so. Since, we write - `int arr[]` and hence we always define the size of the array beforehand and hence we can't increase it's size. Hence, we can say that array is an element which is of fixed nature. If we need something of dynamic nature, then we use something known as vectors.

We can store any data type inside the vector, which can be a number, character, string, pair or another vector.

```cpp
void explainVector() {
    vector<int> vec; // This is how we define an empty container
    // For insertion into a vector, we do something known as push_back
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    // Hence, we don't need to define the size, it keeps on increasing/dec
    // reasing.

    // To get the number of variables inside the vestor container, we 
    // use the `.size()` method.
    cout << vec.size() << endl;

    // Instead of push_back(), we can use something known as emplace_back().
    vec.emplace_back(5);
}
int main() {
    explainVector();
    return 0;
}
```

Vectors also store the values based on 0-based indexing, like - 0, 1, 2...

To print all the elements of the vector, we use a `for` loop -

```cpp
// [1, 2, 0]
for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " "; // prints 1 2 0
}
```

What we don't want to write such long lines of code just to print all the values inside the vector ?

There is when iterator comes into play.

**Iterator** -

```cpp
// iterator [1, 2, 0]
vector<int>::iterator itr = vec.begin();
```

`whatever_you_have_defined::iterator variableName = vec.begin()`.

`vec.begin()` basically returns you the pointer to the memory location where the first_element is. It is not returning you the element, but returning you the reference to the memory-address.

```cpp
cout << *itr << endl; // prints 1
```

prints the value of the variable stored at that memory-location.

So, we will use it to get the beginIterator and the endIterator -

```cpp
vector<int>::iterator beginItr = vec.begin();
vector<int>::iterator endItr = vec.end();
```

> Important -
> 
> `vec.end()` is not pointing to the last element 0, it is pointing to the location after that element 0.
> 
> So, end means `after_the_end` actually.

Now, we have the starting iterator or location and the end iterator or the end location, if we just scroll through it, we will get the values of the vector printed using the `for` loop.

```cpp
for (vector<int>::iterator i = beginItr; i < endItr; i++) {
    cout << *i << " "; // prints 1 2 0
}
```

> Note that we are not travelling from = beginItr to the <= endItr but instead from = beginItr to the < endItr.
> 
> Because the end always points to the `after_the_last_element`.
> 
> But if I do something like this -
> 
> ```cpp
> vector<int>::iterator beginItr = vec.begin();
> vector<int>::iterator endItr = vec.end();
> endItr = endItr - 1;
> for (vector<int>::iterator itr = beginItr; itr <= endItr; i++) {
>     cout << *itr << " ";
> }
> ```
> 
> Here, endItr is actually ponting to the last element which is 0 in this case,

An important chuck_luck -

```cpp
vector<int>::iterator beginItr = vec.begin();
// we can use the `auto` keyword of C++ which automatically assigns the 
// type of the iterator.
auto endItr = vec.end();
// So, whatever is the type of the `vec.end()`, it automatically assigns
// the type to the variable `endItr`
// Similarly, we can use this to write for the `beginItr`
auto beginItr = vec.begin();
endItr = endItr - 1;
for (auto itr = beginItr; i <= endItr; i++) {
    cout << *itr << " ";
}
```

Ok, now is there a still better way than this ?

Yes, we can use a `for_each` loop on this vector -

```cpp
for (auto i : vec) {
    cout << i << " "; // prints 1 2 0
}
```

Basically, for_each iterates over the container.

**Reverse Iterator**

```cpp
// [1, 2, 0]
auto reverseBegin = vec.rbegin(); // It will be pointing to 0
auto reverseEnd = vec.rend(); // It will be pointing to a memory location
// before 1 and this is a reverse iterator
```

To print the values inside the vector in the reverse order, we can write -

```cpp
for (auto i = reverseBegin; i < reverseEnd; i++) {
    cout << *i << " "; // prints 0 2 1
}
// This goes in the reverse direction. Since `reverseBegin` is a reverse 
// iterator, on doing i++, it goes in the reverse direction. Also, we need
// to write `< reverseEnd` not `> reverseEnd` as it's the reverse concept.
```

**Defining vector in another way**

```cpp
vector<int> vec(5);
vec.push_back(1);
vec.push_back(2);
vec.push_back(0);

for (auto i : vec) {
    cout << i << " ";
}
// This prints 0 0 0 0 0 1 2 0
```

> ![NOTE]
> 
> This means when we declare a vector with initial size 5, this creates a container of size 5 and since we didn't tell what elements to put inside it, it auto assigned 5 0s to itself.
> 
> More Eamples of assigning vectors with defined size -
> 
> ```cpp
> vector<int> vec(5, 8); // creates a vector - {8, 8, 8, 8, 8}
> vector<int> vec = {7, 8}; // assigned 
> // two elements and creates a vector - {7, 8}
> vec.push_back(1);
> vec.push_back(2);
> vec.push_back(0);
> // creates a vector vec = {7, 8, 1, 2, 0}
> ```

**Duplicate a Vector**

```cpp
vector<int> dupVec(vec);
// creates a dupVec = {7. 8, 1, 2, 0}
```

What if we don't want all the elements ?

Let's say we want to duplicate the `vec` from 8 till 0.

Then, what we do is - 

```cpp
vector<int> dupVec(vec.begin() + 1, vec.end());
// creates the dupVec = {8, 1, 2, 0}
vector<int> dupVec(vec.begin() + 2, vec.end());
// creates the dupVec = {1, 2, 0}
vector<int> dupVec(vec.begin(), vec.end() - 1);
// creates the dupVec = {8, 1, 2}
```

Basically, first_paramter of the `dupVec()` method is the `first` index and the second_paramter is `after_the_end` index.

**vec.front()**

Gives the first element of the vector.

Example - 

```cpp
cout << vec.front(); // prints the first element of the vector vec.
```

**vec.back()**

Gives the last element of the vector.

Example -

```cpp
cout << vec.back(); // prints the last element of the vector vec.
```

**vec.pop_back()**

Removes the last element from the vector.

Example -

```cpp
// [1, 2, 0]
vec.pop_back(); // removes 0 from the last
cout << vec.back(); // prints 2 which is now the last element of the 
// vector
```

**vec.erase()**

```cpp
// [0, 1, 2]
vec.erase(0); // Won't workkkkkkkk !
```

So, how it works ? We pass the reference to the memory location of where that element is stored rather than the element itself.

> <u>Note</u> that `vec.begin()` points to the `first_element` of the vector whereas `vec.end()` points to the `after_the_last_element` of the vector.

```cpp
vector<int> vec = {7, 8};
vec.push_back(1);
vec.push_back(2);
vec.emplace_back(0);
for (auto i : vec) {
    cout << i << " "; // prints - 7 8 1 2 0
}
cout << endl;

vec.erase(vec.begin() + 2); // erases the element at the 'first+2' place, 
// that is, at the 3rd place

for (auto i : vec) {
    cout << i << " "; // prints - 7 8 2 0
}
```

To delete `8 1 2` from the vector, 

We need to specify where we need to begin, that is, the pointer to the beginning element which we want to remove, and also need to specify the pointer to the the element which is 1 more than the last element which we want to remove.

Since our vector is `vec = {7, 8, 1, 2, 0}`, and we need to remove `8 1 2`,  we will write -

```cpp
vec.erase(vec.begin() + 1, vec.end() - 1);
for (auto i : vec) {
    cout << i << " "; // prints - 7 0
}
```

**vec.clear()**

This clears out all the elements of the vector.

```cpp
vec.clear(); // this clears out all the elements of the vector.
```

**Access the elements of the vector using square brackets and `.at()`**

```cpp
cout << vec.at(3); // prints the character at the 3rd index
cout << vec[3]; // does the same - use this always
```

**swap()**

```cpp
vector<int> vec1 = {7, 8};
vector<int> vec2 = {6, 4};
swap(vec1, vec2);
for (auto i : vec1) {
    cout << i << " "; // prints - 6 4
}
```

**insert()**

Example - 

```cpp
vector<int> vec = {7, 8, 8, 6, 7};
vec.insert(vec.begin(), 4); // this adds 4 before the `vec.begin()` in the 
// vector vec
for (auto i : vec) {
    cout << i << " "; // prints - 4 7 8 8 6 7
}
```

So, basically `.insert(pointer_before_we_need_to_insert, what_we_need_to_insert)` inserts the number given in the second parameter to the place before the given place in the first parameter.

**Summary of Vectors**

- initialisation

- .push_back()

- .front()

- .back()

- iterator

- for_each

- .erase()

- .insert()

- .size()

- access element - [], .at()

- swap()

- .clear()

---

## 3. List

List is also a container and works on the same-format as vectors.

```cpp
void explainList() {
    list<int> ls;
}
```

ls.push_back(), ls.erase(), ls.insert(), ls.pop_back(), iterator, etc work the same way as in the vector, also follows the 0-based indexing - starts at  0and ends at `ls.size() - 1`.

But there is a speciality of list - **list allows you to insert at front**

Example -

```cpp
list<int> ls = {6, 7};
ls.push_front(1);
for (auto i : ls) {
    cout << i << " "; // prints - 1 6 7 
}
```

`.push_front()` is the same as the `.emplace_front()`.

Also, we have a `.front()` method whivh just return the first element of the list and it's the same as in the case of vectors.

Look more for the differences in the methods of the list and vectors in C++.

**list-recap**

- push_front() / emplace_front()

- front()

---

## 4. deque

It's again the same thing, all the functions are same, behaves same as a vector or a list.

It also allows you to push_front().

---

So what is the difference between vectors, list, and deque ?

For vectors, the underlying data-structure that C++ uses is **arrays** - dynamic array.

For List and Deque, the underlying data-structure is linked-list.

---

## 5. Stack (LIFO)

This is the **LIFO** data-structure. Pile up the things, when you pick up, you get the last element you put inside.

```cpp
void explainStack() {
    // LIFO
    stack<int> st; // define a stack
}
```

To put the elements inside the stack, we have something known as push operation.

```cpp
st.push(1);
st.push(7);
```

Now, the first element of stack st is 7, you can't access 1 without first accessing 7.

Again, `st.size()` will return the size of the stack.

```cpp
cout << st.size() << endl; // prints 2
```

**Hw to get the elements of the Stack ?**

In case of Stack, we don't have any iterator concept or the for loop concept, the only way to get the elements of the stack is taking it out.

**st.top()**

```cpp
cout << st.top() << " ";  // prints 7
cout << st.top() << " ";  // prints 7 again
```

Hence, `st.top()` gives the topmost element. So, how can we get the next element which is 1 ? We first need to take out the first elememt to make the next element the first element and then we can access it using `.top()`.

Example  -

```cpp
cout << st.top() << " ";
st.pop(); // pops out the last element we inserted which is 7, now the 
// top element is 1.
cout << st.top() << " "; // prints 1
```

Hence, 

```cpp
void explainStack() {
    stack<int> st;

    st.push(1);
    st.push(7);

    cout << st.top() << " "; // 7
    st.pop(); // deletes 7 from the stack
    cout << st.top() << " "; // 1
    st.pop(); // deletes 1 from the stack
    cout << st.top() << " "; // RUN_TIME ERROR as there is no element 
// inside the stack
}
```

What if we need to print all the elements of the stack ?

Then we use our `while` loop.

```cpp
// LIFO
stack<int> st;
st.push(1);
st.push(7);
st.push(71);
st.push(73);
st.push(17);
st.push(27);
// To print all the elements of the stack
while(st.empty() == false) {
    cout << st.top() << " ";
    st.pop();
}
// prints - 27 17 73 71 7 1 - LastInFrstOut
```

> Stack offers a limited number of functionalities but is extremely useful.

**stack-recap**

- .push() / .emplace()

- .top()

- .pop()

- .size()

- swap()

- .empty()

---

## 6 Queue (FIFO)

Similar to Stack but follows FIRST-IN-FIRST-OUT policy. Just like the ticket-counter, whoever stands first gets the ticket first, go out first. It can be of any data-type like an array, double or any complex data-type.

```cpp
void explainQueue() {
    // FIFO
    queue<int> q;
    q.push(2);
    q.push(22);
    q.push(23);
    q.push(24);
    // To print all the elements of the queue
    while (q.empty() == false) {
        cout << q.front() << " ";
        q.pop();
    }
}
// prints - 2 22 23 24 - FirstInFirstOut
```

So, we can say `q.pop()` removes the first element standing on the ticket counter and the second element now becomes the first person standing in the line. And, `q.front()` returns the first element.

**queue-recap**

- push / emplace

- front

- pop

- size

- swap

- empty

---

## 7. Priority Queue (Internally heap)

PQ stores the highest element at the top. Under the hood, there is a heap implemented in this data-structure. Heap is nothing but a tree concept. Functions are pretty much the same as stacks and queues.

```cpp
void explainPQ() {
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(10);
    pq.push(8);
    cout << pq.top() << " "; // prints 10
    pq.pop() << endl;
    cout << pq.top() << " "; // prints 8
}
```

```cpp
while(pq.empty() == false) {
    cout << pq.top() << " ";
    pq.pop();
}
// prints 10 8 5 2
```

Hence, PQ  is an internal data-structure which stores elements on the basis of magnitude, the element with the highest magnitude being at the top.

> ![IMPORTANT]
> 
> To store the smallest element at the top - 
> 
> ```cpp
> priority_queue<int, vector<int>, greater<int>> pq;
> // This makes the PQ a `minimum_heap`
> // min-heap - internal data-structure which stores the minimum
> // element at the top.
> pq.push(5);
> pq.push(2);
> pq.push(10);
> pq.push(8);
> while(pq.empty() == false) {
>     cout << pq.top() << " ";
>     pq.pop();
> }
> // prints - 2 5 8 10
> ```

**PQ - RECAP**

- .top()

- .pop()

- .push() / .emplace()

- .empty()

- .size()

---

## 8. Set Container

Set is a data-structure that **stores only unique elements and in  ascending order.**

```cpp
void explainSet() {
    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(21);
    st.insert(21);
    st.insert(12);
// To print all the elements
    for (auto it : st) {
        cout << it << " ";    
    }
}
// prints - 2 12 21 
```

- use `.insert()` to insert the data into the set.

- use simple`for()` loop to iterate over (ascending-finite) set.

**Find the element in the set**

```cpp
auto it = st.find(12);
```

Returns the pointer to the found-element.

Searches for the element we want to find and finally reaches the `after_last_the_element` of the set if it doesn't find the required element.

```cpp
auto it = st.find(12);
if (it != st.end()) { // it is equal to the after_the_last_element if it 
// doesn't find the last element
    // if the element is found
    cout << *it;
}
```

Basically, we can say that `.find()` method returns an iterator to 12.

Hence, if we want to find an element in the set, what we do is - we use the `.find()` method and check is it's not equal to the end (`st.end()`) iterator(that is, the required element is there in the set) , then it means that it has found the required element and we simply ptint it.

**st.count()**

Returns 0 if the element is not there and returns 1 if the element is present inside the set.

Example -

```cpp
st.count(21); // returns 1 since 21 is present in our set.
```

> Note that `st.count()` doesn't count the number of occurences of the number in the set as the set only stores each element only once.

**st.erase()**

To erase a particular element, we use the `.erase()` method.

Example -

```cpp
set<int> st;
st.insert(21);
st.insert(12);
st.insert(12);
st.insert(2);
// creates a set st = {2, 12, 21}

st.erase(21); // erases the element 21 from the set st

for(auto it : st) {
    cout << it << " ";
}
// prints 2 12
```

Now, to erase the last element, we can do-

```cpp
auto it = st.end(); // points to the after_the_last_element
it--; // points to the last element
st.erase(it); // removes 21 which is the last element
for(auto it : st) {
    cout << it << " ";
}
// prints - 2 12
```

To remove the last-second element, we can do-

```cpp
auto it = st.end();
it--; // pointing to 21
it--; // pointing to 12
st.erase(it);
for (auto it : st) {
    cout << it << " ";
}
// prints 2 21
```

Thus, we can remove any element of the set with `.erase()` method by simply passing it the pointer to element we want to remove or simply if we know the value of the element we want to remove, we can do that too by passing the value also.

**Now, to delete multiple element of the set, what we do is -**

```cpp
set<int> st;
st.insert(2);
st.insert(21);
st.insert(12);
st.insert(211);
st.insert(213);

for (auto it : st) {
    cout << it << " ";
}
// prints - 2 12 21 211 213
```

Now, to erase the elements from 12 to 211, we can pass the two arguments inside the `.erase()` method where the first_argument is the pointer to the first-element-we-want-to-remove and the second_argument is the pointer to the 1-more-than-the-last-element-we-want-to-remove.

```cpp
st.erase(st.begin() + 1, st.end() - 1); // erases `12` to `211`
// But basically maybe this won't work as we need to pass the iterators
// or maybe there is another issue.
auto it1 = st.begin();
it1++;
auto it2 = st.end();
it2--;
st.erase(it1, it2);
for (auto it : st) {
    cout << it << " ";
}
// prints 2 213
```

So basically, `.erase()` method works like this - `st.erase(iterator OR element OR (it1, it2))`.

**lower_bound and upper_bound in the set**

1. **lower_bound** - returns an iterator that points to an element that is >= the number given.

Example - 

```cpp
auto it = st.lower_bound(11); // pointer to 12
cout << *it; // prints 12
```

If it doesn't find any element which is greater than or equal to the given element, then it always becomes the end iterator pointing to the after_the_end_element.

Example -

```cpp
auto it = st.lower_bound(214);
if (it == st.end()) {
    cout << "end";
}
// prints 214 as there is no element greater than or equal to 214 in our
// set which contains - 2 12 21 213 214
```

> Why are we doing this check that if it's not the end iterator ? This is because we don't do *end_iterator as it's not valid memory location.

2. **upper_bound** - returns the iterator that points to an element that is `>` the number given.

Example - 

```cpp
auto it = st.upper_bound(12);
cout << *it; // prints 21 which is greater than the number given 12.
```

**Set Container Recap**

- insert / emplace

- .find()

- .erase(iterator, element, (it1, it2))

- .count()

- .lower_bound()

- .upper_bound()

---

## 9. MultiSet Data Structures

Very similar to set data structure, but it also stores the repeating elements as well in ascending order ofcourse.

Example - 

```cpp
void explainMultiSet() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(0);
    ms.insert(2);
    ms.insert(21);
    ms.insert(21);

    for (auto it : ms) {
        cout << it << " ";    
    }
}
//prints - 0 1 1 1 1 2 21 21
```

**ms.find()**

```cpp
auto it = ms.find(1);
// points to the first_occurence of the element 1
```

**ms.erase()**

```cpp
auto it = ms.erase(1); // erases all the occurences of 1
for (auto it : ms) {
    cout << it << " ";
}
// prints- 0 2 12 21
```

To erase just the first occurence of `1`, we can do -

```cpp
auto it = ms.erase(ms.find(1));
// ms.find(1) is an iterator to the first occurence of 1
for (auto it : ms) {
    cout << it << " ";
}
// prints- 0 1 1 1 2 12 21
```

**ms.lower_bound() and ms.upper_bound() is similar**

**ms.count()** -  returns the count or the number of occurences of the given element

Example - 

```cpp
cout << ms.count(1); // prints- 4
```

**multiset-recap**

- ms.insert()

- ms.find()

- ms.erase()

- ms.lower_bound()

- ms.upper_bound()

- ms.count()

---

## 10. Unordered Set (lower_bound and ub doesn't exist)

Doesn't store the elements in any order but always **store unique elements**.

```cpp
void explainUnorderedSet() {
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(1);
    st.insert(11);
    st.insert(11);
    st.insert(12);
    st.insert(12);
    st.insert(12);

    for (auto it : st) {
        cout << it << " ";
    }
}
// prints 12 2 11 1
```

All the functionalities of set apply over here apart from upper_bound() and lower_bound() because it's not sorted.

Why do we need **unordered-set** ? Because it has **better time-complexity**.

```cpp
auto it = st.find(11); // O(1)
// O(N) - Rare scenario
```

It mostly happens in constant time-complexity - **O(1)**.

If we don't care about the order and all we need is a better search-functionality, then we use unordered set data structure.

---

## 11. Map Data Structure

It's like the dictionary in Python, stores key-value pairs.

**It stores key-value pairs on the basis of the concept of pairs and stores in the ascending order of the keys.**

To store Roll_Numbers with Names (keys will be integers and values will be names or strings) , we write -

```cpp
void explainMap() {
    map<int, string> mpp;
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp[3] = "cat";
    mpp.insert({4, "Raj"});
}
```

**Syntax to define a map -**

`map_name[key] = value;` OR `map_name.insert({key, value});` OR `map_name.emplace({key, value});`.

These `key:values` are stored in the comcept of **pairs**

Hence, to print all the key-value pairs of a map, we write -

```cpp
for (auto it : mpp) {
    cout << it.first << "->" << it.second << endl;
}
// prints-
// 1->abc
// 2->bcd
// 3->cat
// 4->Raj
```

We can't store 2 different values to the same key in a map, for example - if I say `mpp[1] = "abc";` and then I say `mpp[1] = "Beast";` then the map `mpp` stores `"Beast"` on the key `1` and not `"abc"`- Stores everything unique and unique keys in a sorted ascending order.

**mpp.find()**

Returns the iterator or pointer to the **key-value pair** for the **given key_name**.

Example -

```cpp
auto it = mpp.find(4); // pointer to {4, "Raj"}
// To print - first get hold of *it which is the value or the pair and 
// then use .first() and .second() to get the key and the value
cout << (*it).first << "->" << (*it).second << endl;
```

What if we try to find a `key-value` pair which does not exist ? Then in that case, it always returns an iterator to the **end**.

Example -

```cpp
auto it = mpp.find(5);
if (it == mpp.end()) {
    cout << "not found";
}
```

**lower_bound** - returns the pointer to the pair with the key greater than or equal to the given key.

**upper_bound** - returns the pointer to the pair with the key greater than the given key.

> Note - Key and the Value can be anything that you want, even a vector or a pair.

**Map-recap**

- .insert()  / .emplace() / mpp[key] = value

- .find()

- .empty()

- .size()

- .lower_bound()

- .upper_bound()

---

## 12. Unordered Map

Similar to unordered-set. The only difference from the map is that it doesn't store the key-value pairs in any order of keys. And, that's why the Time-Complexity of unordered_map is **O(1)** for any function, like `find()` etc until and unless the data-set is very large and there are collissions inside the map, whereas map takes `O(N)` TC.

When do we use Unordered_map ? When we don't care about the order of map and all we care about is a faster search functionality.

---

## 13. Multimap Data Structure

We know that a map stores pairs n ascending order of keys and also only store unique keys.

With multi-map data structure, we can **same keys with same values again and again** and **same keys wiht different values** and also it stores key-value pairs in the ascending order of keys.

Examples -

```cpp
multimap<int, char> mpp;
mpp.insert({3, 'b'});
mpp.insert({1, 'a'});
mpp.insert({1, 'b'});
mpp.insert({1, 'a'});
mpp.insert({2, 'a'});
mpp.insert({2, 'a'});
mpp.insert({2, 'b'});
for (auto it : mpp) {
    cout << it.first << "->" << it.second << endl;
}
// prints -
1->a
1->b
1->a
2->a
2->a
2->b
3->b
```

We can see that multimap stores key-value pairs in the ascending order of keys and not in the ascendng order of values. Also, it can store multiple key-value pairs with the same keyNames and different or same values.

**What if I need to figure out all the range of the key-2 ?**

All we need to do is - 

```cpp
auto it = mpp.equal_range(2);
```

This returns the pair of iterators , where the first iterator points to the first starting place where the key-2 starts and the second pair points to the ending place of the key-2.

So, to iterate over it, what we do is -

```cpp
auto it = mpp.equal_range(2);
for (auto i = it.first; i != it.second; i++) {
    // i != it.second since in a multimap, key-values are not
    // stored in any order so doing <, >, <=, >= doesn't make sense.
    // it.first is an iterator and it.second is also an iterator and 
    // hence i is also an iterator.
    cout << (*i).first << "->" << (*i).second << endl;
}
// prints-
2->a
2->a
2->b
```

**Multimap is DONE**

---

## Functions and Algorithms

### 1. Sort Function

We have a sort() function which sorts the array in simple way.

```cpp
void explainSort() {
    int arr[5] = {6, 2, 1, 7, 8};
    sort(arr, arr + 5); // starts from the 0 index till the arr+5-1 index
//which is 4th index
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
// prints - 1 2 6 7 8 
```

What if we want t just sort {2, 1, 7} in {6, 2, 1, 7, 8}, So we write -

```cpp
sort(arr+1, arr+4); // sorts like this - 6 1 2 7 8 
```

> Note that the first parameter is the index we want to start the sort from, whereas the second parameter is 1 more than the index we want to end our sort at. So, it basically doesn't include the last index.

We can also sort the vector with the `sort()` function. For Example- 

```cpp
vector<int> vec = {5, 1, 7, 0, 1};
sort(vec.begin(), vec.end());
for (auto it : vec) {
    cout << it << " ";
} // prints 0 1 1 5 7 
```

To just sort {7, 1} out of {5, 7, 1, 0, 1}, we can write -

```cpp
sort(vec.begin() + 1, vec.begin() + 3); // one more than the end index
// sorts like this - {5, 1, 7, 0, 1}
```

---

### 2. accumulate

Just sums up the elements of the container.

Syntax - `accumulate(starting_index, one_more_than_the_ending_index, initial_sum);`

Example -

```cpp
int arr[5] = {6, 2, 1, 7, 0};
cout << accumulate(arr, arr+5, 0); // prints 16
// Note that here `arr` refers to the 0th index of the array `arr`
```

---

### 3. count

Returns the number of times a given number appears.

Syntax - `count(starting_index, one_more_than_the_ending_index, number_to_count);`

Example -

```cpp
int arr[5] = {6, 2, 1, 1, 0};
int num = 1;
cout << count(arr, arr + 5, num); // prints 2
```

---

### 4. find

We have done find with sets and maps, but there is a slight difference in case of arrays and vectors.

Returns the iterator to the first occurence of the given number in the array.

Syntax - `find(starting_index, final_index + 1, number_to_find);`

Example -

```cpp
int arr[5] = {6, 2, 1, 1, 0};
auto it = find(arr, arr + 5, 1);
cout << *it;
// and if the number passed is not inside the array, the pointer reaches
// the last element of the array.
if (it == (arr + 5)) { // arr is also a pointer or iterator to the first
// element of the array `arr`
    cout << "not found";
}
```

Similarly, it works for the vectors with `vec.begin()` and `vec.end()`.

### 5. next_permutation

**Used a lot and very interesting**

Works with arrays, string, vectors. What it does is - prints all the permutations in a sorted order.

Example -

```cpp
string str = "abc";
do {
    cout << str << endl;
} while(next_permutation(str.begin(), str.end()));
// prints-
abc
acb
bac
bca
cab
cba
```

Here, the next_permutation of `bca` is `cab`.

If we start with `string str = "bca";` then first of all, `do` prints the string `bca` and then it prints the next_permutation if it's available, if the next_permutation is available, then `next_permutation(str.begin(), str.end());` returns true and the `while` loop runs. And thus, prints all the next permutations -

```cpp
string str = "bca";
do {
    cout << str << endl;
} while(next_permutation(str.begin(), str.end()));
```

We can also permutate a part of the string. Example -

```cpp
string str = "abc";
do {
    cout << str << endl;
} while(next_permutation(str.begin(), str.begin() + 2));
// prints-
abc
bac
```

---

### 6. prev_permutation

Returns true if the preious permutation exists. Example -

```cpp
abc
acb
bac
bca
cab
cba
```

If my initial string is "cba" then the prev_permutation is "cab" and again the prev_permutation is "bca" and so on. . .

Example Run -

```cpp
string str = "cba";
do {
    cout << str << endl;
} while(prev_permutation(str.begin(), str.begin() + 3));
// prints-
cba
cab
bca
bac
acb
abc
```

Hence, with next_permutation and prev_permutation, you can just give the initial iterator and the end iterator, and get all the permutation without writing the logic of getting all the iterations.

---

### 7. max_element

Always returns the pointer to the max_element of the array.

```cpp
int arr[5] = {7, 6, 5, 10, 9};
auto it = max_element(arr, arr+5);
cout << *it; // prints - 10
```

SIMILARLY, we have **min_element** -

```cpp
int arr[5] = {7, 6, 5, 10, 9};
cout << *min_element(arr, arr+5);
// prints - 5
```

---

### 8. reverse

As the name suggests, it reverses the array.

```cpp
int arr[] = {7, 6, 5, 10, 9};
reverse(arr, arr + 5); // reverses the entire array 
for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
// prints - 9 10 5 6 7 
```

Just give the starting_iterator and the end_iterator, and it reverses the string.

---

### 9. pow

```cpp
cout << pow(2, 9); // 512
```

---

### 10. comparator

What happens when a sorting functi on is called ?

Let's take an example -

```cpp
int arr[] = {5, 6, 1, 2};
sort(arr, arr + 4);
for (int i = 0; i < 4; i++) {
    cout << arr[i] << " ";
}
```

Internally, what happens -

```cpp
el1 is 5
el2 is 6
check if el1 should be before el2 - yes since 5 < 6
hence, there is an inernal comparator that takes el1 and el2 and tells 
you if el1 should be before el2 or not
- And this thing keeps on repeating.
```

What if we want to sort this array in the descending order rather than the ascending order ? Then we need to modify the internal comparator.

That's when the concept of internal comparator comes into the picture.

> Always remember that the comparator is just a function which returns either true or false.

Example -

```cpp
// e11, el2
// tells true if el1 is before el2 - default internal comparator
// tells true if el1 has to be after the el2 - modified
bool internalComparator(int el1, int el2) {
    if (el1 < el2) return false;
    return true; // if el1 > el2 since descending comparator it is
}

Now we need to pass this comparator to the sort() method

int arr[4] = {5, 6, 1, 2};
sort(arr, arr + 4, internalComparator);
for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
} // prints - 6 5 2 1 
```

**Understanding Internal Comparators in depth** -

Let's take the example of an array of pairs.

```cpp
bool internalComparator() {

}
pair<int, int> arr[] = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
// pair is a data-type of things we want to store inside this array 
// named `arr`
```

**Problem** - Write a comparator to sort the elements of the array arr in such a way that the pair with the largest second element comes before the pair with the smaller second element and in case of a tie in the second element, pair with the smaller first element comes before the pair with the bigger first element.

**Solution Walkthrough**

```cpp
pair<int, int> arr[] = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
sort(arr, arr + 5);
for (int i = 0; i < 5; i++) {
    cout << "{" << arr[i].first << ", " << arr[i].second << "} ";
}
// prints - {1, 5} {1, 6} {2, 6} {2, 9} {3, 9}
```

This  is the result of the default internalComparator. What we need is a new comparator which sorts this array of pairs in the descending order of their second element and in the ascending order of their first element in case of a tie in the second elements for any two pairs.

> Note that we can also overwrite the default comparator of the Priority Queue by our internal comparator.

Let's overwrite this default rule to solve our problem -

```cpp
bool internalComparator(pair<int, int> el1, pair<int, int> el2) {
    if (el1.second > el2.second) return true;
    if (el1.second < el2.second) return false;
    if (el1.first < el2.first) return true;
    return false;
}
pair<int, int> arr[] = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
sort(arr, arr + 5);
for (int i = 0; i < 5; i++) {
    cout << "{" << arr[i].first << ", " << arr[i].second << "} ";
}
// prints- {2, 9} {3, 9}, {1, 6} {2, 6} {1, 5}
```

What if we want to over-write another rule which is - if the second elements of the two pairs are the same, then whichever pair has the greater first element will come first, that is, sort in the descending order of the second element and also sort in the descending order of the first element in case of a tie in the second element.

Then, my try which works -

```cpp
#include <bits/stdc++.h>
using namespace std;

bool internalComparator(pair<int, int> el1, pair<int, int> el2) {
    // should print - {3, 9} {2, 9}, {2, 6} {1, 6} {1, 5}
    // if it returns false it swaps
    // we want to return true if the order is correct as we desire
    if (el1.second > el2.second) {
        return true;
    }
    else {
        if (el1.second == el2.second) {
            if (el1.first > el2.first) return true;
            return false;
        }
        return false;
    }
}

int main() {

    pair<int, int> arr[] = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
    sort(arr, arr + 5, internalComparator);
    for (int i = 0; i < 5; i++) {
        cout << "{" << arr[i].first << ", " << arr[i].second << "} ";
    }
    // prints - {3, 9} {2, 9}, {2, 6} {1, 6} {1, 5}
}
```

---

**And we have completed -**

- Containers

- Algorithms

- Functions

- Iterators

---

That's all about the C++ STL.

For more examples, look at Striver Notes.

Thank You :heart:
---
