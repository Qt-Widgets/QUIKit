#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QUIKit/quikit_global.h>

namespace Ui {
class BaseWindow;
}

class QUIKITSHARED_EXPORT BaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = Q_NULLPTR);
    virtual ~BaseWindow();

protected:
    void paintEvent(QPaintEvent *event) final;
    bool event(QEvent *event) final;
protected:
    void maximizeButtonClicked();
private:
    Ui::BaseWindow *ui;

private:
    void syncPosition();
};

#endif // BASEWINDOW_H
