<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS><TS version="1.1" language="it">
<defaultcodec></defaultcodec>
<context>
    <name>AlpmHandler</name>
    <message>
        <location filename="../src/AlpmHandler.cpp" line="1029"/>
        <source>: requires </source>
        <translation>: richiede </translation>
    </message>
    <message>
        <location filename="../src/AlpmHandler.cpp" line="1038"/>
        <source>: conflicts with </source>
        <translation>: è in conflitto con </translation>
    </message>
    <message>
        <location filename="../src/AlpmHandler.cpp" line="1061"/>
        <source>%1 exists in both &apos;%2&apos; and &apos;%3&apos;</source>
        <translation>%1 esiste sia in &apos;%2&apos; che in &apos;%3&apos;</translation>
    </message>
    <message>
        <location filename="../src/AlpmHandler.cpp" line="1068"/>
        <source>: %1 exists in filesystem</source>
        <translation>: %1 esiste nel filesystem</translation>
    </message>
</context>
<context>
    <name>BuildingDialog</name>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="50"/>
        <source>Error</source>
        <translation>Errore</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="56"/>
        <source>Would you like to abort building?.
All Process will be lost.</source>
        <translation>Vuoi davvero annullare la compilazione?
Tutti i progressi andranno perduti.</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="64"/>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;Building Process Aborted by the User. Building Failed.&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;Compilazione annullata dall&apos;utente. Compilazione Fallita.&lt;/b&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="83"/>
        <source>Updating ABS Tree...</source>
        <translation>Aggiornamento dell&apos;albero ABS...</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="86"/>
        <source>&lt;b&gt;Starting ABS Tree Update...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Inizio Aggiornamento dell&apos;albero ABS...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="139"/>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;ABS Tree Was Successfully Updated!&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;Albero ABS Aggiornato con successo!&lt;/b&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="141"/>
        <source>ABS Update</source>
        <translation>Aggiornamento ABS</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="141"/>
        <source>Your ABS Tree was updated!</source>
        <translation>L&apos;albero ABS è stato aggiornato!</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="158"/>
        <source>&lt;b&gt;Building %1 failed!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Compilazione di %1 fallita!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="163"/>
        <source>&lt;b&gt;%1 was built successfully!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;%1 compilato con successo!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="218"/>
        <source>Processing Package %1 of %2...</source>
        <translation>Compilazione pacchetto %1 di %2...</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="219"/>
        <source>Building %1...</source>
        <translation>Compilazione di %1...</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="243"/>
        <source>&lt;b&gt;Building %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Compilazione di %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="268"/>
        <source>&lt;b&gt;Building operation has started.&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Compilazione dei pacchetti Iniziata.&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
</context>
<context>
    <name>BuildingHandler</name>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="100"/>
        <source>You need to have ABS installed to use Shaman&apos;s
building feature. Do you want to install it now?</source>
        <translation>Devi avere installato ABS per utilizzare le capacità
di compilazione di Shaman. Vuoi installarlo ora?</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="337"/>
        <source>Error</source>
        <translation>Errore</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="132"/>
        <source>You can not remove packages when processing
your queue from Source</source>
        <translation>Non puoi rimuovere pacchetti se esegui la coda
da sorgente</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="163"/>
        <source>Some of your packages do not belong to Arch
Linux&apos;s official repository. Shaman is able to
build packages from official sources only.</source>
        <translation>Alcuni dei pacchetti selezionati non appartengono
ai repositori ufficiali di Arch Linux. Shaman è in grado
di compilare pacchetti solo da sorgenti ufficiali.</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="200"/>
        <source>You are about to install &lt;b&gt;%1 package&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>Stai per installare &lt;b&gt;%1 pacchetto&lt;/b&gt; da sorgente. Compilare da sorgente&lt;br&gt;può dare diversi vantaggi, ma è comunque molto lento.&lt;br&gt;Se non ne sei sicuro, probabilmente preferiresti eseguire la tua coda da file&lt;br&gt;binari. Prima di continuare, è consigliabile rivedere la tua configurazione&lt;br&gt;per massimizzare le prestazioni della compilazione.</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="206"/>
        <source>You are about to install &lt;b&gt;%1 packages&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>Stai per installare &lt;b&gt;%1 pacchetti&lt;/b&gt; da sorgente. Compilare da sorgente&lt;br&gt;può dare diversi vantaggi, ma è comunque molto lento.&lt;br&gt;Se non ne sei sicuro, probabilmente preferiresti eseguire la tua coda da file&lt;br&gt;binari. Prima di continuare, è consigliabile rivedere la tua configurazione&lt;br&gt;per massimizzare le prestazioni della compilazione.</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="225"/>
        <source>To be Installed</source>
        <translation>Da Installare</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="232"/>
        <source>To be Upgraded</source>
        <translation>Da Aggiornare</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="378"/>
        <source>Package Building</source>
        <translation>Compilazione Pacchetti</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="311"/>
        <source>Your Packages failed to build!</source>
        <translation>Non è stato possibile compilare i pacchetti!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="315"/>
        <source>Your packages Failed to Build.
Look at the output for more details.</source>
        <translation>Non è stato possibile compilare i pacchetti.
Guarda l&apos;output per maggiori dettagli.</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="353"/>
        <source>Close</source>
        <translation>Chiudi</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="343"/>
        <source>Building Packages Failed!!</source>
        <translation>Compilazione dei Pacchetti Fallita!!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="357"/>
        <source>Shaman - Idle</source>
        <translation>Shaman - In Attesa</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="346"/>
        <source>Some packages failed to build.
Do you want to proceed anyway?</source>
        <translation>Alcuni pacchetti non sono stati compilati.
Vuoi proseguire comunque?</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="373"/>
        <source>Install Built Packages</source>
        <translation>Installa i Pacchetti Compilati</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="374"/>
        <source>Close Without Installing</source>
        <translation>Chiudi Senza Installare</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="375"/>
        <source>Packages Built Successfully!</source>
        <translation>Pacchetti Compilati con Successo!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="379"/>
        <source>Your Packages have been built successfully, and are ready to be installed</source>
        <translation>I Pacchetti sono stati compilati con successo, e sono pronti per essere installati</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="509"/>
        <source>Shaman - Processing</source>
        <translation>Shaman - Operazione in corso</translation>
    </message>
