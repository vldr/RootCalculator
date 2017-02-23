#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RootCalculator.h"
#include <sstream>
#include <Windows.h>

#include <iomanip>

class TipCalculator : public QMainWindow
{
	Q_OBJECT

public:
	TipCalculator(QWidget *parent = Q_NULLPTR);
	QString Calculate();
private:
	Ui::TipCalculatorClass ui;
};
