#include "cellarray.h"

CellArray * CellArray::instance()
{
    static CellArray inst;
    return &inst;
}

//caio teste