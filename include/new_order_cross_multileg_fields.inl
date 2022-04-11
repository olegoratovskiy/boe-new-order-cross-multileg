#ifndef FIELD
#error You need to define FIELD macro
#else
FIELD(cross_id)
FIELD(cross_type)
FIELD(side)
FIELD(price)
FIELD(order_qty)
FIELD(number_of_bitfields)

C_FIELD(bitfield, bitfield1)
C_FIELD(bitfield, bitfield2)
C_FIELD(bitfield, bitfield3)

FIELD(group_count)
#undef FIELD
#endif