</context>
<context>
    <name>CallBacks</name>
    <message>
        <location filename="../src/callbacks.cpp" line="114"/>
        <source>%1 requires installing %2 from IgnorePkg/IgnoreGroup.
 Install anyway?</source>
        <translation>%1 richiede l&apos;installazione di %2 da IgnorePkg/IgnoreGroup.
Installare comunque?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="117"/>
        <source>%1 is in IgnorePkg/IgnoreGroup.
 Install anyway?</source>
        <translation>%1 è in IgnorePkg/IgnoreGroup.
Installare comunque?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="121"/>
        <source>%1 is designated as a HoldPkg.
 Remove anyway?</source>
        <translation>%1 è contrassegnato come HoldPkg.
Rimuovere comunque?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="124"/>
        <source>Replace %1 with %2/%3?</source>
        <translation>Sostituire %1 con %2/%3?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="128"/>
        <source>%1 conflicts with %2.
Remove %3?</source>
        <translation>%1 è in conflitto con %2.Rimuovere %3?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="132"/>
        <source>%1-%2: local version is newer.
Upgrade anyway?</source>
        <translation>%1-%2: la versione locale è più recente.Aggiornare comunque?</translation>
    </message>
    <message>
        <location filename="../src/callbacks.cpp" line="136"/>
        <source>File %1 is corrupted.
Do you want to delete it?</source>
        <translation>Il File %1 è corrotto.
Vuoi cancellarlo?</translation>
    </message>
</context>
<context>
    <name>ConfigDialog</name>
    <message>
        <location filename="../ui/configDialog.ui" line="13"/>
        <source>Shaman - Configuration</source>
        <translation>Shaman - Configurazione</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="88"/>
        <source>Favourite Actions</source>
        <translation>Azioni preferite</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="97"/>
        <source>When Upgrading System:</source>
        <translation>Quando si Aggiorna il Sistema:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="106"/>
        <source>Upgrade Immediately</source>
        <translation>Aggiorna Subito</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="113"/>
        <source>Add Upgradeable Packages To Queue</source>
        <translation>Aggiungi i Pacchetti Aggiornabili alla Coda</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="120"/>
        <source>Ask</source>
        <translation>Chiedi</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="136"/>
        <source>When Processing Queue</source>
        <translation>Quando si Esegue la Coda</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="143"/>
        <source>Keep application running in System Tray only</source>
        <translation>Mantieni l&apos;applicazione solo nella Tray</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="153"/>
        <source>GUI Startup</source>
        <translation>Avvio della GUI</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="159"/>
        <source>Start in the System Tray</source>
        <translation>Avvia nella Tray</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="176"/>
        <source>When Application is in System Tray only</source>
        <translation>Quando l&apos;applicazione è solo nella Tray</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="182"/>
        <source>Update Database every</source>
        <translation>Aggiorna i database ogni</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="196"/>
        <source>minutes</source>
        <translation>minuti</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="203"/>
        <source>If upgrades are available:</source>
        <translation>Se sono disponibili aggiornamenti:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="210"/>
        <source>Just Notify</source>
        <translation>Notifica e basta</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="217"/>
        <source>Notify and add them to Queue</source>
        <translation>Notifica e aggiungili alla Coda</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="227"/>
        <source>Maintenance</source>
        <translation>Manutenzione</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="308"/>
        <source>Checkable Options</source>
        <translation>Opzioni Selezionabili</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="314"/>
        <source>Use Active FTP</source>
        <translation>Usa FTP Attivo</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="321"/>
        <source>Use Deltas (needs xdelta to be installed)</source>
        <translation>Usa Delta (xdelta deve essere installato)</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="331"/>
        <source>Advanced Options</source>
        <translation>Opzioni Avanzate</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="341"/>
        <source>HoldPkgs:</source>
        <translation>HoldPkgs:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="351"/>
        <source>IgnorePkgs:</source>
        <translation>IgnorePkgs:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="361"/>
        <source>IgnoreGroups:</source>
        <translation>IgnoreGroups:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="371"/>
        <source>NoUpgrade:</source>
        <translation>NoUpgrade:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="381"/>
        <source>NoExtract:</source>
        <translation>NoExtract:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="395"/>
        <source>XFerCommand: (example: /path/to/command %u) Blank for Default</source>
        <translation>XFerCommand: (esempio: /path/to/command %u) Vuoto per predefinito</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="433"/>
        <source>Arch Linux Official Repositories</source>
        <translation>Repositori Ufficiali di Arch Linux</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="441"/>
        <source>Here you can choose what repositories to use between Arch Linux&apos;s official ones.
Please note that packages from Unstable and Testing may break your system.</source>
        <translation>Qui puoi scegliere quali repositori utilizzare tra quelli ufficiali di Arch Linux.
Considera che i pacchetti da Unstable e Testing possono compromettere il tuo sistema.</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="610"/>
        <source>Server</source>
        <translation>Server</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="505"/>
        <source>Mirror:</source>
        <translation>Mirror:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="520"/>
        <source>Add Mirror</source>
        <translation>Aggiungi Mirror</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="533"/>
        <source>KDEMod Repositories</source>
        <translation>Repositori di KDEMod</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="541"/>
        <source>KDEMod is an improved version of KDE, an Arch Linux exclusive. Featuring an 
improved Qt build, compatible with Arch Linux standard Qt&apos;s, an improved theme,
and lots of addons, KDEMod is the best way to taste the ease and the power
of KDE with the simplicity and the power of Arch.</source>
        <translation>KDEMod è una versione migliorata di KDE, un&apos;esclusiva di Arch Linux. Con una
versione migliorata delle Qt, compatibile con quelle standard di Arch Linux, un tema
migliorato, e moltissime aggiunte, KDEMod è il modo migliore per combinare la facilità
e il potere di KDE con la semplicità e le performance di Arch Linux.</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="551"/>
        <source>KDEMod 3 Repository</source>
        <translation>Repository di KDEMod 3</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="558"/>
        <source>KDEMod 4 Repository (Unstable, testers only)</source>
        <translation>Repository di KDEMod 4 (Instabile, solo per tester)</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="581"/>
        <source>Third-Party Repositories</source>
        <translation>Repositori di Terze Parti</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="589"/>
        <source>You can extend your packages choice by adding other repositories. Third-Party 
Repositories act just as normal ones, and will be accessible through both Shaman
and Pacman.</source>
        <translation>Puoi estendere la scelta di pacchetti aggiungendo altri repositori. I repositori
