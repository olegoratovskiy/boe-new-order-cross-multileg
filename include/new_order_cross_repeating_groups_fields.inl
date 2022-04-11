#ifndef FIELD
#error You need to define FIELD macro
#else
FIELD(side)
FIELD(volume)
FIELD(cl_ord_id)
FIELD(capacity)
FIELD(clearing_firm)
FIELD(account_type)
FIELD(algorithmic_indicator)
#undef FIELD
#endif
