#include "RootCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RootCalculator w;
	w.show();
	return a.exec();
}
