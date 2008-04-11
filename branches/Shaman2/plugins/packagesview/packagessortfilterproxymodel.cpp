
#include "packagessortfilterproxymodel.h"

PackagesSortFilterProxyModel::PackagesSortFilterProxyModel(QObject *parent)
  : QSortFilterProxyModel(parent),
    m_repo(QString()),
    m_group(QString()),
    m_state(All),
    m_searchText(QString()),
    m_search(Name)
{
}

PackagesSortFilterProxyModel::~PackagesSortFilterProxyModel()
{
}

void PackagesSortFilterProxyModel::setPackagesState(PackagesState state)
{
    m_state = state;
}

void PackagesSortFilterProxyModel::setRepositoryFilter(const QString repo = QString())
{
    m_repo = repo;
}

void PackagesSortFilterProxyModel::setGroupFilter(const QString group = QString())
{
    m_group = group;
}

void PackagesSortFilterProxyModel::setSearch(Search search)
{
    m_search = search;
}

void PackagesSortFilterProxyModel::setSearchText(const QString searchText = QString())
{
    m_searchText = searchText
}

bool PackagesSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    //Our "main"-method
    Package *package = static_cast<Package*>(sourceModel()->index(sourceRow, 1, sourceParent).internalPointer());//We have a package as internal pointer
    if (!package)
        return false;

    return (m_group.isEmpty() || package->groups().contains(m_group)) && //Look if it's in the group
           (m_repo.isEmpty() || package->repository() = m_repo) && //Look if it's in the repository
           searchMatch && //Now let's check the state
           ((m_state == All) ||
            (m_state == Installed && m_package->status() != Package::Installed) ||
            (m_state == NotInstalled && m_package->status() != Package::NotInstalled) ||
            (m_state == Upgradeable && m_package->status() != Package::Upgradeable) ||
            (m_state == InQueue && m_package->action() != Package::NoAction)) && //Let's go for searching
            (m_searchText.isEmpty() ||
             (m_seach == Name && package->name().contains(m_searchText))
             (m_search == Description && package->desciption().contains(m_searchText)));
}
