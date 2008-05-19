namespace Shaman {
class AbstractPlugin : public KPlugin
{
    Q_OBJECT
    public:
        enum PluginType {//TODO: Probably to .desktop file as well?
            Backend,
            GUI,
            PackageView,
            Configurator
        };

        AbstractPlugin();

        virtual QWidget* configurationWidget() {return 0;}
  
        virtual PluginType getPluginType() const= 0;
};
}
