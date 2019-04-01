#include "basewindow.h"
#include "ui_basewindow.h"

#include <QTimer>
#include <QWindow>
#include <QScreen>
#include <QPainter>

#include "FramelessHelper.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
    , ui(new Ui::BaseWindow())
{
    ui->setupUi(this);

    setWindowTitle("Qt Widgets Inside");

    auto helper = new FramelessHelper(this);
    helper->setDraggableMargins(3, 3, 3, 3);
    helper->setMaximizedMargins(3, 3, 3, 3);
    helper->setTitleBarHeight(32);

    helper->addExcludeItem(ui->minimizeButton);
    helper->addExcludeItem(ui->maximizeButton);
    helper->addExcludeItem(ui->closeButton);

    connect(ui->minimizeButton, &QPushButton::clicked, this, &BaseWindow::showMinimized);
    connect(ui->maximizeButton, &QPushButton::clicked, this, &BaseWindow::maximizeButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &BaseWindow::close);
    ui->maximizeButton->setIcon(QIcon(QStringLiteral(":/res/maximize-button1.png")));

    QTimer::singleShot(100, this, &BaseWindow::syncPosition);
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QImage backgroundImage(QStringLiteral(":/res/background.png"));
    painter.drawImage(contentsRect(), backgroundImage);
}

bool BaseWindow::event(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange) {
        if (windowState() & Qt::WindowMaximized) {
            ui->maximizeButton->setIcon(QIcon(QStringLiteral(":/res/maximize-button2.png")));
            ui->maximizeButton->setToolTip(tr("Restore"));
        } else {
            ui->maximizeButton->setIcon(QIcon(QStringLiteral(":/res/maximize-button1.png")));
            ui->maximizeButton->setToolTip(tr("Maximize"));
        }
    }

    return QWidget::event(event);
}

void BaseWindow::maximizeButtonClicked()
{
    if (windowState() & Qt::WindowMaximized) {
        showNormal();
    } else {
        showMaximized();
    }
}

void BaseWindow::syncPosition()
{
    QWindow *window = windowHandle();
    QScreen *screen = window->screen();

    window->setX(screen->availableGeometry().width() / 2 + 10);
}
