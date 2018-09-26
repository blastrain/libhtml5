#pragma once

#include "libhtml5.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;


class LinkStyle {
public:
    virtual ~LinkStyle();
    HTML5_PURE_VIRTUAL_PROPERTY_OBJECT(LinkStyle, StyleSheet, sheet);
};

NAMESPACE_HTML5_END;
