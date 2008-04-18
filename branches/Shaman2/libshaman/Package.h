#ifndef SHAMANPACKAGE_H
#define SHAMANPACKAGE_H

//TODO: Probably identify by ID??
namespace Shaman {
class Package : public QObject //TODO: Probably not needed??
{
    Q_OBJECT
    public:
        enum PackageState {
            Installed,
            NotInstalled,
            Upgradeable
        }
        enum PackageAction {
            NoAction,
            Install,
            Remove,
            Upgrade
        }
        Package(const QString &name, const QString &description, const Version &version /*TODO*/, const PackageState &state, QObject *parent);//TODO: Need more params? anyway probably use another PackageData class, not struct, cause we need const values...
        ~Package();

        QString name() const;//TODO: Do we need a setName(), imo not ;)
        void setDescription(const QString &desc);
        QString description() const;
        void setVersion(const Version &version);
        Version version() const;
        void setPackageState(const PackageState &state);
        PackageState packageState() const;
        void setPackageAction(const PackageAction &action);
        PackageAction packageAction() const;
        virtual QList<Package*> dependecies();//TODO: = 0 ???
        virtual QList<Package*> conflicts();
        //TODO: Providers, not found dependencies...

    private:
        QString m_name;
        QString m_description;
        Version m_version;
        PackageState m_packageState;
        PackageAction m_packageAction;
};
};
#endif
