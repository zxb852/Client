#ifndef DATA_H
#define DATA_H

#include<time.h>
#include<stdio.h>

struct record_time
{
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;

    record_time() :year(0), month(0), day(0), hour(0), min(0), sec(0)
    {}
    record_time(int iyear, int imonth, int iday, int ihour, int imin, int isec)
    {
        set(iyear, imonth, iday, ihour, imin, isec);
    }
    record_time(const tm* p)
    {
        year = p->tm_year + 1900;
        month = p->tm_mon + 1;
        day = p->tm_mday;
        hour = p->tm_hour;
        min = p->tm_min;
        sec = p->tm_sec;
    }

    void set(int iyear, int imonth, int iday, int ihour, int imin, int isec)
    {
        year = iyear;
        month = imonth;
        day = iday;
        hour = ihour;
        min = imin;
        sec = isec;

        if (year > 2000 && year < 3000 && month>0 && month < 13 && day>0 && day < 32 && hour >= 0 && hour < 24 && min >= 0 && min < 60 && sec >= 0 && sec < 60)
            return;

        while (true) {
            if (year > 2000 && year < 3000 && month>0 && month < 13 && day>0 && day < 32 && hour >= 0 && hour < 24 && min >= 0 && min < 60 && sec >= 0 && sec < 60)
                break;
            if (sec > 59) {
                sec -= 60;
                min += 1;
            }
            if (sec < 0) {
                sec += 60;
                min -= 1;
            }

            if (min > 59) {
                min -= 60;
                hour += 1;
            }
            if (min < 0) {
                min += 60;
                hour -= 1;
            }

            if (hour > 23) {
                hour -= 24;
                day += 1;
            }
            if (hour < 0) {
                hour += 24;
                day -= 1;
            }

        }

        if (year > 2000 && year < 3000 && month>0 && month < 13 && day>0 && day < 32 && hour >= 0 && hour < 24 && min >= 0 && min < 60 && sec >= 0 && sec < 60)
            return;
        else {
            year = 0;
            month = 0;
            day = 0;
            hour = 0;
            min = 0;
            sec = 0;
        }
    }
    void settimenow()
    {
        time_t timep;
        time(&timep);
        struct tm* nowTime = localtime(&timep);
        nowTime->tm_year += 1900;
        nowTime->tm_mon += 1;
        year = nowTime->tm_year;
        month = nowTime->tm_mon;
        day = nowTime->tm_mday;
        hour = nowTime->tm_hour;
        min = nowTime->tm_min;
        sec = nowTime->tm_sec;
    }
    void clear()
    {
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        min = 0;
        sec = 0;
    }
    bool isempty()
    {
        if (year == 0 && month == 0 && day == 0 && hour == 0 && min == 0 && sec == 0)
            return true;
        else
            return false;
    }


    bool operator<(const record_time& m)
    {
        if (year < m.year) return true;
        else if(year > m.year) return false;

        if (month < m.month) return true;
        else if(month > m.month) return false;

        if (day < m.day) return true;
        else if(day > m.day) return false;

        if (hour < m.hour) return true;
        else if(hour > m.hour) return false;

        if (min < m.min) return true;
        else if(min > m.min) return false;

        if (sec < m.sec) return true;
        else if(sec > m.sec) return false;

        return false;
    }
    bool operator<=(const record_time& m)
    {
        if (year == m.year && month == m.month && day == m.day && hour == m.hour && min == m.min && sec == m.sec)
            return true;
        if (operator<(m))
            return true;
        return false;
    }

};


#endif // DATA_H
