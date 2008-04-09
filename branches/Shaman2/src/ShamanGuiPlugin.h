
class QWidget;
class QDockWidget;
class QAction;

class ShamanGuiPlugin : public ShamanAbstractPlugin
{
    public:  
        ShamanAbstractPlugin();

        void addToolBarAction(QAction *action);
        void addDockWidget(QDockWidget *widget);
        void addMainWidget(QWidget *widget);
  
        virtual ShamanPlugin::PluginType getPluginType() {return ShamanPlugin::GUI;}
};

Q_DECLARE_INTERFACE(ShamanGuiPlugin, "org.shaman.Modules.ShamanGui/1.0"); 
