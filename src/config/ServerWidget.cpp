#include "ServerWidget.h"

#include "ui_serverWidget.h"

ServerWidget::ServerWidget(QWidget *parent)
        : QWidget(parent)
        , m_ui(new Ui::ServerWidget)
{
    m_ui->setupUi(this);

    connect(m_ui->deferButton, SIGNAL(clicked()), this, SIGNAL(defer()));
    connect(m_ui->preferButton, SIGNAL(clicked()), this, SIGNAL(prefer()));
    connect(m_ui->removeButton, SIGNAL(clicked()), this, SIGNAL(remove()));
}

QString ServerWidget::server() const
{
    return m_ui->serverEdit->text();
}

void ServerWidget::setServer(const QString &server)
{
    m_ui->serverEdit->setText(server);
}
