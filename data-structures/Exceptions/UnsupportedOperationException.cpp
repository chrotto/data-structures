#include "UnsupportedOperationException.h"

DS::UnsupportedOperationException::UnsupportedOperationException(): std::exception("Empty collection can't be reduced.")
{
}
