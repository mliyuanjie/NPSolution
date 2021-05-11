#include <QtWidgets/qapplication.h>
#include "mainWindow.h"


int main(int argc, char* argv[]) {
		QApplication app(argc, argv);
		QMainWindow w;
		Ui::MainWindow ui;
		ui.setupUi(&w);
		w.show();
		return app.exec();
}