di terze parti sono esattamente come quelli standard, e saranno accessibili sia tramite
Shaman che tramite Pacman.</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="605"/>
        <source>Repository</source>
        <translation>Repository</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="633"/>
        <source>Add New Repository</source>
        <translation>Aggiungi un Nuovo Repository</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="640"/>
        <source>Edit Repository</source>
        <translation>Modifica Repository</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="647"/>
        <source>Remove Repository</source>
        <translation>Rimuovi Repository</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="666"/>
        <source>Preferences</source>
        <translation>Preferenze</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="679"/>
        <source>Review Building output before installing</source>
        <translation>Rivedi l&apos;output del compilatore prima di installare</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="689"/>
        <source>ABS Configuration</source>
        <translation>Configurazione di ABS</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="695"/>
        <source>Use supfiles that match your current repositories</source>
        <translation>Usa i supfiles dei tuoi repositori attuali</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="704"/>
        <source>Define supfiles manually</source>
        <translation>Definisci i supfile manualmente</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="719"/>
        <source>Makepkg Configuration</source>
        <translation>Configurazione di Makepkg</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="725"/>
        <source>CFlags</source>
        <translation>CFlags</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="735"/>
        <source>CXXFlags</source>
        <translation>CXXFlags</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="745"/>
        <source>BuildEnv</source>
        <translation>BuildEnv</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="755"/>
        <source>Options</source>
        <translation>Opzioni</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="765"/>
        <source>Doc_Dirs</source>
        <translation>Doc_Dirs</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="778"/>
        <source>Build Environment</source>
        <translation>Ambiente di Compilazione</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="786"/>
        <source>Building Path</source>
        <translation>Percorso di Compilazione</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="798"/>
        <source>Remove installed makedepends after build</source>
        <translation>Rimuovi le dipendenze di compilazione installate dopo la compilazione</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="805"/>
        <source>Clean Build Environment after installation</source>
        <translation>Pulisci l&apos;Ambiente di Compilazione dopo l&apos;installazione</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="88"/>
        <source>General</source>
        <translation>Generale</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="408"/>
        <source>Clean Unused Databases</source>
        <translation>Pulisci i Database non utilizzati</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="420"/>
        <source>Clean Cache</source>
        <translation>Pulisci la Cache</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="432"/>
        <source>Empty Cache</source>
        <translation>Svuota la cache</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="444"/>
        <source>Optimize Pacman Database</source>
        <translation>Ottimizza il Database di Pacman</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="456"/>
        <source>Clean All Building Environments</source>
        <translation>Pulisci tutti gli Ambienti di Compilazione</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="138"/>
        <source>Repositories</source>
        <translation>Repositori</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="199"/>
        <source>Pacman</source>
        <translation>Pacman</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="267"/>
        <source>ABS</source>
        <translation>ABS</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="356"/>
        <source>Enter Here the Repository&apos;s Name</source>
        <translation>Digita il nome del Repository</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="358"/>
        <source>Enter Here the Repository&apos;s Server</source>
        <translation>Digita il Server del Repository</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="413"/>
        <source>Cleaning up unused Databases...</source>
        <translation>Pulizia dei Database Inutilizzati...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="425"/>
        <source>Cleaning up Cache...</source>
        <translation>Pulizia della Cache...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="437"/>
        <source>Deleting Cache...</source>
        <translation>Eliminazione della Cache...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="461"/>
        <source>Cleaning up building Environments...</source>
        <translation>Pulizia degli ambienti di Compilazione...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="476"/>
        <source>Cleaning up Unused Databases Failed!</source>
        <translation>Pulizia dei Database Inutilizzati Fallita!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="481"/>
        <source>Cleaning up Cache Failed!</source>
        <translation>Pulizia della Cache Fallita!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="486"/>
        <source>Deleting Cache Failed!</source>
        <translation>Non è stato possibile eliminare la Cache!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="491"/>
        <source>Could not clean Build Environments!!</source>
        <translation>Non è stato possibile pulire gli Ambienti di Compilazione!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="504"/>
        <source>Unused Databases Cleaned up successfully!</source>
        <translation>Database Inutilizzati puliti con successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="509"/>
        <source>Cache Cleaned Up Successfully!</source>
        <translation>Cache Pulita con Successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="514"/>
        <source>Cache Successfully Deleted!</source>
        <translation>Cache Cancellata con Successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="518"/>
        <source>Build Environments Successfully Cleaned!</source>
        <translation>Ambienti di compilazione puliti con Successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="519"/>
        <source>Build Environments Successfully Cleaned!!</source>
        <translation>Ambienti di compilazione puliti con Successo!!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="912"/>
        <source>Settings Changed</source>
        <translation>Impostazioni Cambiate</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="918"/>
        <source>Your repositories have changed.
Do you want to Update Your Database?</source>
        <translation>I Repositori sono stati modificati.
Vuoi aggiornare i Database?</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="949"/>
        <source>Mirror Format is incorrect. Your mirror should look like this:
http://mirror.org/$repo/os/i686</source>
        <comment>Obviously keep the example as it is ;)</comment>
        <translation>Il formato del Mirror non è corretto. Una sintassi corretta è del tipo:
http://mirror.org/$repo/os/i686</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="971"/>
        <source>Your Mirror was successfully added!
It is now available in mirrorlist.</source>
        <comment>mirrorlist here means /etc/pacman.d/mirrorlist, so it should not be translated.</comment>
        <translation>Il tuo mirror è stato aggiunto con successo!
