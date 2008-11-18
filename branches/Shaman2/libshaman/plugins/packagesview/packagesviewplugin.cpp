
PackagesViewPlugin::PackagesViewPlugin()
{
    init();
}

PackagesViewPlugin::~PackagesViewPlugin()
{
}

void PackagesViewPlugin::init()
{
    m_model = new PackagesModel(this, bla->packagesList());
    QTreeView *view = new QTreeView(this);
    view->setModel(m_model);
}
