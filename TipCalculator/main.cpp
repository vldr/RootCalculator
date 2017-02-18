#include "TipCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TipCalculator w;
	w.show();
	return a.exec();
}