E&apos; ora disponibile in mirrorlist.</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1000"/>
        <source>Pacman Database Optimized Successfully!</source>
        <translation>Database di Pacman Ottimizzato con Successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1005"/>
        <source>Could not Optimize Pacman Database!</source>
        <translation>Non è stato possibile ottimizzare il Database di Pacman!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1019"/>
        <source>Operation Completed Successfully!</source>
        <translation>Operazione Completata con Successo!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1018"/>
        <source>Sync was successfully executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>Sync è stato eseguito con successo!!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1023"/>
        <source>Sync could not be executed!</source>
        <comment>Sync is always the command</comment>
        <translation>Non è stato possibile eseguire sync!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1024"/>
        <source>Sync could not be executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>Non è stato possibile eseguire sync!!</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="240"/>
        <source>Process Selected</source>
        <translation>Esegui l&apos;azione Selezionata</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="452"/>
        <source>Optimizing Pacman Database...</source>
        <translation>Ottimizzazione del Database di Pacman...</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="264"/>
        <source>Waiting</source>
        <comment>Waiting for a user action</comment>
        <translation>In Attesa</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="449"/>
        <source>Core</source>
        <comment>Do not translate</comment>
        <translation>Core</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="456"/>
        <source>Extra</source>
        <comment>Do not translate</comment>
        <translation>Extra</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="463"/>
        <source>Community</source>
        <comment>Do not translate</comment>
        <translation>Community</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="470"/>
        <source>Testing</source>
        <comment>Do not translate</comment>
        <translation>Testing</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="477"/>
        <source>Unstable</source>
        <comment>Do not translate</comment>
        <translation>Unstable</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1011"/>
        <source>Running sync...</source>
        <comment>sync is a command, so it should not be translated</comment>
        <translation>Esecuzione di sync...</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="166"/>
        <source>Show Splashscreen</source>
        <translation>Mostra Schermata d&apos;avvio</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="282"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Shaman Manteinance.&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Please choose an action from the Drop-Down Menu.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Manutenzione di Shaman.&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Per favore scegli un&apos;azione dal menù a comparsa.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="672"/>
        <source>Process all dependencies and queue from binary first (recommended)</source>
        <translation>Esegui prima tutte le dipendenze e la coda da binario (raccomandato)</translation>
    </message>
</context>
<context>
    <name>EditPBuild</name>
    <message>
        <location filename="../src/EditPBuild.cpp" line="152"/>
        <source>Saving</source>
        <translation>Salvataggio</translation>
    </message>
    <message>
        <location filename="../src/EditPBuild.cpp" line="158"/>
        <source>You modified this PKGBUILD.
Do you want to save it?</source>
        <translation>Hai Modificato questo PKGBUILD.
Vuoi salvarlo?</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../ui/MainWindow.ui" line="13"/>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="49"/>
        <source>All packages</source>
        <translation>Tutti i pacchetti</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="54"/>
        <source>Installed packages</source>
        <translation>Pacchetti Installati</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="59"/>
        <source>Not installed packages</source>
        <translation>Pacchetti Non Installati</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="64"/>
        <source>Upgradeable packages</source>
        <translation>Pacchetti Aggiornabili</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="69"/>
        <source>Packages in Queue</source>
        <translation>Pacchetti in Coda</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="137"/>
        <source>Status</source>
        <translation>Stato</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="142"/>
        <source>Name</source>
        <translation>Nome</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="147"/>
        <source>Action</source>
        <translation>Azione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="152"/>
        <source>Version</source>
        <translation>Versione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="157"/>
        <source>Size</source>
        <translation>Dimensione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="162"/>
        <source>Repository</source>
        <translation>Repository</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="167"/>
        <source>Groups</source>
        <translation>Gruppi</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="172"/>
        <source>Description</source>
        <translation>Descrizione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="177"/>
        <source>Action-Text</source>
        <translation>Action-Text</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="221"/>
        <source>Repositories</source>
        <translation>Repositori</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="243"/>
        <source>Package Groups</source>
        <translation>Gruppi di Pacchetti</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="399"/>
        <source>Package Information</source>
        <translation>Informazioni sul Pacchetto</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="301"/>
        <source>Install selected package</source>
        <translation>Installa il pacchetto selezionato</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="304"/>
        <source>Mark for Installation</source>
        <translation>Segna per l&apos;Installazione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="320"/>
        <source>Remove selected package</source>
        <translation>Rimuovi il pacchetto selezionato</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="323"/>
        <source>Mark for Removal</source>
        <translation>Segna per la Rimozione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="339"/>
        <source>Complete Remove selected package (pacman -Rcs)</source>
        <translation>Rimuovi completamente il pacchetto  (pacman -Rcs)</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="342"/>
        <source>Mark for complete removal</source>
        <translation>Segna per la rimozione completa</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="358"/>
        <source>Cancel action for selected package</source>
        <translation>Annulla azione per il pacchetto selezionato</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="361"/>
        <source>Cancel action</source>
        <translation>Annulla Azione</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="434"/>
        <source>Files</source>
        <translation>Files</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="444"/>
        <source>1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="453"/>
        <source>Dependencies</source>
        <translation>Dipendenze</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="482"/>
        <source>File</source>
        <translation>File</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="488"/>
        <source>Help</source>
        <translation>Aiuto</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="494"/>
        <source>Actions</source>
        <translation>Azioni</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="498"/>
        <source>Build and Install from Source</source>
        <translation>Compila e Installa da Sorgente</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="523"/>
        <source>Quick Actions</source>
        <translation>Azioni Rapide</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="548"/>
        <source>Package Repositories</source>
        <translation>Repositori di Pacchetti</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="556"/>
        <source>Settings...</source>
        <translation>Impostazioni...</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="564"/>
        <source>About...</source>
        <translation>Informazioni...</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="572"/>
        <source>Update Database</source>
        <translation>Aggiorna Database</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="580"/>
        <source>Upgrade System</source>
        <translation>Aggiorna il Sistema</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="588"/>
        <source>Install Package From File</source>
        <translation>Installa Pacchetto da File</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="596"/>
        <source>Update ABS Tree</source>
        <translation>Aggiorna l&apos;albero ABS</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="601"/>
        <source>Build and Install Queue</source>
        <translation>Compila e Installa la Coda</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="175"/>
        <source>Quit</source>
        <translation>Esci</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="617"/>
        <source>Process Queue</source>
        <translation>Esegui la Coda</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="625"/>
        <source>Cancel all actions</source>
        <translation>Annulla tutte le Azioni</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="170"/>
        <source>Settings</source>
        <translation>Impostazioni</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1634"/>
        <source>Shaman - Idle</source>
        <translation>Shaman - In Attesa</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="234"/>
        <source>Shaman will keep running in the system tray.
To close it, click Quit in the file menu or in the tray icon context menu.
While in the System Tray, Shaman will update your Databases
at a regular interval and notify you about available upgrades.
You can change this behaviour in Settings.</source>
        <translation>Shaman verrà ridotto nel vassoio di sistema.
Per Chiuderlo, clicca su Esci nel menù File o nel menù dell&apos;Icona nel vassoio.
Mentre ridotto a Icona, Shaman aggiornerà i Database a intervalli regolari
e ti notificherà di eventuali aggiornamenti. 
Puoi cambiare questo comportamento nelle Impostazioni.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="242"/>
        <source>Shaman - Reducing To Tray</source>
        <translation>Shaman - Riduzione a Icona</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1862"/>
        <source>Upgrade</source>
        <translation>Aggiorna</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1617"/>
        <source>Shaman - Idle (Upgrades Available)</source>
        <translation>Shaman - In Attesa (Aggiornamenti Disponibili)</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1618"/>
        <source>System Upgrade</source>
        <translation>Aggiornamento del Sistema</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1619"/>
        <source>There is %1 upgradeable package.
