class Student {
   private:
    int age, rollNumber;
    string name, grade;

   public:
    // setter
    void setName(string s) {
        // we can also include some logic so that nobody can set their name as
        // empty
        if (s.empty()) {
            cout << "Invalid Name";
            return;
        }
        name = s;
    }
    void setAge(int a) { age = a; }
    void setRollNumber(int r) { rollNumber = r; }
    void setGrade(string g) { grade = g; }

    // getter
    int getAge() { return age; }
    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
    string getGrade() { return grade; }
};
int main() {
    Student s1;
    s1.setAge(21);
    s1.setGrade("A+");
    s1.setName("Rohit");
    s1.setRollNumber(456);

    s1.setName("");  // Invalid Name

    cout << s1.getAge();  // prints 21

    return 0;
}