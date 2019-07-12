#pragma once

#include "html5.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;


class LinkStyle {
public:

    HTML5_PURE_VIRTUAL_READONLY_PROPERTY_OBJECT(LinkStyle, StyleSheet, sheet);

    virtual ~LinkStyle();
};

NAMESPACE_HTML5_END;