Click here to upgrade your System.</source>
        <translation>C&apos;è %1 pacchetto aggiornabile.
Clicca qui per aggiornare il tuo Sistema.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1619"/>
        <source>There are %1 upgradeable packages.
Click here to upgrade your System.</source>
        <translation>Ci sono %1 pacchetti aggiornabili.
Clicca qui per aggiornare il tuo Sistema.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="473"/>
        <source>All Repositories</source>
        <translation>Tutti i Repositori</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="476"/>
        <source>Local Packages</source>
        <translation>Pacchetti Locali</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1031"/>
        <source>All Groups</source>
        <translation>Tutti i Gruppi</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="588"/>
        <source>Mark for Reinstallation</source>
        <translation>Segna per la Reinstallazione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1857"/>
        <source>Install</source>
        <translation>Installa</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1867"/>
        <source>Uninstall</source>
        <translation>Rimuovi</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1867"/>
        <source>Complete Uninstall</source>
        <translation>Rimuovi Completamente</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="659"/>
        <source>Status: </source>
        <translation>Stato: </translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="661"/>
        <source>Installed</source>
        <translation>Installato</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="663"/>
        <source>Not installed</source>
        <translation>Non Installato</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="677"/>
        <source>Action: </source>
        <translation>Azione: </translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1586"/>
        <source>Shaman - Processing</source>
        <translation>Shaman - Operazione in corso</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1686"/>
        <source>Error</source>
        <translation>Errore</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="774"/>
        <source>One or more Databases could not be updated.
Last error reported was:
%1</source>
        <translation>Non è stato possibile aggiornare uno o più Database.
L&apos;ultimo errore riportato è stato:
%1</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="780"/>
        <source>Database Update</source>
        <translation>Aggiornamento Database</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="780"/>
        <source>Databases Updated Successfully</source>
        <translation>Database aggiornati con Successo</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="882"/>
        <source>Mark for Upgrade</source>
        <translation>Segna per l&apos;Aggiornamento</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="884"/>
        <source>Cancel Action</source>
        <translation>Annulla Azione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="923"/>
        <source>Mark all for installation</source>
        <translation>Segna tutti per l&apos;Installazione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="925"/>
        <source>Mark all for reinstallation</source>
        <translation>Segna tutti per la Reinstallazione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="927"/>
        <source>Mark all for removal</source>
        <translation>Segna tutti per la Rimozione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1259"/>
        <source>Your system is up to date!</source>
        <translation>Il tuo sistema è aggiornato!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1370"/>
        <source>Queue Processing</source>
        <translation>Esecuzione Coda</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1370"/>
        <source>Your Queue is being processed.
Please wait.</source>
        <translation>La tua coda sta venendo eseguita.
Attendi.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1440"/>
        <source>Queue Processed</source>
        <translation>Coda Eseguita</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1433"/>
        <source>Your Queue was successfully processed!</source>
        <translation>La Coda è stata eseguita con successo!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1440"/>
        <source>Your Queue was successfully processed!!</source>
        <translation>La Coda è stata eseguita con successo!!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1506"/>
        <source>To be Installed</source>
        <translation>Da Installare</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1513"/>
        <source>To be Upgraded</source>
        <translation>Da Aggiornare</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1527"/>
        <source>To be Removed</source>
        <translation>Da Rimuovere</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1542"/>
        <source>Your Queue is about to be processed. You are going to:&lt;br /&gt;</source>
        <translation>La tua coda sta per essere eseguita. Stai per:&lt;br /&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1544"/>
        <source>Remove &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>Rimuovere &lt;b&gt;%1 pacchetto&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1544"/>
        <source>Remove &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>Rimuovere &lt;b&gt;%1 pacchetti&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1546"/>
        <source>Install/Upgrade &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>Installare/Aggiornare &lt;b&gt;%1 pacchetto&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1546"/>
        <source>Install/Upgrade &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>Installare/Aggiornare &lt;b&gt;%1 pacchetti&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1547"/>
        <source>Do you wish to continue?</source>
        <translation>Vuoi proseguire?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1677"/>
        <source>Install a Package</source>
        <translation>Installa un Pacchetto</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1677"/>
        <source>Arch Linux Packages (*.pkg.tar.gz)</source>
        <translation>Pacchetti di Arch Linux (*.pkg.tar.gz)</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1686"/>
        <source>%1 does not seem
a valid package</source>
        <translation>%1 non sembra
essere un pacchetto valido</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1717"/>
        <source>You need to have ABS installed to use Shaman&apos;s
building feature. Do you want to install it now?</source>
        <translation type="obsolete">Devi avere installato ABS per utilizzare le capacità
di compilazione di Shaman. Vuoi installarlo ora?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1746"/>
        <source>You can not remove packages when processing
your queue from Source</source>
        <translation type="obsolete">Non puoi rimuovere pacchetti se esegui la coda
da sorgente</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1775"/>
        <source>Some of your packages do not belong to Arch
Linux&apos;s official repository. Shaman is able to
build packages from official sources only.</source>
        <translation type="obsolete">Alcuni dei pacchetti selezionati non appartengono
ai repositori ufficiali di Arch Linux. Shaman è in grado
di compilare pacchetti solo da sorgenti ufficiali.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1809"/>
        <source>You are about to install &lt;b&gt;%1 package&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation type="obsolete">Stai per installare &lt;b&gt;%1 pacchetto&lt;/b&gt; da sorgente. Compilare da sorgente&lt;br&gt;può dare diversi vantaggi, ma è comunque molto lento.&lt;br&gt;Se non ne sei sicuro, probabilmente preferiresti eseguire la tua coda da file&lt;br&gt;binari. Prima di continuare, è consigliabile rivedere la tua configurazione&lt;br&gt;per massimizzare le prestazioni della compilazione.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1815"/>
        <source>You are about to install &lt;b&gt;%1 packages&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation type="obsolete">Stai per installare &lt;b&gt;%1 pacchetti&lt;/b&gt; da sorgente. Compilare da sorgente&lt;br&gt;può dare diversi vantaggi, ma è comunque molto lento.&lt;br&gt;Se non ne sei sicuro, probabilmente preferiresti eseguire la tua coda da file&lt;br&gt;binari. Prima di continuare, è consigliabile rivedere la tua configurazione&lt;br&gt;per massimizzare le prestazioni della compilazione.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1987"/>
        <source>Package Building</source>
        <translation type="obsolete">Compilazione Pacchetti</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1920"/>
        <source>Your Packages failed to build!</source>
        <translation type="obsolete">Non è stato possibile compilare i pacchetti!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1924"/>
        <source>Your packages Failed to Build.
