#include "TipCalculator.h"

#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

TipCalculator::TipCalculator(QWidget *parent)
	: QMainWindow(parent)
{
	QIcon icon(":/TipCalculator/Resources/TipCalculator.png");
	setWindowIcon(icon);

	// Setup ui.
	ui.setupUi(this);

	// Make the window not resizable.
	setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	// Bind the button click to the function.
	connect(ui.calculateButton, &QPushButton::clicked, [this] {
		// Set the info label text to the calculated text.
		ui.infoLabel->setText(Calculate().c_str());
	}); 
}

std::string TipCalculator::Calculate() {
	// Initalize string variables, and get the LineEdit value;
	QString billInput = ui.billInput->text();
	QString percentageInput = ui.percentInput->text();

	// Initalize double variables, and parse the string counterpart to a double.
	double billInputDouble = billInput.toDouble();
	double percentageInputDouble = percentageInput.toDouble(); 
	 
	// Check if it's zero or a negative number.
	if (percentageInputDouble <= 0 || billInputDouble <= 0)
		return "Error!";

	// Calculate the total tip and the total bill.
	double totalTip = billInputDouble * (percentageInputDouble / 100);
	double totalBill = billInputDouble + totalTip;

	// Initalize a stringstream variable.
	std::stringstream finalString;

	// Input all the numbers and text together.
	finalString << "Your total tip: <b>$" << totalTip << "</b><br>"
		<< "Your total bill with the tip: <b>$" << totalBill << "</b>";

	// Return the final string.
	return finalString.str();
}