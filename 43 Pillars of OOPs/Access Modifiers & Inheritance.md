![alt text](image.png)

---
## Example:

```cpp
class A {
protected:
    int x = 10;
};

class B : public A {
public:
    void show() {
        cout << x; // accessible
    }
};
```