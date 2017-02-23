/********************************************************************************
** Form generated from reading UI file 'RootCalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTCALCULATOR_H
#define UI_ROOTCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TipCalculatorClass
{
public:
    QWidget *centralWidget;
    QPushButton *calculateButton;
    QLineEdit *billInput;
    QLabel *label;
    QLabel *infoLabel;

    void setupUi(QMainWindow *TipCalculatorClass)
    {
        if (TipCalculatorClass->objectName().isEmpty())
            TipCalculatorClass->setObjectName(QStringLiteral("TipCalculatorClass"));
        TipCalculatorClass->resize(241, 173);
        TipCalculatorClass->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255,0);"));
        centralWidget = new QWidget(TipCalculatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"QWidget {\n"
"	background-color:rgb(45, 45, 45);\n"
"	border-top:2px solid rgb(234, 1, 255);\n"
"}"));
        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));
        calculateButton->setGeometry(QRect(10, 120, 121, 41));
        calculateButton->setStyleSheet(QLatin1String("QPushButton {\n"
"border:1px solid rgb(27, 27, 27);\n"
"border-bottom:2px solid rgb(27, 27, 27);\n"
"\n"
"background-color:rgb(37, 37, 37);\n"
"color:rgb(173, 173, 173);\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-bottom:0px solid gray;\n"
"}"));
        billInput = new QLineEdit(centralWidget);
        billInput->setObjectName(QStringLiteral("billInput"));
        billInput->setGeometry(QRect(10, 80, 221, 31));
        QFont font;
        font.setPointSize(13);
        billInput->setFont(font);
        billInput->setStyleSheet(QLatin1String("border:1px solid rgb(27, 27, 27);\n"
"border-bottom:2px solid rgb(27, 27, 27);\n"
"\n"
"background-color:rgb(37, 37, 37);\n"
"color:rgb(173, 173, 173);\n"
"border-radius:5px;\n"
"padding:5px;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 251, 16));
        label->setStyleSheet(QLatin1String("color:gray;\n"
"padding-left:2px;\n"
"border:none;"));
        infoLabel = new QLabel(centralWidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(10, 10, 221, 41));
        QFont font1;
        font1.setPointSize(8);
        infoLabel->setFont(font1);
        infoLabel->setStyleSheet(QLatin1String("color:white;\n"
"background-color:rgb(10,10,10,80);\n"
"padding-left:5px;\n"
"border-radius:5px;\n"
"border:none;"));
        TipCalculatorClass->setCentralWidget(centralWidget);

        retranslateUi(TipCalculatorClass);

        QMetaObject::connectSlotsByName(TipCalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TipCalculatorClass)
    {
        TipCalculatorClass->setWindowTitle(QApplication::translate("TipCalculatorClass", "TipCalculator", Q_NULLPTR));
        calculateButton->setText(QApplication::translate("TipCalculatorClass", "Calculate", Q_NULLPTR));
        billInput->setText(QString());
        label->setText(QApplication::translate("TipCalculatorClass", "Quadratic Equation:", Q_NULLPTR));
        infoLabel->setText(QApplication::translate("TipCalculatorClass", "Type a equation, ex: <br><b>x^2+x-2</b>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TipCalculatorClass: public Ui_TipCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTCALCULATOR_H
