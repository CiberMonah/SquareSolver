#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED

#include <stdlib.h>

#ifdef NDEBUG
#define Assert(condition) ((void)0)
#else
#define Assert(condition) ({                                                                                            \
    if (!condition) {                                                                                                   \
        printf("Assertion failed: in file: %s, in function: %s, in line: %d", __FILE__, __FUNCTION__, __LINE__);        \
        abort();                                                                                                        \
    }                                                                                                                   \
})
#endif

#endif // ASSERT_H_INCLUDED
