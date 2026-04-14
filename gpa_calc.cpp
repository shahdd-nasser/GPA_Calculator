#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

double gradeTopoints(double mark)
{
    if (mark >= 96)
        return 4.0;
    if (mark >= 92)
        return 3.7;
    if (mark >= 88)
        return 3.4;
    if (mark >= 84)
        return 3.2;
    if (mark >= 80)
        return 3.0;
    if (mark >= 76)
        return 2.8;
    if (mark >= 72)
        return 2.6;
    if (mark >= 68)
        return 2.4;
    if (mark >= 64)
        return 2.2;
    if (mark >= 60)
        return 2.0;
    if (mark >= 55)
        return 1.5;
    if (mark >= 50)
        return 1;
    else
        return 0;
}

struct courses
{
    string name;
    double mark;
    int credithours;
};

double GPACalc(vector<courses> course)
{
    double totalpoints = 0;
    int totalhours = 0;

    for (int i = 0; i < course.size(); i++)
    {
        double p = gradeTopoints(course[i].mark);

        totalhours += course[i].credithours;
        totalpoints += p * course[i].credithours;
    }

    return totalpoints / totalhours;
}

int main()
{
    int n;
    cout << "Enter number of courses: ";
    cin >> n;
    cout << "\n";

    vector<courses> course;
    for (int i = 0; i < n; i++)
    {
        courses c;
        cout << "Enter course name: ";
        cin >> c.name;
        cout << "Enter course mark: ";
        cin >> c.mark;
        cout << "Enter course credit hours: ";
        cin >> c.credithours;
        cout << "\n";
        course.push_back(c);
    }

    double GPA = round(GPACalc(course) * 100) / 100;

    string generalgrade;
    if (GPA >= 3.7)
        generalgrade = "Excellent";
    else if (GPA >= 3.0)
        generalgrade = "Very Good";
    else if (GPA >= 2.4)
        generalgrade = "Good";
    else if (GPA >= 1.0)
        generalgrade = "Pass";
    else
        generalgrade = "Fail";

    cout << "GPA is " << fixed << setprecision(2) << GPA << endl;
    cout << generalgrade;

    return 0;
}
