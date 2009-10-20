
#include <QApplication>
#include "firstrunwizard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FirstRunWizard wizard;

    wizard.show();

    return app.exec();
}