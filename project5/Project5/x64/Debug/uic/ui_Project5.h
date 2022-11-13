/********************************************************************************
** Form generated from reading UI file 'Project5.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT5_H
#define UI_PROJECT5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Project5Class
{
public:
    QAction *action_open;
    QAction *action_exit;
    QAction *action_min_convert;
    QAction *action_min_dist;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_Q;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Project5Class)
    {
        if (Project5Class->objectName().isEmpty())
            Project5Class->setObjectName(QStringLiteral("Project5Class"));
        Project5Class->resize(1045, 790);
        Project5Class->setMaximumSize(QSize(1045, 790));
        Project5Class->setMouseTracking(true);
        Project5Class->setAutoFillBackground(true);
        action_open = new QAction(Project5Class);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_open->setCheckable(true);
        action_exit = new QAction(Project5Class);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_exit->setCheckable(true);
        action_min_convert = new QAction(Project5Class);
        action_min_convert->setObjectName(QStringLiteral("action_min_convert"));
        action_min_convert->setCheckable(true);
        action_min_dist = new QAction(Project5Class);
        action_min_dist->setObjectName(QStringLiteral("action_min_dist"));
        action_min_dist->setCheckable(true);
        centralWidget = new QWidget(Project5Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/Project5/\345\234\260\345\233\276.bmp);"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        Project5Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Project5Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1045, 30));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_Q = new QMenu(menuBar);
        menu_Q->setObjectName(QStringLiteral("menu_Q"));
        Project5Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Project5Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Project5Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Project5Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Project5Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_Q->menuAction());
        menu->addAction(action_open);
        menu->addAction(action_exit);
        menu_Q->addAction(action_min_convert);
        menu_Q->addAction(action_min_dist);

        retranslateUi(Project5Class);
        QObject::connect(action_open, SIGNAL(triggered(bool)), Project5Class, SLOT(load_map()));
        QObject::connect(action_exit, SIGNAL(triggered(bool)), Project5Class, SLOT(close_window()));
        QObject::connect(action_min_convert, SIGNAL(triggered(bool)), Project5Class, SLOT(min_convert()));
        QObject::connect(action_min_dist, SIGNAL(triggered(bool)), Project5Class, SLOT(min_dist()));

        QMetaObject::connectSlotsByName(Project5Class);
    } // setupUi

    void retranslateUi(QMainWindow *Project5Class)
    {
        Project5Class->setWindowTitle(QApplication::translate("Project5Class", "\345\205\254\344\272\244\350\275\254\344\271\230", Q_NULLPTR));
        action_open->setText(QApplication::translate("Project5Class", "\350\257\273\345\205\245\345\234\260\345\233\276", Q_NULLPTR));
        action_exit->setText(QApplication::translate("Project5Class", "\351\200\200\345\207\272", Q_NULLPTR));
        action_min_convert->setText(QApplication::translate("Project5Class", "\346\234\200\345\260\221\350\275\254\344\271\230", Q_NULLPTR));
        action_min_dist->setText(QApplication::translate("Project5Class", "\346\234\200\347\237\255\350\267\235\347\246\273", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Project5Class", "\346\226\207\344\273\266(F)", Q_NULLPTR));
        menu_Q->setTitle(QApplication::translate("Project5Class", "\346\237\245\350\257\242(Q)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Project5Class: public Ui_Project5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT5_H
