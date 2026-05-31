Variations of Scopes in C++
Apart from the primary classification of the scopes as global and local, there are few other specialized variations of these scopes that divides the declared variable based on its accessibility and visibility. Following are some common variations of variable scopes in C++.

- Instance Scope
- Static Member Scope
- Namespace Scope

1. Instance scope
Variables which are accessible to the whole class.
```cpp
#include <iostream>
using namespace std;
class A {
    public:
        int instanceVar;

        A(int val) {
            instanceVar = val;
        }

        void display() {
            cout << instanceVar << endl;
        }
};

int main() {
    A a1(1);
    a1.display();

    A a2(33);
    a2.display();

    return 0;
}
```

<p>Output : 
1
33</p>

2. Static Member Scope
Shared across all the instances of the class and also can be accessed using the class name wthout creating the instance.
```cpp
#include <iostream>
using namespace std;

class A
{
  public:
  
    // Static variable with static scope i.e. accessible in whole class
    static int staticVar;
};

int A::staticVar = 1;

int main() {
    cout << A::staticVar;

    return 0;
}
```

<p>Output:
1</p>

3. Namespace Scope
A namespace in C++ is a container that allows users to create a separate scope where the given variables are defined. It is used to avoid name conflicts and group related code together. These variables can be then accessed using their namespace name and scope resolution operator.

```cpp
using namespace std;
namespace N
{
    int namespaceVar = 10;
}
int main() {
    cout << N::namespaceVar << endl;
}
```

<p>Output:
10
</p>

