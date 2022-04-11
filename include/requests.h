#pragma once

#include "fields.h"

#include <algorithm>
#include <array>
#include <vector>

/*
 * New Order
 *  Price(1,4)
 *  OrdType(1,16)
 *  TimeInForce(1,32)
 *  MaxFloor(1,128)
 *  Symbol(2,1)
 *  Capacity(2,64)
 *  Account(3,1)
 */

constexpr size_t new_order_bitfield_num()
{
    return std::max({0
#define FIELD(_, n, __) , n
#include "new_order_opt_fields.inl"
    });
}

constexpr size_t new_order_opt_fields_size()
{
    return 0
#define FIELD(name, _, __) +name##_field_size
#include "new_order_opt_fields.inl"
            ;
}

constexpr size_t new_order_cross_obligatory_count()
{
    return 0
#define FIELD(_, type, size) +size *(1 - type)
#include "new_order_cross_fields_for_size.inl"
            ;
}

constexpr size_t new_order_cross_repeating_group_count()
{
    return 0
#define FIELD(_, type, size) +size * type
#include "new_order_cross_fields_for_size.inl"
            ;
}

constexpr size_t new_order_cross_multileg_obligatory_count()
{
    return 0
#define FIELD(_, type, size) +size *(1 - type)
#include "new_order_cross_multileg_fields_for_size.inl"
            ;
}

constexpr size_t new_order_cross_multileg_repeating_group_count()
{
    return 0
#define FIELD(_, type, size) +size * type
#include "new_order_cross_multileg_fields_for_size.inl"
            ;
}

enum class RequestType
{
    New,
    NewCross,
    NewCrossMultileg
};

constexpr size_t calculate_size(const RequestType type)
{
    switch (type) {
    case RequestType::New:
        return 36 + new_order_bitfield_num() + new_order_opt_fields_size();
    case RequestType::NewCross:
        return 0;
    case RequestType::NewCrossMultileg:
        return 0;
    }
}

enum class Side
{
    Buy,
    Sell
};

enum class OrdType
{
    Market,
    Limit,
    Pegged
};

enum class TimeInForce
{
    Day,
    IOC,
    GTD
};

enum class Capacity
{
    Agency,
    Principal,
    RisklessPrincipal
};

enum class AccountType
{
    Client,
    House
};

enum class Position
{
    Open,
    Close,
    None
};

struct Order
{
    Side side;
    double volume;
    std::string cl_ord_id;
    Capacity capacity;
    std::string clearing_firm;
    AccountType account_type;
    bool algorithmic_indicator;
};

struct ComplexOrder
{
    Order order;
    std::vector<Position> legs;
};

std::array<unsigned char, calculate_size(RequestType::New)> create_new_order_request(
        unsigned seq_no,
        const std::string & cl_ord_id,
        Side side,
        double volume,
        double price,
        OrdType ord_type,
        TimeInForce time_in_force,
        double max_floor,
        const std::string & symbol,
        Capacity capacity,
        const std::string & account);

std::vector<unsigned char> create_new_order_cross_request(
        unsigned seq_no,
        const std::string & cross_id,
        double price,
        const std::string & symbol,
        const Order & agency_order,
        const std::vector<Order> & contra_orders);

std::vector<unsigned char> create_new_order_cross_multileg_request(
        unsigned seq_no,
        const std::string & cross_id,
        double price,
        const std::string & symbol,
        const ComplexOrder & agency_order,
        const std::vector<ComplexOrder> & contra_orders);
