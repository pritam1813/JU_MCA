#include <stdio.h>

struct Time
{
    int hr, min, sec;
};

struct Time addTime(struct Time T1, struct Time T2)
{
    int sec = T1.sec + T2.sec;
    int min = T1.min + T2.min;
    int hr = T1.hr + T2.hr;

    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }

    if (min >= 60)
    {
        hr += min / 60;
        min %= 60;
    }

    struct Time addT;
    addT.hr = hr;
    addT.min = min;
    addT.sec = sec;

    return addT;
}

int main()
{
    struct Time t1, t2;
    printf("Enter Time 1 (in format hr:min:sec): ");
    scanf("%d:%d:%d", &t1.hr, &t1.min, &t1.sec);

    printf("Enter Time 2 (in format hr:min:sec): ");
    scanf("%d:%d:%d", &t2.hr, &t2.min, &t2.sec);

    struct Time result = addTime(t1, t2);
    printf("Added Time: %d:%d:%d\n", result.hr, result.min, result.sec);

    return 0;
}