Look at the output for more details.</source>
        <translation type="obsolete">Non è stato possibile compilare i pacchetti.
Guarda l&apos;output per maggiori dettagli.</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1962"/>
        <source>Close</source>
        <translation type="obsolete">Chiudi</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1952"/>
        <source>Building Packages Failed!!</source>
        <translation type="obsolete">Compilazione dei Pacchetti Fallita!!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1955"/>
        <source>Some packages failed to build.
Do you want to proceed anyway?</source>
        <translation type="obsolete">Alcuni pacchetti non sono stati compilati.
Vuoi proseguire comunque?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1982"/>
        <source>Install Built Packages</source>
        <translation type="obsolete">Installa i Pacchetti Compilati</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1983"/>
        <source>Close Without Installing</source>
        <translation type="obsolete">Chiudi Senza Installare</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1984"/>
        <source>Packages Built Successfully!</source>
        <translation type="obsolete">Pacchetti Compilati con Successo!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1988"/>
        <source>Your Packages have been built successfully, and are ready to be installed</source>
        <translation type="obsolete">I Pacchetti sono stati compilati con successo, e sono pronti per essere installati</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1738"/>
        <source>%1 GiB</source>
        <comment>Size is in Gib</comment>
        <translation>%1 GB</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1740"/>
        <source>%1 MiB</source>
        <comment>Size is in MiB</comment>
        <translation>%1 MB</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1742"/>
        <source>%1 KiB</source>
        <comment>Size is in KiB</comment>
        <translation>%1 KB</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1744"/>
        <source>%1 Bytes</source>
        <comment>Size is in Bytes</comment>
        <translation>%1 Bytes</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="609"/>
        <source>Quit</source>
        <comment>Quit the application</comment>
        <translation>Esci</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="235"/>
        <source>Do not show this Again</source>
        <translation>Non mostrare di nuovo</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="801"/>
        <source>Pacman Update</source>
        <translation>Aggiornamento di Pacman</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="808"/>
        <source>Pacman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Pacman now?</source>
        <translation>Pacman può essere aggiornato. È consigliabile aggiornarlo
da solo per evitare eventuali conflitti di versione.
Vuoi aggiornare Pacman ora?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="837"/>
        <source>Shaman Update</source>
        <translation>Aggiornamento di Shaman</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="844"/>
        <source>Shaman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Shaman now?</source>
        <translation>Shaman può essere aggiornato. È consigliabile aggiornarlo
da solo per evitare eventuali conflitti di versione.
Vuoi aggiornare Shaman ora?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1415"/>
        <source>Restart required</source>
        <translation>Riavvio Richiesto</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1417"/>
        <source>Pacman or Shaman was updated. Shaman will now quit,
please restart it to use the new version</source>
        <translation>Pacman o Shaman sono stati aggiornati. Shaman ora si 
chiuderà, riavvialo per usare la nuova versione</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1803"/>
        <source>Library Question</source>
        <translation>Domanda della Libreria</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1725"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm Version: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Un&apos;interfaccia a libalpm in Qt4&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Licenza: GPLv2+&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Versione di libalpm: v.%1&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="666"/>
        <source>Local Version: </source>
        <translation>Versione Locale: </translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="671"/>
        <source>Version in the Repository: </source>
        <translation>Versione nel Repository: </translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="117"/>
        <source>You have to be root to run Shaman.
Please restart it with root privileges.</source>
        <translation>Devi essere root per utilizzare Shaman.
Per favore riavvialo da root.</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="141"/>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="129"/>
        <source>There was a problem while testing libalpm.
Maybe another application has a lock on it.</source>
        <translation>C&apos;è stato un problema testando libalpm.
Forse un&apos;altra applicazione tiene un lock su di essa.</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="116"/>
        <source>Shaman</source>
        <comment>Hey! If you are reading this, first of all thanks for helping us in making Shaman better. There are not many comments unless where needed, since all the strings are pretty self-explanatory. You will see a lot of HTML in some cases: do not let that scare you, but please edit text only. Editing HTML tags too may break our layout, so be careful. A good practice could be copying the whole string, and then translating just what&apos;s outside the tags, usually just a few words. If you have any doubts, or if you just want to drop us a line, there goes our email addresses:
Dario: drf54321@gmail.com
Lukas: l.appelhans@gmx.de
Thanks again, and enjoy your translation!</comment>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="127"/>
        <source>Please Wait, loading packages...</source>
        <translation type="obsolete">Attendere prego, caricamento dei pacchetti...</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="160"/>
        <source>Please Wait...</source>
        <translation>Attendere Prego...</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="211"/>
        <source>Loading Databases...</source>
        <translation>Caricamento dei Database...</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="219"/>
        <source>Loading Packages...</source>
        <translation>Caricamento dei Pacchetti...</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="227"/>
        <source>Starting up Shaman...</source>
        <translation>Avvio di Shaman...</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="142"/>
        <source>Pacman is not updated.
Shaman needs libalpm &gt;= 2.1.0 to run.
Yours is %1. Please update Pacman.</source>
        <translation>Pacman non è aggiornato.
Shaman ha bisogno di libalpm &gt;= 2.1.0.
La versione corrente è %1.
Per favore aggiorna Pacman.</translation>
    </message>
