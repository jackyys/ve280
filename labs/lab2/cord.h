#ifndef CORD_H
#define CORD_H

#include <string>

typedef struct cord *cord_t;
struct cord {
    size_t len;
    cord *left;
    cord *right;
    std::string data;
};

bool is_cord(cord *);

size_t cord_length(cord_t R);

cord_t cord_new(const std::string &s);

cord_t cord_join(cord_t R, cord_t S);

std::string cord_tostring(cord_t R);

char cord_charat(cord_t R, size_t i)
/*@requires 0 <= i && i < cord_length(R); @*/ ;

cord_t cord_sub(cord_t R, size_t lo, size_t hi)
/*@requires 0 <= lo && lo <= hi && hi <= cord_length(R); @*/ ;

#endif
