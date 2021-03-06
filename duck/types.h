#ifndef _DUCK_TYPES_H
#define _DUCK_TYPES_H

#include "lr_parser.h"

/* constants */
#define VAL_NIL             0
#define VAL_PRIMITIVE       1
#define VAL_STRING          2
#define VAL_REFERENCE       3
#define VAL_FUNCTION        4
#define VAL_FLOATING_POINT  5
#define VAL_DICTIONARY      6

/* floating-point precision */
#define  DOUBLE_EPSILON     (1.0E-12)

/* types */

struct CONTEXT;
struct PAIR;

typedef struct FUNCTION
{
    struct PAIR* parameters;
    SYNTAX_TREE* body;
    unsigned int built_in;
    int (*functor)(int);
	struct CONTEXT* closure;
    int ref_count;
    const char* fn_name;
} FUNCTION;

struct HASH_TABLE;
typedef struct VALUE
{
    int         type;
    union 
    {
        int             primitive;
        double          floatp;
        const char*     string;
        FUNCTION*       function;
        struct CONTEXT* reference;
        struct HASH_TABLE* 
                        dictionary;
    } data;
  int const_string;
} VALUE;

typedef struct PAIR
{
    const char*  identifier;
    VALUE        value;
    struct PAIR* next;
} PAIR;

typedef struct CONTEXT
{
    PAIR*       list;
    int         ref_count;
    struct CONTEXT* parent;
} CONTEXT;

typedef struct CALLSTACK
{
    const char* fn_name;
    FUNCTION* function;
    struct CALLSTACK* next;
} CALLSTACK;

/* casts */

double TypeFloat(VALUE value);
int    TypeInt(VALUE value);
int    IsDynamic(VALUE type);
VALUE  CopyString(VALUE string);

#endif // _DUCK_TYPES_H

