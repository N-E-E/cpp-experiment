/********************************************************************************
** Form generated from reading UI file 'point_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINT_DIALOG_H
#define UI_POINT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_point_dialogClass
{
public:
    QLabel *StopMsg;

    void setupUi(QDialog *point_dialogClass)
    {
        if (point_dialogClass->objectName().isEmpty())
            point_dialogClass->setObjectName(QStringLiteral("point_dialogClass"));
        point_dialogClass->resize(410, 79);
        StopMsg = new QLabel(point_dialogClass);
        StopMsg->setObjectName(QStringLiteral("StopMsg"));
        StopMsg->setGeometry(QRect(40, 20, 331, 41));

        retranslateUi(point_dialogClass);

        QMetaObject::connectSlotsByName(point_dialogClass);
    } // setupUi

    void retranslateUi(QDialog *point_dialogClass)
    {
        point_dialogClass->setWindowTitle(QApplication::translate("point_dialogClass", "point_dialog", Q_NULLPTR));
        StopMsg->setText(QApplication::translate("point_dialogClass", "\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class point_dialogClass: public Ui_point_dialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINT_DIALOG_H
