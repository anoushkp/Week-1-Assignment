/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Anosh Viraf Pesuna>
 * @date <February 8th, 2021 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

print_statistics(test,SIZE);
sort_array(test,SIZE);

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

int find_median( unsigned char array[], int length )//Function for calculating the median
{
    int med;
    int a,b,c,d,i,j;// declaring all variables

    for( i=0; i<length; i++ ) //Sorting the array in ascending order for calculating median
    {
      for( j=i+1; j<length; j++ )
      {
        if ( array[i]>array[j] )
        {
          d =  array[i];
          array[i] = array[j];
          array[j] = d;
        }
      }
    }

    if ( length % 2 == 0 ) //Case where length is even
    {
      a = (length - 2)/2;
      b = (length/2);
      med = ((array[a] + array[b])/2);
    }

    else // Case where length is odd
    {
      c = (length+1)/2;
      med = array[c];
    }

    printf("The median is: %d\n",med); //Printing the value
}

int find_mean( unsigned char array[], int length )//Function to calculate mean
{
  int total=0;//initialzing the value
  int mean;//declaring variables
  for ( int i=0; i<length; i++ )//First calculating total
  {
    total = total + array[i];
  }
  mean = total/length;//then dividing by length
  printf("The mean is: %d\n",mean);//Printing the value
}

int find_maximum( unsigned char array[], int length )//Function for calculating the maximum value
{
  int max = array[0];//initializing
  for ( int i=0; i<length; i++ )
  {
    if ( array[i] > max )
    {
      max = array[i];
    }
  }
  printf("The maximum number is: %d\n",max);//printing the value
}

int find_minimum( unsigned char array[], int length )//Function for calculating the minimum value
{
  int min = array[0];//initialzing
  for ( int i=0; i<length; i++ )
  {
    if ( array[i] < min )
    {
      min = array[i];
    }
  }
  printf("The minimum number is: %d\n",min);//printing the value
}

void sort_array( unsigned char array[], int length )//Function to sort the array from largest to smallest
{
  int a,j;//declaring variables
  for (int i = 0; i < length; i++)
{
    for (j = i + 1; j < length; j++)
    {
        if (array[i] < array[j])
        {
            a = array[i];
            array[i] = array[j];
            array[j] = a;
        }
    }
}
printf("The new sorted array is as follows: \n");//Printing the new sorted array
print_array(array,length);
}

void print_array( unsigned char array[], int length )//Function to print an array
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", array[i]);
  }
}

void print_statistics( unsigned char array[], int length )//Function combing the calculations and calling them
{
  find_median( array, length );
  find_mean( array, length );
  find_maximum( array, length );
  find_minimum( array, length );
}


/* Add other Implementation File Code Here */
