// Playing with a few standard library algorithms
// 
// Haruto Hirata
// A00595113
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

struct Student {
    std::string name;
    int grade;

    Student(const std::string& n, int g)
        : name(n), grade(g) {
    }
};

// Display a student
void displayStudent(const Student& student) {
    std::cout << student.name << " - Grade: " << student.grade << std::endl;
}

// Check if student has 90+ grade
bool isHonorStudent(const Student& student) {
    return student.grade >= 90;
}

// Check for 60- grade
bool isFailingStudent(const Student& student) {
    return student.grade < 60;
}

// Add curve to student grade
Student applyCurve(const Student& student) {
    int newGrade = std::min(100, student.grade + 5); // add 5 points, max 100
    return Student(student.name, newGrade);
}

int main() {
    // test data
    std::vector<Student> students = {
        Student("Student 1", 85),
        Student("Student 2", 92),
        Student("Student 3", 78),
        Student("Student 4", 56),
        Student("Student 5", 95),
        Student("Student 6", 82),
        Student("Student 7", 67),
        Student("Student 8", 91),
        Student("Student 9", 88),
        Student("Student 10", 74)
    };

    std::cout << "=== Original Student List ===" << std::endl;
    std::for_each(students.begin(), students.end(), displayStudent);
    std::cout << std::endl;

    // Algorithm 1: Sort by grade 
    std::cout << "=== Algorithm 1: Sorting students by grade ===" << std::endl;
    std::sort(students.begin(), students.end(),

        [](const Student& a, const Student& b) {
            return a.grade > b.grade;  // ORDER BY grade DESC
        });
    std::for_each(students.begin(), students.end(), displayStudent);
    std::cout << std::endl;

    // Algorithm 2: Find first 90+ student
    std::cout << "=== Algorithm 2: Finding first student who has 90+ grade ===" << std::endl;
    auto it = std::find_if(students.begin(), students.end(), isHonorStudent);
    if (it != students.end()) {
        std::cout << "First student who has 90+ grade found: ";
        displayStudent(*it);
    }
    else {
        std::cout << "No student who has 90+ grade found." << std::endl;
    }
    std::cout << std::endl;

    // Algorithm 3: Count different types of students
    std::cout << "=== Algorithm 3: Counting students by performance ===" << std::endl;
    int honorCount = std::count_if(students.begin(), students.end(), isHonorStudent);
    int passingCount = std::count_if(students.begin(), students.end(),
        [](const Student& s) { return s.grade >= 60; });
    int failingCount = std::count_if(students.begin(), students.end(), isFailingStudent);

    std::cout << "Honor students (90-100): " << honorCount << std::endl;
    std::cout << "Passing students (60+): " << passingCount << std::endl;
    std::cout << "Failing students (60-): " << failingCount << std::endl;
    std::cout << std::endl;

    // Algorithm 4: Add curve to all grades
    std::cout << "=== Algorithm 4: Applying 5 points curve to all students ===" << std::endl;
    std::vector<Student> curved;
    curved.reserve(students.size());
    std::transform(students.begin(), students.end(), std::back_inserter(curved), applyCurve);

    // show the curved results
    for (const auto& s : curved) {
        displayStudent(s);
    }
    std::cout << std::endl;

    // Algorithm 5: Partition passing vs failing
    std::cout << "=== Algorithm 5: Partitioning students ===" << std::endl;
    std::vector<Student> temp = curved;
    auto partition_point = std::partition(temp.begin(), temp.end(),
        [](const Student& s) { return s.grade >= 60; });

    std::cout << "Passing students:" << std::endl;
    std::for_each(temp.begin(), partition_point, displayStudent);
    std::cout << "\nFailing students:" << std::endl;
    std::for_each(partition_point, temp.end(), displayStudent);
    std::cout << std::endl;

    // Algorithm 6: Calculate average
    std::cout << "=== Algorithm 6: Calculating average grade ===" << std::endl;
    int total = std::accumulate(curved.begin(), curved.end(), 0,
        [](int sum, const Student& s) {
            return sum + s.grade;
        });
    double avg = static_cast<double>(total) / curved.size();
    std::cout << "Average grade after curve: " << avg << std::endl;
    std::cout << std::endl;

    // Algorithm 7: Find min and max
    std::cout << "=== Algorithm 7: Find min and max ===" << std::endl;
    auto min_grade = std::min_element(curved.begin(), curved.end(),
        [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        });
    auto max_grade = std::max_element(curved.begin(), curved.end(),
        [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        });

    std::cout << "Lowest grade: ";
    displayStudent(*min_grade);
    std::cout << "Highest grade: ";
    displayStudent(*max_grade);

    return 0;
}