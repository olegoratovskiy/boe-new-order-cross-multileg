#ifndef FIELD
#error You need to define FIELD macro
#else
FIELD(cross_id)
FIELD(cross_type)
FIELD(side)
FIELD(price)
FIELD(order_qty)
FIELD(number_of_bitfields)
FIELD(bitfield)
FIELD(group_count)
#undef FIELD
#endif
