#ifndef NOFOCUSRECTSTYLE_H
#define NOFOCUSRECTSTYLE_H

#include <QUIKit/quikit_global.h>
#include <QProxyStyle>

class NoFocusRectStyle : public QProxyStyle {
public:
    NoFocusRectStyle(QStyle *baseStyle) : QProxyStyle(baseStyle) {}
    void drawPrimitive(PrimitiveElement element,
                       const QStyleOption *option,
                       QPainter *painter,
                       const QWidget *widget = Q_NULLPTR) const {
        if (element == QStyle::PE_FrameFocusRect) {
            return;
        }
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

#endif // NOFOCUSRECTSTYLE_H
