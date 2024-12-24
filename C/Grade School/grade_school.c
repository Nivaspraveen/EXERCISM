#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "grade_school.h"

bool name_exists(roster_t *roster, char *name)
{
    int index = 0;
    while ((size_t)index < roster->count)
    {
        if (strncmp(roster->students[index].name, name, MAX_NAME_LENGTH) == 0)
            return true;
        index++;
    }
    return false;
}

bool compare_students(student_t *s1, student_t *s2)
{
    if (s1 == 0 && s2 == 0)
        return true;
    if ((s1 == 0 && s2 != 0) || (s1 != 0 && s2 == 0))
        return false;
    return s1->grade == s2->grade && strncmp(s1->name, s2->name, MAX_NAME_LENGTH) == 0;
}

void init_roster(roster_t *roster)
{
    *roster = (roster_t){0};
}

bool add_student(roster_t *roster, char name[], uint8_t grade)
{
    if (name_exists(roster, name))
        return false;
    int index = -1;
    student_t empty_student = {0};
    while (index < MAX_STUDENTS)
    {
        if (index == -1 && !compare_students(&(roster->students[0]), &empty_student) && roster->students[0].grade >= grade)
            break;
        if (index == -1)
            index++;
        if (compare_students(&(roster->students[index]), &empty_student) || (!compare_students(&(roster->students[index + 1]), &empty_student) && roster->students[index + 1].grade >= grade))
            break;
        index++;
    }
    while (index < MAX_STUDENTS)
    {
        if (index == -1 && roster->students[0].grade > grade)
            break;

        if (index == -1 && strncmp(roster->students[0].name, name, MAX_NAME_LENGTH) >= 0)
            break;

        if (index == -1)
            index++;

        if (compare_students(&(roster->students[index]), &empty_student) || (!compare_students(&(roster->students[index + 1]), &empty_student) && (roster->students[index + 1].grade > grade || strncmp(roster->students[index + 1].name, name, MAX_NAME_LENGTH) >= 0)))
            break;

        index++;
    }
    if (index == MAX_STUDENTS || (index + 1 == MAX_STUDENTS && !compare_students(&(roster->students[index]), &empty_student)))
        return false;

    if (index + 1 != MAX_STUDENTS && !compare_students(&(roster->students[index + 1]), &empty_student))
    {
        student_t temp = roster->students[index + 1];
        int i = index + 2;
        while ((size_t)i < roster->count + 1)
        {
            student_t swap = roster->students[i];
            roster->students[i] = temp;
            temp = swap;
            i++;
        }
    }

    if (index == -1 || !compare_students(&(roster->students[index]), &empty_student))
        index++;

    roster->students[index].grade = grade;
    strncpy(roster->students[index].name, name, MAX_NAME_LENGTH);

    if (roster->count < MAX_STUDENTS)
        roster->count++;

    return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade)
{
    roster_t gradeRoster;
    init_roster(&gradeRoster);

    int index = 0;
    while ((size_t)index < roster->count)
    {
        if (roster->students[index].grade == grade)
            add_student(&gradeRoster, roster->students[index].name, roster->students[index].grade);
        index++;
    }

    return gradeRoster;
}