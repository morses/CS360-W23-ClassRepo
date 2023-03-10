#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intersperse(char c, const char * input, char * output)
{
    // Error condition
    if(input == NULL || output == NULL)
    {
        return 1;
    }
    int length = strlen(input);     // will fail if not properly null terminated
    // Nothing to do if it's just the empty string
    if(length == 0)
    {
        return 0;
    }
    // Take care of the first letter, then iterate i over the input and j over the output
    output[0] = input[0];
    int i, j;
    for (i = 1, j = 1; i < length; i++, j += 2)
    {
        output[j]     = c;
        output[j + 1] = input[i];
    }
    // Don't forget to null terminate the output
    output[j] = '\0';
    return 0;
}

int main(int argc, char ** argv)
{
    // allocate memory for output string, larger than any we'll actually have
    char *output = (char *)calloc(1000, sizeof(char));

    intersperse(',', "", output);
    printf("empty string -> %s\n", output);
    intersperse(',', "A", output);
    printf("A -> %s\n", output);
    intersperse(',', "AB", output);
    printf("AB -> %s\n", output);
    intersperse(',', "ABCDEFG", output);
    printf("ABCDEFG -> %s\n", output);
    
    free(output);
    return 0;
}