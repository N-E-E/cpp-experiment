/********************************************************************************
** Form generated from reading UI file 'file_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_WIDGET_H
#define UI_FILE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_file_widgetClass
{
public:
    QLabel *labelStop;
    QLabel *labelLine;
    QPushButton *ButtonStop;
    QPushButton *ButtonLine;
    QTextEdit *textEditStop;
    QTextEdit *textEditLine;
    QPushButton *ButtonConfirm;
    QPushButton *ButtonExit;

    void setupUi(QWidget *file_widgetClass)
    {
        if (file_widgetClass->objectName().isEmpty())
            file_widgetClass->setObjectName(QStringLiteral("file_widgetClass"));
        file_widgetClass->resize(663, 422);
        labelStop = new QLabel(file_widgetClass);
        labelStop->setObjectName(QStringLiteral("labelStop"));
        labelStop->setGeometry(QRect(80, 130, 81, 18));
        labelLine = new QLabel(file_widgetClass);
        labelLine->setObjectName(QStringLiteral("labelLine"));
        labelLine->setGeometry(QRect(80, 210, 81, 18));
        ButtonStop = new QPushButton(file_widgetClass);
        ButtonStop->setObjectName(QStringLiteral("ButtonStop"));
        ButtonStop->setGeometry(QRect(390, 120, 112, 34));
        ButtonLine = new QPushButton(file_widgetClass);
        ButtonLine->setObjectName(QStringLiteral("ButtonLine"));
        ButtonLine->setGeometry(QRect(390, 200, 112, 34));
        textEditStop = new QTextEdit(file_widgetClass);
        textEditStop->setObjectName(QStringLiteral("textEditStop"));
        textEditStop->setGeometry(QRect(170, 120, 201, 31));
        textEditLine = new QTextEdit(file_widgetClass);
        textEditLine->setObjectName(QStringLiteral("textEditLine"));
        textEditLine->setGeometry(QRect(170, 200, 201, 31));
        ButtonConfirm = new QPushButton(file_widgetClass);
        ButtonConfirm->setObjectName(QStringLiteral("ButtonConfirm"));
        ButtonConfirm->setGeometry(QRect(130, 310, 112, 34));
        ButtonExit = new QPushButton(file_widgetClass);
        ButtonExit->setObjectName(QStringLiteral("ButtonExit"));
        ButtonExit->setGeometry(QRect(350, 310, 112, 34));

        retranslateUi(file_widgetClass);
        QObject::connect(ButtonStop, SIGNAL(clicked(bool)), file_widgetClass, SLOT(stop_input()));
        QObject::connect(ButtonLine, SIGNAL(clicked(bool)), file_widgetClass, SLOT(line_input()));
        QObject::connect(ButtonConfirm, SIGNAL(clicked(bool)), file_widgetClass, SLOT(check_file()));
        QObject::connect(ButtonExit, SIGNAL(clicked(bool)), file_widgetClass, SLOT(close()));

        QMetaObject::connectSlotsByName(file_widgetClass);
    } // setupUi

    void retranslateUi(QWidget *file_widgetClass)
    {
        file_widgetClass->setWindowTitle(QApplication::translate("file_widgetClass", "\346\226\207\344\273\266\345\212\240\350\275\275", Q_NULLPTR));
        labelStop->setText(QApplication::translate("file_widgetClass", "\347\253\231\347\202\271\346\226\207\344\273\266", Q_NULLPTR));
        labelLine->setText(QApplication::translate("file_widgetClass", "\347\272\277\350\267\257\346\226\207\344\273\266", Q_NULLPTR));
        ButtonStop->setText(QApplication::translate("file_widgetClass", "\346\265\217\350\247\210", Q_NULLPTR));
        ButtonLine->setText(QApplication::translate("file_widgetClass", "\346\265\217\350\247\210", Q_NULLPTR));
        ButtonConfirm->setText(QApplication::translate("file_widgetClass", "\347\241\256\345\256\232", Q_NULLPTR));
        ButtonExit->setText(QApplication::translate("file_widgetClass", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class file_widgetClass: public Ui_file_widgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_WIDGET_H
