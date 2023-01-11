
/* Including header files */

#include <stdio.h>

/* Conditional compilation or customize according to architecture */

// For GCC, predefined macros: http://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
// and: https://github.com/cpredef/predef/blob/master/Architectures.md
#ifdef __x86_64__
	// definitions specific to 64 bit Windows
	#define NAME "x86_64 architecture"
#elif __i386__
	// definitions specific to 32 bit Windows
	#define NAME "32 bit Windows"
#elif __arm__
	#define NAME "ARM architecture"
#elif __ppc64__
	#define NAME "PowerPC architecture"
#else
	#define NAME "unknown architecture"
#endif

/* Define constants */
#define PI 		3.141592653589793
#define TWOPI 	6.283185307179586

/* Can do much more complex things as well, e.g. functions */
#define TORADIANS(x)	((x) * 0.017453292519943295)

int main( int argc, char * argv[] )
{
    printf("Hello World!\n");
	printf("Architecture: %s\n",NAME);
    return 0;
}
