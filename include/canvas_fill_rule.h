#pragma once

#include <assert.h>

enum class CanvasFillRule {
    NONZERO,
    EVENODD,
};

inline std::string toCanvasFillRuleString(CanvasFillRule rule)
{
    switch (rule) {
    case CanvasFillRule::NONZERO:
        return "nonzero";
        break;
    case CanvasFillRule::EVENODD:
        return "evenodd";
        break;
    }
    return "";
}

inline CanvasFillRule toCanvasFillRule(std::string rule)
{
    if (rule == "nonzero") {
        return CanvasFillRule::NONZERO;
    } else if (rule == "evenodd") {
        return CanvasFillRule::EVENODD;
    }
    assert(false && "cannot convert to CanvasFillRule");
    return CanvasFillRule::NONZERO;
}
