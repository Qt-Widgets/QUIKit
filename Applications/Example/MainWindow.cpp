#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QDir>

#include <QUIKit/BaseWindow.h>

#define RELEASE_CLASS(pointer) \
    if(pointer) {\
        delete pointer;\
        pointer = Q_NULLPTR;\
    }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pWidget = Q_NULLPTR;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    RELEASE_CLASS(m_pWidget);

    m_pWidget = new BaseWindow();
    m_pWidget->show();
}
