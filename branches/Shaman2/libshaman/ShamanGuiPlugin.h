//TODO: we probably need a parent???
class QWidget;
class QDockWidget;
class QAction;

class ShamanGuiPlugin : public ShamanAbstractPlugin
{
    public:  
        ShamanAbstractPlugin();

        void addToolBarAction(QAction *action);//TODO: Probably split out to a "GUI-Interface"?
        void addDockWidget(QDockWidget *widget);
        void addMainWidget(QWidget *widget);
  
        virtual ShamanPlugin::PluginType getPluginType() {return ShamanPlugin::GUI;}
};

Q_DECLARE_INTERFACE(ShamanGuiPlugin, "org.shaman.Modules.ShamanGui/1.0"); 
