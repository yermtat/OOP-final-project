#pragma once

int CalcYearWeek(int iYear, int iMonth, int iDay, int iWeekDay) // функция для подсчета недели честным образом позаимствована у пользователя afull
{                                                               // на stack overflow
    int iLeap = 0;
    static const int ppiYearDays[2][13] =
    {
        /* Normal year */
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        /* Leap year */
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };
    /* Check for leap year */
    if (((iYear % 4) == 0) && (((iYear % 100) != 0) || ((iYear % 400) == 0)))
    {
        iLeap = 1;
    }
    /* Calculate the year week */
    return (((ppiYearDays[iLeap][iMonth] + iDay) - (iWeekDay + 7) % 7 + 7) / 7) + 1;
}

int CalcWeekDay(int iDay, int iMonth, int iYear)
{
    if (iMonth < 3)
    {
        iMonth += 12;
        iYear -= 1;
    }
    
    int day = (iDay + (2 * iMonth) + (6 * (iMonth + 1) / 10) + iYear
        + (iYear / 4) - (iYear / 100) + (iYear / 400)) % 7;

    return (day == 6) ? 0 : day + 1;
}
