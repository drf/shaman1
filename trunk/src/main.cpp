#include <iostream>
#include <QtGui>
#include "AlpmHandler.h"
#include "alpm_list.h"
#include "MainWindow.h"

int main(int argc, char **argv)
{
	AlpmHandler *aHandler = new AlpmHandler(true);
	alpm_list_t *getpkg;
	
	QApplication app(argc, argv);
	
	uid_t myuid = geteuid();
	
	if(myuid > 0)
	{	
		printf("Ehi ehi stronzo ma dove credi di andare? Solo root può farlo");
		return 1;
	}
	
	MainWindow mainwin(aHandler, &app);
	
	mainwin.show();
	
	//mainwin.populatePackagesView();
	mainwin.populateRepoColumn();
	
	return app.exec();
	
	printf("Il database locale ha %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, NULL, true)));
	printf("In core ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "core", false)));
	printf("In extra ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "extra", false)));
	printf("In sblub ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "sblub", false)));
	printf("In totale sono disponibili %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, NULL, false)));
	
	aHandler->updateDatabase();
	
		printf("Minchiazzzio allora mo aggiorno\n");
		
		getpkg = aHandler->getUpgradeablePackages();
		
		if(getpkg == NULL)
			printf("Nulla di nulla zio\n");
		else
			printf("Ouch\n");
	
		printf("Nulla da fare qui.\n");
	
	
	sleep(1);
	
	//return 0;
}

