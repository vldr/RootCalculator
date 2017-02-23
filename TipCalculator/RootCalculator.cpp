#include "RootCalculator.h"

#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

TipCalculator::TipCalculator(QWidget *parent)
	: QMainWindow(parent)
{
	// Setup ui.
	ui.setupUi(this);

	// Initalize QIcon variable
	QIcon icon(":/TipCalculator/Resources/TipCalculator2.png");

	// Set the icon of the window.
	setWindowIcon(icon);

	// Set custom title.
	setWindowTitle("Root Calculator (" + QString(__DATE__) + ")");

	// Make the window not resizable.
	setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowCloseButtonHint);

	// Bind the button click to the function.
	connect(ui.calculateButton, &QPushButton::clicked, [this] {
		// Set the info label text to the calculated text.
		ui.infoLabel->setText(Calculate());
	}); 
}

QString TipCalculator::Calculate() {
	QString inputString = ui.billInput->text();

	if (!inputString.contains(QRegExp("[-+]*[0-9.]*x\\^2[-+][0-9.]*x[-+][0-9.]")))
		return "Error!";

	// Remove the x, as they are implied.
	inputString = inputString.replace("x", "");

	// Remove ^2 as it is implied.
	inputString = inputString.replace("^2", "");

	// Split by + or - symbols into an array of strings.
	QStringList inputStringPieces = inputString.split(QRegExp("[-]|[+]"));

	// Create a list where all the operators will be stored.
	QStringList inputStringOperators;

	// For loop, loop through all the characters to find the operators.
	for (QChar ch : inputString) {
		QString s = ch;

		// If the operators are found they are inserted into the list. Dynamically.
		if (ch == '+' || ch == '-')
			inputStringOperators.push_back(s);
	}

	int i = 0;
	foreach(const QString &str, inputStringPieces) {
		if (str.isEmpty())
			inputStringPieces[i] = "1";

		i++;
	}

	// Initalise a,b,c as doubles for the equation.
	double a;
	double b;
	double c;

	// If they are two operators.
	if (inputStringOperators.size() == 2) {
		// Add the operator infront of the number as string then parse it as a double.
		a = inputStringPieces[0].toDouble();
		b = (inputStringOperators[0] + inputStringPieces[1]).toDouble();
		c = (inputStringOperators[1] + inputStringPieces[2]).toDouble();
	}
	else {
		// Add the operator infront of the number as string then parse it as a double.
		a = (inputStringOperators[0] + inputStringPieces[1]).toDouble();
		b = (inputStringOperators[1]+ inputStringPieces[2]).toDouble();
		c = (inputStringOperators[2] + inputStringPieces[3]).toDouble();
	}

	// Create a double array for the possible two roots.
	double x[] = { 0,0 };
	x[0] = ((-1 * b) + sqrt(b*b - (4 * a*c))) / (2 * a);
	x[1] = ((-1 * b) - sqrt(b*b - (4 * a*c))) / (2 * a);

	// Check if the roots are numbers.
	if (isnan(x[0]) && isnan(x[1]))
		return "No Roots";

	// Check if the x value is zero, and make it absolute.
	if (abs(x[1]) == 0)
		x[1] = abs(x[0]);
	 
	// Find the discrinmant.
	if (sqrt(b*b - (4 * a*c)) == 0)
		return "x = " + QString::number(x[0], 'g', 15);

	// Check if it's a number.
	if (isnan(x[0]))
		return "x = " + QString::number(x[1], 'g', 15); 
	 
	// Check if it's a number.
	if (isnan(x[1]))
		return "x = " + QString::number(x[0], 'g', 15);

	return "x1 = " + QString::number(x[1], 'g', 15) + "<br>x2 = " + QString::number(x[0], 'g', 15);
}