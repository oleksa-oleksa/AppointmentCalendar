#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"


void swapAppointment(TAppointment *a, TAppointment *b)
{
    TAppointment swp;

    memcpy(&swp, a, sizeof(TAppointment));
    memcpy(a, b, sizeof(TAppointment));
    memcpy(b, &swp, sizeof(TAppointment));
}


void qsort(TAppointment *appointments, int lowerBound, int upperBound, int (*ordering) (TAppointment *a, TAppointment *b),
           void (*swapAppointment) (TAppointment *a, TAppointment *b))
{

    int idx;

    if (lowerBound >= upperBound)
        return;
    else
    {
        idx = partition(appointments, lowerBound, upperBound);
        qsort(appointments, lowerBound, idx - 1);
        qsort(appointments, idx + 1, upperBound);
    }
}

int partition (TAppointment *appointments, int lowerBound, int upperBound, int (*ordering) (TAppointment *a, TAppointment *b),
               void (*swapAppointment) (TAppointment *a, TAppointment *b))
{
    int i = lowerBound, j = upperBound;
    int temp;
    TAppointment *pivot = appointments + lowerBound;

    while (i <= j)
    {
        while (i <= j && ordering(appointments + i, pivot) < 1)
        {
            i++;
        }
        while (j >= i && ordering(appointments + j, pivot) > -1)
        {
            j--;
        }

        if (i < j)
        {
            swapAppointment(appointments + i, appointments + j);

            i++;
            j--;
        }
    }
    i--;

    swapAppointment(appointments + lowerBound, appointments + i);

    return(i);
}


void quickSortAppointments(TAppointment *appointments, int amount, int (*ordering) (TAppointment *a, TAppointment *b))
{

    qsort(appointments, 0, (amount - 1), ordering, swapAppointment);
}
