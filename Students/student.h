
class Student {
    std::string name;
    int result;
    std::string grade;
    public:

        Student() {
            result = -1;
        }

        std::string getName() {
            return name;
        }
        void setName(std::string n) {
            name = n;
        }
        int getResult() {
            return result;
        }
        void setResult(int r) {
            result = r;
        }
        std::string getGrade() {
            return grade;
        }
        void setGrade(std::string g) {
            grade = g;
        }
};