</context>
<context>
    <name>QueueDialog</name>
    <message>
        <location filename="../src/QueueDialog.cpp" line="66"/>
        <source>&lt;br&gt;&lt;b&gt; * Validating Transaction&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Convalidazione della Transazione&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="107"/>
        <source>Validating Dependencies...</source>
        <translation>Controllo delle Dipendenze...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="111"/>
        <source>Checking for Conflicts...</source>
        <translation>Controllo i Conflitti...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="115"/>
        <source>Resolving Dependencies...</source>
        <translation>Risoluzione Dipendenze...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="119"/>
        <source>Looking for Inter-Conflicts...</source>
        <translation>Controllo di Inter-Conflitti...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="125"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Installation Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Installazione dei Pacchetti Iniziata&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="129"/>
        <source>Installing %1...</source>
        <translation>Installazione di %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="145"/>
        <source>%1 (%2) installed successfully!</source>
        <translation>%1 (%2) installato con successo!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="164"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Removal Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Rimozione dei Pacchetti Iniziata&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="168"/>
        <source>Removing %1...</source>
        <translation>Rimozione di %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="184"/>
        <source>%1 (%2) removed successfully!</source>
        <translation>%1 (%2) rimosso con successo!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="203"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Upgrading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Aggiornamento dei Pacchetti Iniziato&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="207"/>
        <source>Upgrading %1...</source>
        <translation>Aggiornamento di %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="225"/>
        <source>Upgraded %1 successfully (%2 -&gt; %3)</source>
        <translation>%1 aggiornato con successo (%2 -&gt; %3)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="247"/>
        <source>&lt;br&gt;&lt;b&gt; * Queue Processing Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Esecuzione della Coda Iniziata&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="251"/>
        <source>Checking package integrity...</source>
        <translation>Controllo l&apos;integrità dei pacchetti...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="255"/>
        <source>Checking delta integrity...</source>
        <translation>Controllo dell&apos;integrità dei delta...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="258"/>
        <source>Applying deltas...</source>
        <translation>Applicazione dei delta...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="261"/>
        <source>Generating %1 with %2... </source>
        <translation>Genero %1 con %2... </translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="265"/>
        <source>Success!</source>
        <translation>Eseguito!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="268"/>
        <source>Failed!</source>
        <translation>Fallito!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="282"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Downloading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * Download dei pacchetti Iniziato&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="286"/>
        <source>Starting downloading packages from %1...</source>
        <translation>Inizio a scaricare i pacchetti da %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="326"/>
        <source>%p% (%1 KB/s, %4:%5:%6 remaining)</source>
        <comment>You just have to translate &apos;remaining&apos; here. Leave everything else as it is.</comment>
        <translation>%p% (%1 KB/s, %4:%5:%6 rimanente)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="334"/>
        <source>Downloading %1... (%2 MB of %3 MB)</source>
        <translation>Scarico %1... (%2 MB di %3 MB)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="337"/>
        <source>Downloading %1... (%2 KB of %3 KB)</source>
        <translation>Scarico %1... (%2 KB di %3 KB)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="387"/>
        <source>Queue processed, please wait...</source>
        <translation>Coda eseguita, attendere prego...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="386"/>
        <source>Executing pre_install scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_install...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="390"/>
        <source>Executing pre_upgrade scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_upgrade...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="394"/>
        <source>Executing pre_remove scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_remove...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="398"/>
        <source>Executing post_install scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_install...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="402"/>
        <source>Executing post_upgrade scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_upgrade...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="406"/>
        <source>Executing post_remove scriptlet...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_remove...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="425"/>
        <source>Unexpected Error. Shaman might be corrupted.</source>
        <translation>Errore Inaspettato. Shaman potrebbe essere corrotto.</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="489"/>
        <source>Extracting Scriptlet from package failed!!</source>
        <translation>Impossibile estrarre la Scriptlet dal pacchetto!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="617"/>
        <source>Scriptlet processed successfully!</source>
        <translation>Scriptlet Eseguita con Successo!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="637"/>
        <source>Scriptlet not found in this stage, or error processing it!</source>
        <translation type="obsolete">Scriptlet non disponibile, o errore nell&apos;eseguirla!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="398"/>
        <source>Executing pre_install scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_install per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="403"/>
        <source>Executing pre_upgrade scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_upgrade per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="408"/>
        <source>Executing pre_remove scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet pre_remove per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="413"/>
        <source>Executing post_install scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_install per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="418"/>
        <source>Executing post_upgrade scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_upgrade per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="423"/>
        <source>Executing post_remove scriptlet for %1...</source>
        <translation type="obsolete">Esecuzione della scriptlet post_remove per %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="432"/>
        <source>Executing %1 scriptlet for %2...</source>
        <translation>Esecuzione della scriptlet %1 per %2...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="499"/>
        <source>Package %1 does not have %2 scriptlet</source>
        <translation>Il Pacchetto %1 non ha la scriptlet %2</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="623"/>
        <source>Error processing Scriptlet!!</source>
        <translation>Errore nell&apos;esecuzione della scriptlet!!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="714"/>
        <source>Queue Processing</source>
        <translation>Esecuzione Coda</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="700"/>
        <source>There has been an error while preparing the transaction.
</source>
        <translation>C&apos;è stato un errore durante la preparazione della transazione.
</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="715"/>
        <source>There has been an error while committing the transaction.
</source>
        <translation>C&apos;è stato un errore durante l&apos;esecuzione della transazione.
</translation>
    </message>
</context>
<context>
    <name>QueueReadyDialog</name>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="13"/>
        <source>Review Queue</source>
        <translation>Rivedi Coda</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="28"/>
        <source>Turn off PC when Queue is done</source>
        <translation>Spegni il PC quando la coda è stata Eseguita</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="35"/>
        <source>Process in Tray</source>
        <translation>Esegui nella Tray</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="44"/>
        <source>Show packages...</source>
        <translation>Mostra pacchetti...</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="70"/>
        <source>Packages In Queue</source>
        <translation>Pacchetti In Coda</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="80"/>
        <source>Cancel</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="103"/>
        <source>Process</source>
        <translation>Esegui</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="132"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Review Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rivedi Coda&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>SysUpgradeDialog</name>
    <message>
        <location filename="../src/SysUpgradeDialog.cpp" line="52"/>
        <source>There is &lt;b&gt;%1 upgradeable package&lt;/b&gt;. You can either&lt;br&gt; upgrade immediately or add it to the current Queue&lt;br&gt; and process it later.</source>
        <translation>C&apos;è &lt;b&gt;%1 pacchetto aggiornabile&lt;/b&gt;. Puoi aggiornare&lt;br&gt;immediatamente o aggiungerlo alla coda ed&lt;br&gt;aggiornarlo più tardi.</translation>
    </message>
    <message>
        <location filename="../src/SysUpgradeDialog.cpp" line="55"/>
        <source>There are &lt;b&gt;%1 upgradeable packages&lt;/b&gt;. You can either&lt;br&gt; upgrade immediately or add them to the current Queue&lt;br&gt; and process them later.</source>
        <translation>Ci sono &lt;b&gt;%1 pacchetti aggiornabili&lt;/b&gt;. Puoi aggiornare&lt;br&gt;immediatamente o aggiungerli alla coda ed&lt;br&gt;aggiornarli più tardi.</translation>
    </message>
    <message>
        <location filename="../src/SysUpgradeDialog.cpp" line="57"/>
        <source>To be Upgraded</source>
        <translation>Da Aggiornare</translation>
    </message>
