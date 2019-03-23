/**

+---------------+----------+------+-----+---------+-------+
| Field         | Type     | Null | Key | Default | Extra |
+---------------+----------+------+-----+---------+-------+
| studentNo     | int(4)   | NO   |     | NULL    |       |
| subjectNo     | int(4)   | NO   |     | NULL    |       |
| examDate      | datetime | NO   |     | NULL    |       |
| studentResult | int(4)   | NO   |     | NULL    |       |
+---------------+----------+------+-----+---------+-------+

**/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> studentNo{
    10000, 10001, 10002, 10003, 10004, 10005,
    10006, 10007, 10008, 20000, 20010, 30011, 
    30012
};

vector<int> subjectNo{
    1, 2, 3
};

int main()
{
    // Loop through student id and course id;
    for (int student : studentNo)
    {
        for (int subject : subjectNo)
        {
            if (double(rand()) / RAND_MAX > 0.3)  // if so, generate an exam result.
            {
                int year = 2018;
                int month = rand() % 12 + 1, day = rand() % 28 + 1;
                int result = rand() % 100 + 1;
                printf("(%d, %d, '%d-%d-%d', %d),\n", student, subject, year, month, day, result); 
            }
        }
    }    
}
