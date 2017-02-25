#include "RootCalculator.h"

#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

RootCalculator::RootCalculator(QWidget *parent)
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
		ui.infoLabel->setText(Calculate(ui.billInput->text()));
	}); 
}

// Calculates roots of a quadratic equation.
QString RootCalculator::Calculate(QString inputString) {
	// Create a regex pattern for us to play with.
	QRegExp regexPattern("[-+]*[0-9.]*x\\^2[-+][0-9.]*x[-+][0-9.]*");

	// Match the input to the regex.
	if (!regexPattern.exactMatch(inputString))
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
	for (QChar ch : inputString)
		// If the operators are found they are inserted into the list. Dynamically.
		if (ch == '+' || ch == '-')
			inputStringOperators.push_back(QString(ch));

	for (QStringList::iterator it = inputStringPieces.begin(); it != inputStringPieces.end(); ++it)
		// Check if the item is empty and replace it with a 1.
		if (QString(*it).isEmpty())
			*it = "1";

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

	// Check if the x value is zero, and make it absolute. Because yolo.
	if (abs(x[1]) == 0)
		x[1] = abs(x[1]);
	else if (abs(x[0]) == 0)
		x[0] = abs(x[0]);

	// Check if the roots are numbers.
	if ((b*b - (4 * a*c)) < 0)
		return "No Roots";

	// Find the discrinmant.
	if ( ( b*b - (4 * a*c) ) == 0)
		return "x = " + QString::number(x[0], 'g', 15);

	return "x<span style=\"font-size:7px;\">1</span> = <b>" + QString::number(x[1], 'g', 15) + 
		"</b><br>x<span style=\"font-size:7px;\">2</span> = <b>" + QString::number(x[0], 'g', 15) + "</b>";
}