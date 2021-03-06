#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class CSSRule;

class CSSStyleDeclaration : public Object {
public:

    HTML5_PROPERTY(CSSStyleDeclaration, std::string, cssFloat);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, cssText);
    HTML5_PROPERTY(CSSStyleDeclaration, unsigned long, length);
    HTML5_PROPERTY_OBJECT(CSSStyleDeclaration, CSSRule, parentRule);

    HTML5_PROPERTY(CSSStyleDeclaration, std::string, alignContent);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, alignItems);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, alignSelf);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, all);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationDelay);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationDirection);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationDuration);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationFillMode);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationIterationCount);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationName);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationPlayState);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, animationTimingFunction);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backfaceVisibility);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, background);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundAttachment);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundBlendMode);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundClip);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundImage);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundOrigin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundPosition);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundPositionX);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundPositionY);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundRepeat);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundRepeatX);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundRepeatY);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, backgroundSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, blockSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, border);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottomColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottomLeftRadius);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottomRightRadius);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottomStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderBottomWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderCollapse);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImage);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImageOutset);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImageRepeat);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImageSlice);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImageSource);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderImageWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderLeft);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderLeftColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderLeftStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderLeftWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderRadius);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderRight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderRightColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderRightStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderRightWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderSpacing);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTop);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTopColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTopLeftRadius);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTopRightRadius);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTopStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderTopWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, borderWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, bottom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, boxShadow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, boxSizing);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, breakAfter);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, breakBefore);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, breakInside);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, captionSide);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, caretColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, clear);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, clip);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, clipPath);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, color);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnCount);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnFill);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnGap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnRule);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnRuleColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnRuleStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnRuleWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnSpan);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columnWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, columns);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, content);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, counterIncrement);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, counterReset);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, cursor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, deg);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, direction);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, display);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, dpi);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, dppx);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, emptyCells);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flex);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexBasis);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexDirection);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexFlow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexGrow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexShrink);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, flexWrap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, float_);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, font);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontFamily);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontFeatureSettings);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontKerning);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontLanguageOverride);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontOpticalSizing);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontSizeAdjust);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontStretch);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontSynthesis);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariant);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariantCaps);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariantEastAsian);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariantLigatures);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariantNumeric);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontVariationSettings);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fontWeight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, fr);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, grad);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, grid);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridArea);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridAutoColumns);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridAutoFlow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridAutoRows);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridColumn);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridColumnEnd);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridColumnGap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridColumnStart);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridGap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridRow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridRowEnd);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridRowGap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridRowStart);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridTemplate);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridTemplateAreas);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridTemplateColumns);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, gridTemplateRows);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, hangingPunctuation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, height);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, hyphens);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, imageOrientation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, imageRendering);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, inherit);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, initial);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, inlineSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, isolation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, justifyContent);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, justifyItems);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, justifySelf);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, left);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, letterSpacing);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, lightingColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, lineBreak);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, lineHeight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, listStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, listStyleImage);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, listStylePosition);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, listStyleType);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, margin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, marginBottom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, marginLeft);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, marginRight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, marginTop);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, marker);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, markerEnd);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, markerMid);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, markerStart);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, mask);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maskComposite);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maskMode);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maxBlockSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maxHeight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maxInlineSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maxWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, maxZoom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, minBlockSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, minHeight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, minInlineSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, minWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, minZoom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, mixBlendMode);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, objectFit);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, objectPosition);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, offset);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, offsetDistance);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, offsetPath);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, offsetRotate);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, opacity);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, order);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, orientation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, orphans);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, outline);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, outlineColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, outlineOffset);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, outlineStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, outlineWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overflow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overflowAnchor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overflowWrap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overflowX);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overflowY);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overscrollBehavior);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overscrollBehaviorX);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, overscrollBehaviorY);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, padding);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, paddingBottom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, paddingLeft);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, paddingRight);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, paddingTop);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, page);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, pageBreakAfter);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, pageBreakBefore);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, pageBreakInside);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, paintOrder);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, perspective);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, perspectiveOrigin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, placeContent);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, placeItems);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, placeSelf);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, pointerEvents);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, position);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, quotes);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, r);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, resize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, right);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, rowGap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, rx);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, ry);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, scrollBehavior);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, shapeImageThreshold);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, shapeMargin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, shapeOutside);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, shapeRendering);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, size);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, speak);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, src);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, stopColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, stopOpacity);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, stroke);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeDasharray);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeDashoffset);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeLinecap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeLinejoin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeMiterlimit);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeOpacity);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, strokeWidth);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, tabSize);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, tableLayout);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textAlign);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textAlignLast);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textAnchor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textCombineUpright);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textDecoration);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textDecorationColor);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textDecorationLine);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textDecorationSkipInk);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textDecorationStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textIndent);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textOrientation);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textOverflow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textRendering);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textShadow);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textSizeAdjust);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textTransform);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, textUnderlinePosition);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, top);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, touchAction);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transform);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transformBox);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transformOrigin);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transformStyle);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transition);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transitionDelay);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transitionDuration);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transitionProperty);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, transitionTimingFunction);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, unicodeBidi);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, unicodeRange);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, userSelect);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, userZoom);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, vectorEffect);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, verticalAlign);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, visibility);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, whiteSpace);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, widows);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, width);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, willChange);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, wordBreak);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, wordSpacing);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, wordWrap);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, writingMode);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, x);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, y);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, zIndex);
    HTML5_PROPERTY(CSSStyleDeclaration, std::string, zoom);

    CSSStyleDeclaration(emscripten::val v);
    virtual ~CSSStyleDeclaration();
    static CSSStyleDeclaration *create(emscripten::val v);
    std::string getPropertyPriority(std::string property);
    std::string getPropertyValue(std::string property);
    std::string item(unsigned long index);
    std::string removeProperty(std::string property);
    void setProperty(std::string property, std::string value, std::string priority = "");
    void setPropertyPriority(std::string property, std::string priority);
    void setPropertyValue(std::string property, std::string value);
};

NAMESPACE_HTML5_END;
