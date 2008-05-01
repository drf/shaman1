//TODO: we probably need a parent???
class QWidget;
class QDockWidget;
class QAction;

namespace Shaman{
class GuiPlugin : public AbstractPlugin
{
    public:  
        GuiPlugin();

        void addToolBarAction(QAction *action);//TODO: Probably split out to a "GUI-Interface"?
        void addDockWidget(QDockWidget *widget);
        void addMainWidget(QWidget *widget);
  
        virtual AbstractPlugin::PluginType getPluginType() {return AbstractPlugin::GUI;}
};
}

Q_DECLARE_INTERFACE(Shaman::GuiPlugin, "org.shaman.Modules.ShamanGui/1.0"); 
