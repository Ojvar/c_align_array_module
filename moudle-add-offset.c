#include "stdio.h"

/**
 * @brief ArrayItemType structure
 * 
 */
typedef struct
{
    int area;
    int distance;
} ArrayItemType;

/**
 * @brief Align array items
 * 
 * @param array &ArrayItemType[]
 * @param array_size int
 * @param aligner &ArrayItemType
 */
void align_array(ArrayItemType array[],
                 int array_size,
                 ArrayItemType *aligner)
{
    ArrayItemType *curItem = array;

    while (0 < array_size--)
    {
        curItem->distance += aligner->distance;
        curItem->area += aligner->area;

        curItem++;
    }
}

/**
 * @brief Print array
 * 
 * @param array &ArrayItemType[]
 * @param array_size int
 */
void print_array(ArrayItemType array[],
                 int array_size)
{
    ArrayItemType *curItem = array;

    for (int index = 0; index < array_size; index++)
    {
        printf("\nItem #%d { area: %d, distance: %d }",
               index,
               curItem->area,
               curItem->distance);

        curItem++;
    }
}

/**
 * @brief Prepare array
 *  Fill array by mock data
 * 
 * @param array &ArrayItemType[]
 * @param array_size int
 */
void prepare_array(ArrayItemType array[],
                   int array_size)
{
    ArrayItemType *curItem = array;

    while (0 < array_size--)
    {
        curItem->distance = array_size + 100;
        curItem->area = array_size + 100;

        curItem++;
    }
}

/**
 * @brief Main loop
 * 
 * @return int Program result
 */
int main()
{
    int ARRAY_SIZE = 360;
    ArrayItemType array[ARRAY_SIZE];

    /* Prepare array with mock data */
    prepare_array(array, ARRAY_SIZE);

    /* Align array items */
    ArrayItemType aligner = {
        .area = 5,
        .distance = 200};
    align_array(array, ARRAY_SIZE, &aligner);

    /* Print array */
    print_array(array, ARRAY_SIZE);

    return 0;
}