</context>
<context>
    <name>aboutDialog</name>
    <message>
        <location filename="../ui/aboutDialog.ui" line="13"/>
        <source>About Shaman</source>
        <translation>Informazioni Su Shaman</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="82"/>
        <source>About</source>
        <translation>Informazioni</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="76"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="obsolete">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Un&apos;interfaccia a libalpm in Qt&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Licenza: GPLv2+&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="96"/>
        <source>Authors</source>
        <translation>Autori</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="102"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Dario Freddi&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Lukas Appelhans&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Developer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Dario Freddi&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Sviluppatore&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Lukas Appelhans&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Sviluppatore&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="118"/>
        <source>Thanks To</source>
        <translation>Ringraziamenti A</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="34"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-size:14pt; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (revision 336)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-size:14pt; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (revisione 336)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="121"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;German Translation and KDEMod-Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;mutlu_inek&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="obsolete">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman ha ricevuto aiuti da tantissime persone, ed è anche grazie a loro se ha visto la luce. Se per qualche motivo abbiamo dimenticato di inserirti qui, faccelo sapere.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduttore Tedesco e sviluppatore di KDEMod&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Sviluppatore di KDEMod, ha anche aiutato con il codice.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;mutlu_inek&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="121"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;German Translation and KDEMod-Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="obsolete">&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman ha ricevuto aiuti da tantissime persone, ed è anche grazie a loro se ha visto la luce. Se per qualche motivo abbiamo dimenticato di inserirti qui, faccelo sapere.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduttore Tedesco e sviluppatore di KDEMod&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Sviluppatore di KDEMod, ha anche aiutato con il codice.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="124"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;German Translation and KDEMod-Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>buildingDialog</name>
    <message>
        <location filename="../ui/buildingDialog.ui" line="400"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Building Packages...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Compilazione dei Pacchetti...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="464"/>
        <source>Abort</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="487"/>
        <source>Reduce To Tray</source>
        <translation>Riduci a Icona</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="13"/>
        <source>Shaman - Building Packages</source>
        <translation>Shaman - Compilazione Pacchetti</translation>
    </message>
</context>
<context>
    <name>dbUpdateDialog</name>
    <message>
        <location filename="../ui/dbUpdateDialog.ui" line="13"/>
        <source>Database Update</source>
        <translation>Aggiornamento Database</translation>
    </message>
    <message>
        <location filename="../ui/dbUpdateDialog.ui" line="398"/>
        <source>Update Database..</source>
        <translation>Aggiornamento dei Database..</translation>
    </message>
</context>
<context>
    <name>editPBDialog</name>
    <message>
        <location filename="../ui/editPBDialog.ui" line="13"/>
        <source>Editing PKGBUILD</source>
        <translation>Modifica PKGBUILD</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="23"/>
        <source>Editing PKGBUILD of:</source>
        <translation>Modifica PKGBUILD di:</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="37"/>
        <source>Save</source>
        <translation>Salva</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="60"/>
        <source>Undo</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="70"/>
        <source>Redo</source>
        <translation>Ripristina</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="107"/>
        <source>Ok</source>
        <translation>Ok</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="130"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Edit PKGBUILD&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Modifica PKGBUILD&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>reviewBuildingDialog</name>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="13"/>
        <source>Review Building Queue</source>
        <translation>Rivedi Compilazione della Coda</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="36"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Build Queue From Source&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Compilazione Coda da Sorgente&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="81"/>
        <source>Process All Dependencies from Binary First (advised)</source>
        <translation>Esegui prima tutte le Dipendenze da Binario (consigliato)</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="91"/>
        <source>This is useful if you want to review compiler&apos;s output</source>
        <translation>Utile se si vuole vedere l&apos;output del compilatore</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="104"/>
        <source>Turn off PC when Queue is done</source>
        <translation>Spegni PC quando la coda è stata completata</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="113"/>
        <source>Show packages...</source>
        <translation>Mostra Pacchetti...</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="139"/>
        <source>Packages In Queue</source>
        <translation>Pacchetti In Coda</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="149"/>
        <source>Abort</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="156"/>
        <source>Process From Binary</source>
        <translation>Esegui Da Binario</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="176"/>
        <source>Review PKGBUILDs</source>
        <translation>Modifica i PKGBUILD</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="183"/>
        <source>Process From Source</source>
        <translation>Esegui da Sorgente</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="94"/>
        <source>Do not install immediately when building is finished</source>
        <translation>Non installare subito quando la compilazione è terminata</translation>
    </message>
</context>
<context>
    <name>transactionDialog</name>
    <message>
        <location filename="../ui/transactionDialog.ui" line="13"/>
        <source>Processing Queue...</source>
        <translation>Esecuzione della Coda...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="21"/>
        <source>Check transaction validity</source>
        <translation>Controllo Validità della Transazione</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="28"/>
        <source>Download Packages</source>
        <translation>Scaricamento dei Pacchetti</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="35"/>
        <source>Process queue</source>
        <translation>Esecuzione della Coda</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="42"/>
        <source>Cleanup</source>
        <translation>Pulizia</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="134"/>
        <source>More Details...</source>
        <translation>Dettagli...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="160"/>
        <source>Abort</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="175"/>
        <source>Please Wait...</source>
        <translation>Attendere Prego...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="200"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Process Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Esecuzione della Coda&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>upgradeDialog</name>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="13"/>
        <source>System Upgrade</source>
        <translation>Aggiornamento del Sistema</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="54"/>
        <source>Remember my choice</source>
        <translation>Ricorda la mia scelta</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="65"/>
        <source>Abort</source>
        <translation>Annulla</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="98"/>
        <source>Add to Queue</source>
        <translation>Aggiungi alla Coda</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="108"/>
        <source>Upgrade Now</source>
        <translation>Aggiorna Ora</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="129"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;System-Upgrade&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;p, li { white-space: pre-wrap; }&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Aggiornamento del Sistema&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="168"/>
        <source>Packages to Upgrade</source>
        <translation>Pacchetti da Aggiornare</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="88"/>
        <source>Show packages...</source>
        <translation>Mostra pacchetti...</translation>
    </message>
</context>
</TS>
