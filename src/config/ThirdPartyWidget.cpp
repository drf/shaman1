#include "ThirdPartyWidget.h"

#include <aqpm/Configuration.h>

#include "ServerWidget.h"

#include "ui_thirdPartyWidget.h"

using namespace Aqpm;

ThirdPartyWidget::ThirdPartyWidget(QWidget *parent)
        : QWidget(parent)
        , m_ui(new Ui::ThirdPartyWidget)
{
    m_ui->setupUi(this);
}

void ThirdPartyWidget::reload()
{
    foreach (ServerWidget *w, m_serverWidgets) {
        w->deleteLater();
    }

    m_serverWidgets.clear();

    if (Configuration::instance()->mirrors().contains(m_ui->nameEdit->text())) {
        m_ui->listWidget->addItems(Configuration::instance()->databasesForMirror(m_ui->nameEdit->text()));
    }

    foreach (const QString &server, Configuration::instance()->serversForMirror(m_ui->nameEdit->text())) {
        ServerWidget *wg = new ServerWidget();
        wg->setServer(server);

        m_serverWidgets.append(wg);
        layout()->addWidget(wg);
    }
}

void ThirdPartyWidget::setMirrorName(const QString &name)
{
    m_ui->nameEdit->setText(name);
    reload();
}

QString ThirdPartyWidget::mirrorName() const
{
    return m_ui->nameEdit->text();
}
