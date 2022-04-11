#if !defined(FIELD) || !defined(VAR_FIELD)
#error You need to define FIELD and VAR_FIELD macro
#else

VAR_FIELD(account, 16)
FIELD(capacity, char, char)
VAR_FIELD(cl_ord_id, 20)
FIELD(max_floor, binary4, unsigned)
FIELD(order_qty, binary4, unsigned)
FIELD(ord_type, char, char)
FIELD(price, price, double)
FIELD(side, char, char)
VAR_FIELD(symbol, 8)
FIELD(time_in_force, char, char)

VAR_FIELD(cross_id, 20)
VAR_FIELD(cross_type, 1)
FIELD(number_of_bitfields, char, unsigned);
FIELD(bitfield, char, unsigned);
FIELD(group_count, binary2, unsigned)

FIELD(volume, binary4, unsigned)
VAR_FIELD(clearing_firm, 4)
VAR_FIELD(account_type, 1)
VAR_FIELD(algorithmic_indicator, 1)

VAR_FIELD(legs, 12)

#undef FIELD
#undef VAR_FIELD

#endif
