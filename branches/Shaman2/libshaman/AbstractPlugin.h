namespace Shaman {
class AbstractPlugin
{
    public:
        /**
         * \struct vrs
         * \brief Contains the version of the module
         * Uses 3 int values to create a version in format: "v major.minor.fix".
         */
        struct Version {
            /** The major version number */
            int major;
            /** The minor version number */
            int minor;
            /** The fix version number */
            int fix;
        };

        /**
         * \struct data
         * Defines all the informations needed about a plugin.
         *///TODO: Const???? Can we do that in structs?
        struct ModuleData {
            /** The name of the plugin */
            QString name;
            /** The description of the plugin */
            QString description;
            /** The version of the plugin */
            struct Version ModuleVersion;
            /** The author of the plugin */
            QString author;
            /** The website of the plugin */
            QString website;
            /** The icon of the plugin. This will be used for displaying it in the list */
            QIcon icon;
        };

        enum PluginType {
            Backend,
            GUI,
            PackageView,
            Configurator
        };

        AbstractPlugin();
  
        virtual ModuleData getPluginData() = 0;
        virtual QStringList getDependencies() = 0;
        virtual QWidget* configurationWidget() {return 0;}
  
        virtual PluginType getPluginType() = 0;
};
}

Q_DECLARE_INTERFACE(Shaman::AbstractPlugin, "org.shaman.Modules.ShamanAbstract/1.0");//TODO: Move to KPlugin system
