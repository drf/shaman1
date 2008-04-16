#ifndef PACKAGESSORTFILTERPROXYMODEL_H
#define PACKAGESSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel> 
#include <QString>

class PackagesSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    public:
        enum PackagesState
        {
            All          = 01,
            Installed    = 02,
            NotInstalled = 04,
            Upgradeable  = 08,
            InQueue      = 16
        };

        enum Search
        {
            Name         = 01,
            Description  = 02
        }

        PackagesSortFilterProxyModel(QObject *parent);
        ~PackagesSortFilterProxyModel();

        void setPackagesState(PackagesState state);
        PackagesState packagesState() {return m_state;}
        void setSearch(Search search);
        Search search() {return m_search}
        void setSearchText(const QString searchText = QString());
        QString searchText() const {return m_searchText;}
        void setRepositoryFilter(const QString repo = QString());
        QString repositoryFilter() const {return m_repo;}
        void setGroupFilter(const QString group = QString());
        QString groupFilter() const {return m_group;}

        bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

    private:
        QString m_repo;
        QString m_group;
        PackagesState m_state;
        QString m_searchText;
        Search m_search;
};

#endif
