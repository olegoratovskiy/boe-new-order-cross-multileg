#ifndef FIELD
#error You need to define FIELD macro
#else

FIELD(start_of_message, 0, 4)
FIELD(message_length, 0, 2)
FIELD(message_type, 0, 1)
FIELD(message_unit, 0, 1)
FIELD(seq_no, 0, 4)
FIELD(cross_id, 0, 20)
FIELD(cross_type, 0, 1)
FIELD(cross_prior, 0, 1)
FIELD(price, 0, 8)
FIELD(order_qty, 0, 4)
FIELD(number_of_bitfields, 0, 1)
FIELD(bitfield1, 0, 1)
FIELD(bitfield2, 0, 1)
FIELD(bitfield3, 0, 1)

FIELD(side, 1, 1)
FIELD(alloc_qty, 1, 4)
FIELD(clord, 1, 20)
FIELD(capacity, 1, 1)
FIELD(clearing_firm, 1, 4)
FIELD(account_type, 1, 1)
FIELD(algorithm_indicator, 1, 1)
FIELD(leg_pos, 1, 12)

#undef FIELD
#endif
