namespace ShamanPlugin {

	/**
	* \struct vrs
	* \brief Contains the version of the module
	* Uses 3 int values to create a version in format: "v major.minor.fix".
	*/
	struct vrs {
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
	*/
	struct data {
		/** The name of the plugin */
		QString name;
		/** The description of the plugin */
		QString description;
		/** The version of the plugin */
		struct vrs modVersion;
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

	/**
	* \typedef version
	* The type to use for using struct vrs
	*/
	typedef struct vrs version;
	
	/**
	* \typedef moduleData
	* The type to use for using struct data
	*/
	typedef struct data moduleData;

}  // namespace ShamanPlugin, move to abstract plugin and use Shaman namespace

class ShamanAbstractPlugin
{
  public:  
  
  ShamanAbstractPlugin();
  
    virtual ShamanPlugin::moduleData getPluginData() = 0;
    virtual QStringList getDependencies() = 0;
    virtual QWidget* configurationWidget() {return 0;}
  
    virtual ShamanPlugin::PluginType getPluginType() = 0;
}

Q_DECLARE_INTERFACE(ShamanAbstractPlugin, "org.shaman.Modules.ShamanAbstract/1.0");