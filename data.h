#ifndef DATA_H
#define DATA_H

#include<time.h>
#include<stdio.h>

struct record_time
{
    record_time():year(0),month(0),day(0),hour(0),min(0),sec(0)
    {}

    record_time(int iyear,int imonth, int iday, int ihour,int imin, int isec)
    {
        if(iyear>2000 && iyear<3000)
            year=iyear;
        if(imonth>0 && imonth<13)
            month=imonth;
        if(iday>0 && iday<32)
            day=iday;
        if(ihour>0 && ihour<25)
            hour=ihour;
        if(imin>0 && imin<61)
            min=imin;
        if(isec>0 && isec<61)
            sec=isec;
    }

    record_time(const tm *p)
    {
        year=p->tm_year + 1900;
        month = p->tm_mon + 1;
        day=p->tm_mday;
        hour=p->tm_hour;
        min=p->tm_min;
        sec=p->tm_sec;
    }

    void settimenow()
    {
        time_t timep;
        time(&timep);
        struct tm *nowTime =localtime(&timep);
        nowTime->tm_year += 1900;
        nowTime->tm_mon += 1;
        year=nowTime->tm_year;
        month =nowTime->tm_mon;
        day=nowTime->tm_mday;
        hour=nowTime->tm_hour;
        min=nowTime->tm_min;
        sec=nowTime->tm_sec;
    }

    bool operator <(const record_time &m)
    {
        if(year<m.year)
            return true;
        else if(month<m.month)
            return true;
        else if(day<m.day)
            return true;
        else if(hour<m.hour)
            return true;
        else if(min<m.min)
            return true;
        else if(sec<m.sec)
            return true;
        else
            return false;
    }

    void set(int iyear,int imonth, int iday, int ihour,int imin, int isec)
    {
        if(iyear>2000 && iyear<3000)
            year=iyear;
        if(imonth>0 && imonth<13)
            month=imonth;
        if(iday>0 && iday<32)
            day=iday;
        if(ihour>0 && ihour<25)
            hour=ihour;
        if(imin>0 && imin<61)
            min=imin;
        if(isec>0 && isec<61)
            sec=isec;
    }
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
};


#endif // DATA_H
