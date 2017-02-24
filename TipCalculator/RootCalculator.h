#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RootCalculator.h"
#include <sstream>
#include <Windows.h>

#include <iomanip>

class RootCalculator : public QMainWindow
{
	Q_OBJECT

public:
	RootCalculator(QWidget *parent = Q_NULLPTR);
	QString Calculate(QString inputString);
private:
	Ui::TipCalculatorClass ui;
};
